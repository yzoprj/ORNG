#include "BaseSocket.h"


using namespace orng::net;

BaseSocket::BaseSocket(void)
{
	usedOverlapFlag = false;
	fd = -1;
	ol = NULL;
	buf = NULL;
}

BaseSocket::BaseSocket(uint fd)
{
	this->fd = fd;
	usedOverlapFlag = false;
	ol = NULL;
	buf = NULL;
}

BaseSocket::~BaseSocket(void)
{
	if (ol != NULL)
	{
		delete ol;
		delete buf;
	}
}


void BaseSocket::close()
{
	if (isValidHandle())
	{
		shutdown(fd, SD_BOTH);
		closesocket(fd);
		fd = -1;
	}
}

InetAddress BaseSocket::getLocalAddress()
{
	int ret = -1;
	SOCKADDR_IN addr = {0};
	int len = sizeof(SOCKADDR_IN);
	ret = getsockname(fd, (sockaddr *)&addr, &len);
	if (ret == SOCKET_ERROR)
	{
		return InetAddress();
	}
	
	return InetAddress(ntohl(addr.sin_addr.S_un.S_addr), ntohs(addr.sin_port));
}

InetAddress BaseSocket::getRemoteAddress()
{
	int ret = -1;
	SOCKADDR_IN addr = {0};
	int len = sizeof(SOCKADDR_IN);
	ret = getpeername(fd, (sockaddr *)&addr, &len);
	if (ret == SOCKET_ERROR)
	{
		return InetAddress();
	}

	return InetAddress(ntohl(addr.sin_addr.S_un.S_addr), ntohs(addr.sin_port));
}


void BaseSocket::setSocketOption(const SocketOption &opt)
{
	setsockopt(fd, opt.level, opt.optName, (char *)&opt.optVal, opt.valLen);
}

void BaseSocket::setNonBlock(BaseSocket::SOCKET_BLOCK_FLAGS flags)
{

	ioctlsocket(fd, FIONBIO, (ulong *)&flags);
}

void BaseSocket::useOverlapped()
{
	usedOverlapFlag = true;
	ol = new OVERLAPPED;
	buf = new  char[MAX_BUFFER_LENGTH];
	wsaBuf.buf = buf;
	wsaBuf.len = MAX_BUFFER_LENGTH;
}


void BaseSocket::getSocketOption(SocketOption &opt)
{
	getsockopt(fd, opt.optName, opt.level, (char *)&opt.optVal, &opt.valLen);
}


bool BaseSocket::open()
{
	if((fd = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0)) == SOCKET_ERROR)
	{
		return false;
	}
	return true;
}

bool BaseSocket::open( InetAddress &hostAddr)
{
	if (open() == true)
	{
		SOCKADDR_IN addr;
		int len = sizeof(addr);
		addr.sin_family = AF_INET;
		addr.sin_port = hostAddr.convertToNetPort();
		addr.sin_addr.S_un.S_addr = hostAddr.convertToNetIP();

		if (bind(fd, (sockaddr *)&addr, len) == false)
		{
			return false;
		}
	}
	return true;
}