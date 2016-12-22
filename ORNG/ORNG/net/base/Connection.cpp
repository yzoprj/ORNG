#include "Connection.h"
#include "BaseSocket.h"
using namespace orng::net;

Connection::Connection(void)
{
	sock = new BaseSocket;
	callbackHandler = NULL;
	channel = NULL;
}

Connection::Connection(BaseSocket *sock)
{
	this->sock = sock;
	callbackHandler = NULL;
	channel = NULL;
}

Connection::~Connection(void)
{
}


int Connection::read(char *buf, int len)
{
	int hasSendBytes = 0;
	int ret = 0;
	return 0;
}


int Connection::syncRead(char *buf, int len)
{
	ulong rcvLength = 0;
	ulong hasRcvLen = 0;
	int result = 0;
	ulong flags = 0;
	WSABUF wsaBuf;

	wsaBuf.buf = buf;
	wsaBuf.len = len;
	while (true)
	{
		
		result = WSARecv(sock->getHandle(), &wsaBuf, 1, (LPDWORD)&rcvLength, &flags, NULL, NULL);
		if (result != 0)
		{
			//handle error!
		}
		if (rcvLength == 0)
		{
			break;
		}

		wsaBuf.buf += rcvLength;
		wsaBuf.len -= rcvLength;


	}

	if (result >= 0)
	{
		return -1;
	}

	return len - wsaBuf.len;
	
}


int Connection::syncWrite(const char *buf, int len)
{
	int sndBytesLen = 0;
	
	return true;
}


BaseSocket *Connection::getSocket()
{
	return sock;
}