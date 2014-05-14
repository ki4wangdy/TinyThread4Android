

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := tinyThread4Android

LOCAL_SRC_FILES :=	\
	./src/jni_condition.cpp	\
	./src/jni_lock.cpp	\
	./src/jni_thread.cpp	\
	./src/jni_fastLock.cpp	\
	./src/jni_recursiveLock.cpp	\
	./src/tinythread.cpp

LOCAL_CFLAGS := -I$(LOCAL_PATH)/include
LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)




