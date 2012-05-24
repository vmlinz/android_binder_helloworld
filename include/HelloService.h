#ifndef _HELLOSERVICE_H_
#define _HELLOSERVICE_H_

#include <stdint.h>
#include <sys/types.h>

#include <utils/Errors.h>

#include <binder/BinderService.h>

#include "IHelloService.h"

namespace android {

class HelloService :
    public BinderService<HelloService>,
    public BnHelloService
{
public:
static char const* getServiceName() {return "android.hello.IHelloService";}

HelloService();
virtual ~HelloService();

virtual status_t onTransact(uint32_t code, 
			    const Parcel& data, 
			    Parcel* reply, 
			    uint32_t flags);
virtual void helloThere(const char *str);
};

};
#endif /* _HELLOSERVICE_H_ */
