#ifndef __ORNG_SOCKETCHANNEL_H__
#define __ORNG_SOCKETCHANNEL_H__

#include "../../tools/RawBuffer.h"
#include "../../tools/Common.h"
#include "NetCommon.h"



namespace orng
{
namespace net
{

class BaseSocket;
class Connection;
class SocketChannel
{
public:
	SocketChannel(Connection *conn);
	~SocketChannel(void);
	void enableEvents(uint events);
	
	void SetCurrentEvent(IO_OPERATION_KEY ioKey = IO_OP_NONE);
	void handleEvent(IO_OPERATION_KEY ioKey  = IO_OP_NONE);
	bool canRead();
	bool canWrite();
	bool canAccept();
	uint getHandle();
private:

	Connection *conn;
	uint eventFlags;
	uint opFlag;

};


}
}






#endif

