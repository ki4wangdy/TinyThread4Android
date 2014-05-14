package com.ki4wangdy.tinyThread;

public class Condition {
	
	private long mNativeId;
	
	public Condition(){
		mNativeId = nativeId();
	}
	
	public void await(Lockable lock){
		Assert(mNativeId != 0);
		nativeAwait(lock,mNativeId);
	}
	
	public void singal(){
		Assert(mNativeId != 0);
		nativeSignal(mNativeId);
	}
	
	public void singalAll(){
		Assert(mNativeId != 0);
		nativeSignalAll(mNativeId);
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
	
	private native void nativeAwait(Lockable lock,long nativeId);
	private native void nativeSignal(long nativeId);
	private native void nativeSignalAll(long nativeId);
}
