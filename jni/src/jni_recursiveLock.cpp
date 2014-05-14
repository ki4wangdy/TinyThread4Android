
#include "com_ki4wangdy_tinyThread_RecursiveLock.h"

#include <tinythread.h>

JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeId(JNIEnv *, jobject){
	tthread::recursive_mutex* mutexPtr = new tthread::recursive_mutex;
	return reinterpret_cast<jlong>(mutexPtr);
}

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeDestory
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeDestory(JNIEnv *, jobject, jlong ptr){
	tthread::recursive_mutex* mutexPtr =  reinterpret_cast<tthread::recursive_mutex*>(ptr);
	delete mutexPtr;
}

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeLock(JNIEnv *, jobject, jlong ptr){
	tthread::recursive_mutex* mutexPtr = reinterpret_cast<tthread::recursive_mutex*>(ptr);
	mutexPtr->lock();
}

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeUnLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeUnLock(JNIEnv *, jobject, jlong ptr){
	tthread::recursive_mutex* mutexPtr = reinterpret_cast<tthread::recursive_mutex*>(ptr);
	mutexPtr->unlock();
}

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeTryLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeTryLock(JNIEnv *, jobject, jlong ptr){
	tthread::recursive_mutex* mutexPtr = reinterpret_cast<tthread::recursive_mutex*>(ptr);
	mutexPtr->try_lock();
}

