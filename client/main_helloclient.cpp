//#define LOG_NDEBUG 0
#define LOG_TAG "HelloService"

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "IHelloService.h"

using namespace android;

int main(int argc, char *argv[])
{
    LOGI("Hello client is now starting");

    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder;
    sp<IHelloService> shw;

    do {
	binder = sm->getService(String16("android.hello.IHelloService"));
	if (binder != 0)
	    break;
	LOGW("HelloService not published, waiting...");
	usleep(500000); // 0.5 s
    } while(true);

    LOGI("Hello client is now trying");

    shw = interface_cast<IHelloService>(binder);
    shw->helloThere("Hello From Client");

    LOGI("Hello client is now exiting");

    return(0);
}
