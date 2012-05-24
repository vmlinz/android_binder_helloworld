#include <binder/BinderService.h>

#include "HelloService.h"

using namespace android;

int main(int argc, char **argv){
	HelloService::publishAndJoinThreadPool();
	return 0;
}
