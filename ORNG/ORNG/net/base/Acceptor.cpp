#include "Acceptor.h"
#include <WinSock2.h>
#include <utility>
#include "BaseSocket.h"
#include "NonBlockSocket.h"
#include "Connection.h"
using std::make_pair;
using namespace orng::net;
Acceptor::Acceptor()
{
	sock = new NonBlockSocket();
}



Acceptor::~Acceptor(void)
{
	if (sock != NULL)
	{
		delete sock;
	}
}

void Acceptor::init(const char *ip /* = "127.0.0.1" */, uint port /* = 10008 */)
{
	if (sock == NULL)
	{
		return;
	}
	if(sock->open(InetAddress(ip, port)) == true)
	{
		listen(sock->getHandle(), 64);
	}
	
}


void Acceptor::handleAccept()
{
	SOCKADDR_IN addr;
	int addrSize = sizeof(addr);
	int fd = WSAAccept(sock->getHandle(), (sockaddr *)&addr, &addrSize,NULL, NULL);
	BaseSocket *client = new NonBlockSocket(fd);
	Connection *conn = new Connection(client);
	connMap.insert(make_pair(fd, conn));
}

