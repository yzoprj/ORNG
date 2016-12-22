#ifndef __ORNG_NETCALLBACKS_H__
#define __ORNG_NETCALLBACKS_H__

class RawBuffer;
class Connection;
class BaseSocket;
class ConnectionHandler;
// typedef int (HandelReadCallback			*)(Connection &, RawBuffer &);
// typedef int (HandleWriteCallback		*)(Connection &, const RawBuffer &);
// typedef int (HandleExceptionCallback	*)();
// typedef int (HandleCloseCallBack		*)();
// typedef int (HandelTimeoutCallback		*)();
// typedef int (ReadCompleteCallback		*)(Connection &, RawBuffer &);
// typedef int (WriteCompleteCallback		*)(Connection &, RawBuffer &);
// typedef int (ConnectionCallback			*)(Connection &);

typedef ConnectionHandler*	(*CreateConnectionHandlerPtr) (Connection *conn);

typedef BaseSocket*			(*CreateSocketPtr)(int timeout, int isBlock);


#endif