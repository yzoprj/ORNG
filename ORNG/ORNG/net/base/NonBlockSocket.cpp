#include "NonBlockSocket.h"
#include <WinSock2.h>

using namespace orng::net;

NonBlockSocket::NonBlockSocket(void)
{
}


NonBlockSocket::~NonBlockSocket(void)
{
}


bool NonBlockSocket::open()
{
	if (BaseSocket::open() == false)
	{
		return false;
	}
	setNonBlock(SOCKET_NONBLOCK);
	return true;
};

bool NonBlockSocket::open(InetAddress &hostAddr)
{
	if (BaseSocket::open(hostAddr) == false)
	{
		return false;
	}
	setNonBlock(SOCKET_NONBLOCK);
	return false;
}


void NonBlockSocket::close()
{
	shutdown(fd, SD_BOTH);
	closesocket(fd);
}