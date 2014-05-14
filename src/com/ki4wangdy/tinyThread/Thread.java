package com.ki4wangdy.tinyThread;

public class Thread {

	private long mNativeId;
	
	public Thread(){
		mNativeId = nativeId();
	}

	protected void run(){
	}
	
	public void join(){
		Assert(mNativeId != 0);
		nativeJoin(mNativeId);
	}
	
	public long threadId(){
		Assert(mNativeId != 0);
		return nativeThreadId(mNativeId);
	}
	
	public static void sleep(long time){
		nativeSleep(time);
	}
	
	public static void yield(){
		nativeYield();
	}
	
	@Override
	protected void finalize() throws Throwable {
		if(mNativeId != 0){
			destoryNativeId(mNativeId);
			mNativeId = 0;
		}
		super.finalize();
	}
	
	private void Assert(boolean isTrue){
		if(!isTrue){
			throw new IllegalAccessError();
		}
	}
	
	private native long nativeId();
	private native void destoryNativeId(long nativeId);

	private static native void nativeSleep(long time);
	private static native void nativeYield();
	
	private native long nativeThreadId(long nativeId);
	private native void nativeJoin(long nativeId);
}
