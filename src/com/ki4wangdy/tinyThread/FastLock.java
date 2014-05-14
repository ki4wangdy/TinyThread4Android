package com.ki4wangdy.tinyThread;

public class FastLock implements Lockable {

	/**
	/// Fast mutex class.
	/// This is a mutual exclusion object for synchronizing access to shared
	/// memory areas for several threads. It is similar to the tthread::mutex class,
	/// but instead of using system level functions, it is implemented as an atomic
	/// spin lock with very low CPU overhead.
	///
	/// The \c fast_mutex class is NOT compatible with the \c condition_variable
	/// class (however, it IS compatible with the \c lock_guard class). It should
	/// also be noted that the \c fast_mutex class typically does not provide
	/// as accurate thread scheduling as a the standard \c mutex class does.
	///
	/// Because of the limitations of the class, it should only be used in
	/// situations where the mutex needs to be locked/unlocked very frequently.
	///
	/// @note The "fast" version of this class relies on inline assembler language,
	/// which is currently only supported for 32/64-bit Intel x86/AMD64 and
	/// PowerPC architectures on a limited number of compilers (GNU g++ and MS
	/// Visual C++).
	/// For other architectures/compilers, system functions are used instead.
	 *
	 */
	
	private long mNativeId;
	
	public FastLock(){
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
			destoryNativeid(mNativeId);
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
	private native void destoryNativeid(long nativeId);

	private native void nativeLock(long nativeId);
	private native void nativeUnLock(long nativeId);
	private native void nativeTryLock(long nativeId);
	
}
