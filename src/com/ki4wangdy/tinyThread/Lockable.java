package com.ki4wangdy.tinyThread;

public interface Lockable {
	public void lock();
	public void unLock();
	public void tryLock();
}
