/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ki4wangdy_tinyThread_RecursiveLock */

#ifndef _Included_com_ki4wangdy_tinyThread_RecursiveLock
#define _Included_com_ki4wangdy_tinyThread_RecursiveLock
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeId
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeId
  (JNIEnv *, jobject);

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeDestory
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeDestory
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeLock
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeUnLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeUnLock
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ki4wangdy_tinyThread_RecursiveLock
 * Method:    nativeTryLock
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_RecursiveLock_nativeTryLock
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
