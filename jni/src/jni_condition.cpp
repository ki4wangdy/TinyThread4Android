
#include "com_ki4wangdy_tinyThread_Condition.h"

#include <tinythread.h>
#include <fast_mutex.h>

JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeId(JNIEnv *, jobject){
	tthread::condition_variable* condPtr = new tthread::condition_variable;
	return reinterpret_cast<jlong>(condPtr);
}

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    destoryNativeId
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_destoryNativeId(JNIEnv *, jobject, jlong ptr){
	tthread::condition_variable* condPtr = reinterpret_cast<tthread::condition_variable*>(ptr);
	delete condPtr;
}

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    nativeAwait
 * Signature: (Lcom/ki4wangdy/tinyThread/Lockable;)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeAwait(JNIEnv* env, jobject, jobject lockObj, jlong ptr){

	tthread::condition_variable* condPtr = reinterpret_cast<tthread::condition_variable*>(ptr);

	//com/ki4wangdy/tinyThread/Lock
	jclass cls = env->FindClass("com/ki4wangdy/tinyThread/Lock");
	if(!cls){
		if(env->IsInstanceOf(lockObj,cls)){
			tthread::mutex* mutexPtr = reinterpret_cast<tthread::mutex*>(ptr);
			condPtr->wait<tthread::mutex>(*mutexPtr);
		}
		return ;
	}

	//com/ki4wangdy/tinyThread/FastLock
	cls = env->FindClass("com/ki4wangdy/tinyThread/FastLock");
	if(!cls){
		if(env->IsInstanceOf(lockObj,cls)){
			tthread::fast_mutex* mutexPtr = reinterpret_cast<tthread::fast_mutex*>(ptr);
			condPtr->wait<tthread::fast_mutex>(*mutexPtr);
		}
		return ;
	}

	//com/ki4wangdy/tinyThread/RecursiveLock
	cls = env->FindClass("com/ki4wangdy/tinyThread/RecursiveLock");
	if(!cls){
		if(env->IsInstanceOf(lockObj,cls)){
			tthread::recursive_mutex* mutexPtr = reinterpret_cast<tthread::recursive_mutex*>(ptr);
			condPtr->wait<tthread::recursive_mutex>(*mutexPtr);
		}
		return ;
	}

}

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    nativeSignal
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeSignal(JNIEnv *, jobject, jlong ptr){
	tthread::condition_variable* condPtr = reinterpret_cast<tthread::condition_variable*>(ptr);
	condPtr->notify_one();
}

/*
 * Class:     com_ki4wangdy_tinyThread_Condition
 * Method:    nativeSignalAll
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Condition_nativeSignalAll(JNIEnv *, jobject, jlong ptr){
	tthread::condition_variable* condPtr = reinterpret_cast<tthread::condition_variable*>(ptr);
	condPtr->notify_all();
}


