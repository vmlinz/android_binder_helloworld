LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := $(JNI_H_INCLUDE) $(LOCAL_PATH)/../include

LOCAL_SRC_FILES := IHelloService.cpp HelloService.cpp

LOCAL_SHARED_LIBRARIES := libutils \
libbinder

LOCAL_MODULE := libHelloService

include $(BUILD_SHARED_LIBRARY)
