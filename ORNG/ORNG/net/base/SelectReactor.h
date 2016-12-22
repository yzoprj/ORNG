#ifndef __ORNG_SELECTREACTOR_H__
#define __ORNG_SELECTREACTOR_H__

#include <vector>
#include <map>
#include "../../tools/Common.h"
#include "NetCommon.h"
#include "SocketChannel.h"
#include "Acceptor.h"
#include "SelectModel.h"

using std::vector;
using std::map;
// 
// class SocketChannel;
// class Acceptor;
// class SelectModel;

namespace orng
{
namespace net
{

class SelectReactor
{
public:
	SelectReactor(Acceptor *acceptor);
	~SelectReactor(void);
	void registerChannel(SocketChannel *channel);
	void unregisterChannel(SocketChannel *channel);
	void run();
private:
	vector<SocketChannel *>		readChannels;
	vector<SocketChannel *>		writeChannels;
	vector<SocketChannel *>		exceptChannels;
	map<uint, SocketChannel *>	channels;
	SelectModel					*selector;
	Acceptor					*acceptor;
};



}
}

#endif

