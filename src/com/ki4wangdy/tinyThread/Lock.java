package com.ki4wangdy.tinyThread;

public class Lock implements Lockable {

	private long mNativeId;
	
	/**
	 * The class will block the calling thread until a lock can
     * be obtained. The Lock remains locked until unlock() is called.
	 */
	public Lock(){
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
