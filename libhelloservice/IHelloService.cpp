#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <utils/Errors.h>

#include "IHelloService.h"

namespace android{
    enum {
	    HELLO_PING = IBinder::FIRST_CALL_TRANSACTION,
	    HELLO_THERE
    };

    class BpHelloService: public BpInterface<IHelloService>
    {
    public:
	BpHelloService(const sp<IBinder>& impl)
	    : BpInterface<IHelloService>(impl)
	    {
	    }
	virtual void helloThere(const char *str)
	    {
		Parcel data, reply;
		data.writeInterfaceToken(IHelloService::getInterfaceDescriptor());
		data.writeCString(str);

		remote()->transact(HELLO_THERE, data, &reply, 0);
	    }
    };
	
IMPLEMENT_META_INTERFACE(HelloService, "android.hello.IHelloService");
// ----------------------------------------

    status_t BnHelloService::onTransact(
	uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
    {
	switch(code) {
	case HELLO_THERE: {

	    CHECK_INTERFACE(IHelloService, data, reply);
	    const char *str = data.readCString();

	    printf("HelloService: %s with the help of me :)\n", str);

	    reply->writeCString(str);
	    return NO_ERROR;
	} break;
	default: {
	    return BBinder::onTransact(code, data, reply, flags);
	}
	}
    }
}
