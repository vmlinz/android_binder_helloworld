#include "HelloService.h"

namespace android {
	HelloService::HelloService()
	{};

	HelloService::~HelloService()
	{};

	void HelloService::helloThere(const char *str)
	{
		return;
	}

	status_t HelloService::onTransact(uint32_t code, 
				      const Parcel& data,
				      Parcel* reply, 
				      uint32_t flags)
	{
		return BnHelloService::onTransact(code, data, reply, flags);
	}
}
