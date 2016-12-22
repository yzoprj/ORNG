#ifndef __ORNG_ACCEPTOR_H__
#define __ORNG_ACCEPTOR_H__

#include <map>
#include <vector>
#include "../../tools/Common.h"
#include "NetCommon.h"
#include "NetCallbacks.h"
using std::vector;
using std::map;
namespace orng
{

namespace net
{

class BaseSocket;
class Connection;
class SocketChannel;

class Acceptor
{
public:
	Acceptor();
	~Acceptor(void);
	void init(const char *ip = "127.0.0.1", uint port = 10008);
	void destroy();
	void setNewConnectionCallback(CreateConnectionHandlerPtr ptr);
	void handleAccept();
	void handleRead() {}
	void handleWrite(){}

private:
	BaseSocket *sock;
	SocketChannel *channel;
	map<uint, Connection *> connMap;
};


}
}
 #endif
