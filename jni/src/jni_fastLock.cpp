
#include "com_ki4wangdy_tinyThread_FastLock.h"

#include <tinythread.h>
#include <fast_mutex.h>

JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_FastLock_nativeId(JNIEnv *, jobject){
	tthread::fast_mutex* mutexPtr = new tthread::fast_mutex;
	return reinterpret_cast<jlong>(mutexPtr);
}

/*
 * Class:     com_ki4wangdy_tinyThread_FastLock
 * Method:    destoryNativeid
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_FastLock_destoryNativeid(JNIEnv *, jobject, jlong ptr){
	tthread::fast_mutex* mutexPtr = reinterpret_cast<tthread::fast_mutex*>(ptr);
	delete mutexPtr;
}

/*
 * Class:     com_ki4wangdy_tinyThread_FastLock
 * Method:    nativeLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_FastLock_nativeLock(JNIEnv *, jobject, jlong ptr){
	tthread::fast_mutex* mutexPtr = reinterpret_cast<tthread::fast_mutex*>(ptr);
	mutexPtr->lock();
}

/*
 * Class:     com_ki4wangdy_tinyThread_FastLock
 * Method:    nativeUnLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_FastLock_nativeUnLock(JNIEnv *, jobject, jlong ptr){
	tthread::fast_mutex* mutexPtr = reinterpret_cast<tthread::fast_mutex*>(ptr);
	mutexPtr->unlock();
}

/*
 * Class:     com_ki4wangdy_tinyThread_FastLock
 * Method:    nativeTryLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_FastLock_nativeTryLock(JNIEnv *, jobject, jlong ptr){
	tthread::fast_mutex* mutexPtr = reinterpret_cast<tthread::fast_mutex*>(ptr);
	mutexPtr->try_lock();
}
