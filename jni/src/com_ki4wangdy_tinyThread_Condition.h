/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ki4wangdy_tinyThread_Condition */

#ifndef _Included_com_ki4wangdy_tinyThread_Condition
#define _Included_com_ki4wangdy_tinyThread_Condition
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    nativeId
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeId
  (JNIEnv *, jobject);

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    destoryNativeId
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_destoryNativeId
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    nativeAwait
 * Signature: (Lcom/ki4wangdy/tinyThread/Lockable;J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeAwait
  (JNIEnv *, jobject, jobject, jlong);

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    nativeSignal
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeSignal
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    nativeSignalAll
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeSignalAll
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
