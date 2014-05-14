package com.ki4wangdy;

import java.util.ArrayList;
import java.util.List;

import android.util.Log;

import com.ki4wangdy.tinyThread.Condition;
import com.ki4wangdy.tinyThread.FastLock;
import com.ki4wangdy.tinyThread.Lock;
import com.ki4wangdy.tinyThread.RecursiveLock;

public class UnitTest {
	
	static class Container {
		
		private List<String> buffer = new ArrayList<String>();
		
		private RecursiveLock mLock = new RecursiveLock();
		
		private Condition mEmpty = new Condition();
		private Condition mFull = new Condition();
		
		public void push(String str){
			mLock.tryLock();
			try{
				int size = buffer.size();
				while(size >= 2){
					mFull.await(mLock);
					size = buffer.size();
				}
				Log.d(MainActivity.TAG, "before push, size is " + size);
				buffer.add(str);
				Log.d(MainActivity.TAG, "push : " + str);
				mEmpty.singalAll();
			}finally{
				mLock.unLock();
			}
		}
		
		public String remove(){
			mLock.tryLock();
			try{
				int size = buffer.size();
				while(size == 0){
					mEmpty.await(mLock);
					size = buffer.size();
				}
				Log.d(MainActivity.TAG, "before remove, size is " + size);
				String result = buffer.remove(0);
				Log.d("ki4wangdy", "remove :" + result);
				mFull.notifyAll();
				return result;
			}finally{
				mLock.unLock();
			}
		}
		
	} 
	
	static class Producer extends com.ki4wangdy.tinyThread.Thread{
		
		private final long mSleepTime;
		final Container mContainer;
		
		private boolean mIsStop;
		
		public Producer(Container container, long time){
			mContainer = container;
			mSleepTime = time;
			mIsStop = false;
		}

		public void stop(){
			mIsStop = true;
		}
		
		@Override
		public void run() {
			while(!mIsStop){
				try{
					mContainer.push(System.currentTimeMillis() + "");
					Thread.sleep(mSleepTime);
				}catch(Exception e){
				}
			}
		}
	}
	
	static class Consumer extends com.ki4wangdy.tinyThread.Thread{
		
		private final long mSleepTime;
		final Container mContainer;
		
		private boolean mIsStop;
		
		public Consumer(Container container, long time){
			mContainer = container;
			mSleepTime = time;
			mIsStop = false;
		}
		
		public void stop(){
			mIsStop = true;
		}
		
		@Override
		public void run() {
			while(!mIsStop){
				try{
					mContainer.remove();
					Thread.sleep(mSleepTime);
				}catch(Exception e){
				}
			}
		}
		
	}
	
	static class SingleThread extends com.ki4wangdy.tinyThread.Thread{
		@Override
		protected void run() {
			com.ki4wangdy.tinyThread.Thread.yield();
			Log.i(MainActivity.TAG, super.threadId() + " singleThread run");
		}
	}
	
	
	public static void launchSingelThread(){
		SingleThread thread = new SingleThread();
		thread.join();
		Log.i(MainActivity.TAG, "main thread is over");
	}
	
	static class UnitFastLock{
		private static FastLock lock = new FastLock();
		public static void test(){
			lock.lock();
			lock2();
			lock.unLock();
		}
		
		private static void lock2(){
			lock.lock();
			Log.i(MainActivity.TAG, "lock 2");
			lock.unLock();
		}
	}

	static class UnitTestRecursiveLock{
		private static RecursiveLock lock = new RecursiveLock();
		public static void test(){
			lock.lock();
			lock2();
			lock.unLock();
		}
		
		private static void lock2(){
			lock.lock();
			Log.i(MainActivity.TAG, "lock 2");
			lock.unLock();
		}
	}

	
	
	public static void launchFastLock(){
		UnitFastLock.test();
	}
	
	public static void launchRecursiveLock(){
		Log.i(MainActivity.TAG, System.currentTimeMillis() + "");
		com.ki4wangdy.tinyThread.Thread.sleep(1000);
		Log.i(MainActivity.TAG, System.currentTimeMillis() + "");
		UnitTestRecursiveLock.test();
	}
	
	static class UnitTestLock{
		private static Lock lock = new Lock();
		public static void test(){
			lock.lock();
			lock2();
			lock.unLock();
		}
		
		private static void lock2(){
			lock.lock();
			Log.i(MainActivity.TAG, "lock 2");
			lock.unLock();
		}

	}
	
	public static void launchLock(){
		UnitFastLock.test();
	}
	
	public static void launchProducerAndConsumer(){
		Container buffe = new Container();
		List<Producer> mProducers = new ArrayList<Producer>();
		for(int i=0; i<5; i++){
			mProducers.add(new Producer(buffe, i*10));
		}
		
		List<Consumer> mConsumers = new ArrayList<Consumer>();
		for(int i=0; i<5; i++){
			mConsumers.add(new Consumer(buffe, i*10));
		}
		
		try{
			Thread.sleep(60*1000);
		}catch(Exception e){
		}
		
		int size = mProducers.size();
		for(int i=0; i<size; i++){
			mProducers.get(i).stop();
		}
		
		size = mConsumers.size();
		for(int i=0; i<size; i++){
			mConsumers.get(i).stop();
		}
		
	}
}
