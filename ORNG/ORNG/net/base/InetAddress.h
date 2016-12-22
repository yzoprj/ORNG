#ifndef __ORNG_INETADDRESS_H__
#define __ORNG_INETADDRESS_H__

#include "../../tools/common.h"
#include "../../tools/StringBuffer.h"
namespace orng
{
	using namespace common;

namespace net
{

class InetAddress
{
public:


	
	InetAddress(uint hostAddr, ushort hostPort)
		:ip(hostAddr), port(hostPort){}
	
	InetAddress(const char *hostAddr, ushort hostPort);
	
	InetAddress() 
		:ip(0), port(0){}

	~InetAddress(void){}


	

	void			setIPAddress(const char *hostAddr);

	void			setIPAddress(uint hostAddr) {ip = hostAddr;}
	
	void			setIpAddress(uint hostPort) {port = hostPort;}
					
	// multithread unsafe;
	StringBuffer	getIPAddress();
	
	ushort			getPort();
	
	ushort			convertToNetPort();
	ulong			convertToNetIP();

private:
	uint ip;
	ushort port;
};

}
}


#endif


