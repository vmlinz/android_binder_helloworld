#ifndef ANDROID_HELLOSERVICE_H
#define ANDROID_HELLOSERVICE_H

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android
{
    class IHelloService: public IInterface
    {
    public:
	DECLARE_META_INTERFACE(HelloService);

	virtual void helloThere(const char *str) = 0;
    };

    class BnHelloService: public BnInterface<IHelloService>
    {
    public:
	virtual status_t onTransact(uint32_t code,
				    const Parcel& data,
				    Parcel* reply,
				    uint32_t flags = 0);
    };

};
#endif
