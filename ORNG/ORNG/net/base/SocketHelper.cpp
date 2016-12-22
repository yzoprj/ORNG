#include "SocketHelper.h"

using namespace orng::net;
SocketHelper::SocketHelper(void)
{
}


SocketHelper::~SocketHelper(void)
{
}


SocketHelper::AcceptExPtr SocketHelper::getAccptExPtr(unsigned int sock)
{
	DWORD bytes = 0;
	GUID guidAcceptEx = WSAID_ACCEPTEX;  
	//GUID GuidGetAcceptExSockAddrs = WSAID_GETACCEPTEXSOCKADDRS; 
	AcceptExPtr ptr = NULL;
	if (SOCKET_ERROR == WSAIoctl((SOCKET)sock,
		SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guidAcceptEx,
		sizeof(guidAcceptEx),
		&ptr,
		sizeof(ptr),
		&bytes,
		NULL,
		NULL))
	{
		return NULL;
	}
	return ptr;
}

SocketHelper::GetAcceptExSockAddrsPtr SocketHelper::getAcceptExSockAddrsPtr(unsigned int sock)
{
	DWORD bytes = 0;
	GUID guidAcceptEx = WSAID_GETACCEPTEXSOCKADDRS;  
	//GUID GuidGetAcceptExSockAddrs = WSAID_GETACCEPTEXSOCKADDRS; 
	GetAcceptExSockAddrsPtr ptr = NULL;
	if (SOCKET_ERROR == WSAIoctl((SOCKET)sock,
		SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guidAcceptEx,
		sizeof(guidAcceptEx),
		&ptr,
		sizeof(ptr),
		&bytes,
		NULL,
		NULL))
	{
		return NULL;
	}
	return ptr;
}