#ifndef __ORNG_SOCKETHELPER_H__
#define __ORNG_SOCKETHELPER_H__

#include <winsock2.h>
#include <MSWSock.h>

namespace orng
{
namespace net
{
class SocketHelper
{
public:
	typedef LPFN_ACCEPTEX AcceptExPtr;
	typedef LPFN_GETACCEPTEXSOCKADDRS GetAcceptExSockAddrsPtr;

	static AcceptExPtr getAccptExPtr(unsigned int sock);
	static GetAcceptExSockAddrsPtr getAcceptExSockAddrsPtr(unsigned int sock);
	SocketHelper(void);
	~SocketHelper(void);
};


}
}



#endif
