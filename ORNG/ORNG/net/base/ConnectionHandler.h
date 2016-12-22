#ifndef __ORNG_CONNECTIONHANDLER_H__
#define __ORNG_CONNECTIONHANDLER_H__

namespace orng
{

namespace net
{

class Connection;
class RawBuffer;
class StringBuffer;
class ConnectionHandler
{
public:
	ConnectionHandler(void);
	~ConnectionHandler(void);

	virtual void handleRead(Connection &conn, RawBuffer &rb) {}
	virtual void handleWrite(Connection &conn, const RawBuffer &rb) {}
	virtual void handleException(Connection &conn) {}
	virtual void handleClose(Connection &conn) {}
};


template <typename T>
class ConnectionHandlerFactory
{

};

}
}
#endif
