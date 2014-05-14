
#include "com_ki4wangdy_tinyThread_Lock.h"

#include <tinythread.h>

JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_Lock_nativeId(JNIEnv *, jobject){
	tthread::mutex* mutexPtr = new tthread::mutex;
	return reinterpret_cast<jlong>(mutexPtr);
}

/*
 * Class:     com_ki4wangdy_tinyThread_Lock
 * Method:    nativeDestory
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Lock_nativeDestory(JNIEnv *, jobject, jlong ptr){
	tthread::mutex* mutexPtr = reinterpret_cast<tthread::mutex*>(ptr);
	delete mutexPtr;
}

/*
 * Class:     com_ki4wangdy_tinyThread_Lock
 * Method:    nativeLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Lock_nativeLock(JNIEnv *, jobject, jlong ptr){
	tthread::mutex* mutexPtr = reinterpret_cast<tthread::mutex*>(ptr);
	mutexPtr->lock();
}

/*
 * Class:     com_ki4wangdy_tinyThread_Lock
 * Method:    nativeUnLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Lock_nativeUnLock(JNIEnv *, jobject, jlong ptr){
	tthread::mutex* mutexPtr = reinterpret_cast<tthread::mutex*>(ptr);
	mutexPtr->unlock();
}

/*
 * Class:     com_ki4wangdy_tinyThread_Lock
 * Method:    nativeTryLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Lock_nativeTryLock(JNIEnv *, jobject, jlong ptr){
	tthread::mutex* mutexPtr = reinterpret_cast<tthread::mutex*>(ptr);
	mutexPtr->try_lock();
}

