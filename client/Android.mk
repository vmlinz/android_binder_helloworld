LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES += $(JNI_H_INCLUDE) $(LOCAL_PATH)/../include

LOCAL_SRC_FILES := main_helloclient.cpp

LOCAL_SHARED_LIBRARIES := libHelloService \
libutils \
libbinder

LOCAL_MODULE := helloclient

include $(BUILD_EXECUTABLE)
