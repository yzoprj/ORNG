#include "SocketChannel.h"
#include "BaseSocket.h"
#include "Connection.h"
using namespace orng::net;

SocketChannel::SocketChannel(Connection *conn)
{
	this->conn = conn;
	eventFlags = 0;
	opFlag = IO_OP_NONE;
}


SocketChannel::~SocketChannel(void)
{
}



void SocketChannel::enableEvents(uint events)
{
	eventFlags = events;
}

uint SocketChannel::getHandle()
{
	 return (uint)conn->getSocket()->getHandle();
}


void SocketChannel::SetCurrentEvent(IO_OPERATION_KEY ioKey)
{
	opFlag = ioKey;
}

bool SocketChannel::canAccept()
{
	return (opFlag & IO_OP_ACCEPT) == 0 ? true : false;
}

bool SocketChannel::canRead()
{
	return (opFlag & IO_OP_READ) == 0 ? true : false;
}

bool SocketChannel::canWrite()
{
	return (opFlag & IO_OP_WRITE) == 0 ? true : false;
}


void SocketChannel::handleEvent(IO_OPERATION_KEY ioKey)
{

}