package com.ki4wangdy.tinyThread;

public class RecursiveLock implements Lockable {

	/**
	 * 
	/// Recursive mutex class.
	/// This is a mutual exclusion object for synchronizing access to shared
	/// memory areas for several threads. The mutex is recursive (i.e. a thread
	/// may lock the mutex several times, as long as it unlocks the mutex the same
	/// number of times).
	 */
	
	private long mNativeId;
	
	public RecursiveLock(){
		mNativeId = nativeId();
	}
	
	@Override
	public void lock() {
		Assert(mNativeId != 0);
		nativeLock(mNativeId);
	}

	@Override
	public void unLock() {
		Assert(mNativeId != 0);
		nativeUnLock(mNativeId);
	}

	@Override
	public void tryLock() {
		Assert(mNativeId != 0);
		nativeTryLock(mNativeId);
	}

	@Override
	protected void finalize() throws Throwable {
		if(mNativeId != 0){
			nativeDestory(mNativeId);
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
	private native void nativeDestory(long nativeId);

	private native void nativeLock(long nativeId);
	private native void nativeUnLock(long nativeId);
	private native void nativeTryLock(long nativeId);

}
