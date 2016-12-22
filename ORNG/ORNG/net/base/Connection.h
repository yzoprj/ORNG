#ifndef __ORNG_CONNECTION_H__
#define __ORNG_CONNECTION_H__
#include "../../tools/Common.h"
#include "BaseSocket.h"

namespace orng
{

namespace net
{

class ConnectionHandler;
class SocketChannel;
class RawBuffer;
class Acceptor;


class Connection
{
public:
	friend class SocketChannel;
	friend class Acceptor;

	Connection(void);
	Connection(BaseSocket *sock);
	~Connection(void);

	int					read(char *buf, int maxlen);

	int					read(RawBuffer &rb);
	
	int					write(const char *buf, int len);

	int					write(const RawBuffer & rb);

	ubyte				readByte();

	int					writeByte(ubyte val);
	
	void				setConnectionHandler(ConnectionHandler *callbackHandler);

	SocketChannel*		getSockChannel();

protected:
	
	void				handleRead();

	void				handleWrite();

	void				handleException();

	void				handleClose();

	int					syncRead(char *buf, int len);
		
	int					syncWrite(const char *buf, int len);

	int					asyncRead(char *buf, int len);

	int					asyncWrite(const char *buf, int len);

	BaseSocket*			getSocket();


private:
	BaseSocket			*sock;
	SocketChannel		*channel;
	ConnectionHandler	*callbackHandler;

};
	
}
}

#endif


