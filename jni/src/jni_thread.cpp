


#include "com_ki4wangdy_tinyThread_Thread.h"

#include <tinythread.h>

JavaVM* g_jvm = NULL;
jobject g_threadObj = NULL;

static void runImp(void* arg){
	if(!g_jvm){
		return ;
	}

	JNIEnv* env = NULL;
	if(g_jvm->AttachCurrentThread(&env,NULL) != JNI_OK){
		return ;
	}

	jclass cls = env->GetObjectClass(g_threadObj);
	jmethodID methodId = env->GetMethodID(cls,"run","()V");
	env->CallVoidMethod(g_threadObj,methodId);
	
	env->DeleteGlobalRef(g_threadObj);
	g_jvm->DetachCurrentThread();
}

JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_Thread_nativeId(JNIEnv* env, jobject threadObj){

	env->GetJavaVM(&g_jvm);
	g_threadObj = env->NewGlobalRef(threadObj);

	tthread::thread* threadPtr = new tthread::thread(runImp,NULL);
	return reinterpret_cast<jlong>(threadPtr);
}

/*
 * Class:     com_ki4wangdy_tinyThread_Thread
 * Method:    destoryNativeId
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Thread_destoryNativeId(JNIEnv *, jobject, jlong ptr){
	tthread::thread* threadPtr = reinterpret_cast<tthread::thread*>(ptr);
	delete threadPtr;
}

/*
 * Class:     com_ki4wangdy_tinyThread_Thread
 * Method:    nativeSleep
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Thread_nativeSleep(JNIEnv *, jclass, jlong time){
	tthread::this_thread::sleep_for(tthread::chrono::milliseconds(time));
}

/*
 * Class:     com_ki4wangdy_tinyThread_Thread
 * Method:    nativeYield
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Thread_nativeYield(JNIEnv *, jclass){
	tthread::this_thread::yield();
}

/*
 * Class:     com_ki4wangdy_tinyThread_Thread
 * Method:    nativeThreadId
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_ki4wangdy_tinyThread_Thread_nativeThreadId(JNIEnv *, jobject, jlong ptr){
	tthread::thread* threadPtr = reinterpret_cast<tthread::thread*>(ptr);
	return static_cast<jlong>(threadPtr->get_id().getId());
}

/*
 * Class:     com_ki4wangdy_tinyThread_Thread
 * Method:    nativeJoin
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ki4wangdy_tinyThread_Thread_nativeJoin(JNIEnv *, jobject, jlong ptr){
	tthread::thread* threadPtr = reinterpret_cast<tthread::thread*>(ptr);
	threadPtr->join();
}


