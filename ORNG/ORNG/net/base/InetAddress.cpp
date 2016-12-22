#include "InetAddress.h"
#include <WinSock2.h>
using namespace orng::net;
using orng::common::StringBuffer;


InetAddress::InetAddress(const char *hostAddr, ushort hostPort)
	:port(hostPort)
{
	ip = inet_addr(hostAddr);
}

StringBuffer InetAddress::getIPAddress()
{
	in_addr addr;
	addr.S_un.S_addr = htonl(ip);
	return inet_ntoa(addr);
}


void InetAddress::setIPAddress(const char *hostAddr)
{
	ip = inet_addr(hostAddr);
}

ushort InetAddress::getPort()
{
	return port;
}

ushort InetAddress::convertToNetPort()
{
	return htons(port);
}

ulong InetAddress::convertToNetIP()
{
	return htonl(ip);
}