#ifndef __ORNG_NONBLOCKSOCKET_H__
#define __ORNG_NONBLOCKSOCKET_H__
#include "BaseSocket.h"

namespace orng
{

namespace net
{
class NonBlockSocket : public BaseSocket
{
public:
	NonBlockSocket(void);
	NonBlockSocket(uint fd) :BaseSocket(fd){}
	~NonBlockSocket(void);
	virtual bool open();
	virtual bool open(InetAddress &hostAddr);
	virtual void close();
};

}
}



#endif
