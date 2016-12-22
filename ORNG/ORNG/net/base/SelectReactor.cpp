#include "SelectReactor.h"
#include <utility>


using std::make_pair;
using namespace orng::net;


SelectReactor::SelectReactor(Acceptor *acceptor)
{
}


SelectReactor::~SelectReactor(void)
{
}

void SelectReactor::registerChannel(SocketChannel *channel)
{
	channels.insert(make_pair(channel->getHandle(), channel));
	selector->registerChannel(channel);
}

void SelectReactor::unregisterChannel(SocketChannel *channel)
{
	selector->unregisterChannel(channel);
	channels.erase(channel->getHandle());

}


void SelectReactor::run()
{
	
	int result = 0;
	int timeout = 3000;


	while(true)
	{
		readChannels.clear();
		writeChannels.clear();
		exceptChannels.clear();
		result = selector->getActivedChannels(readChannels, writeChannels, exceptChannels, timeout);
		
		for (uint i = 0; i < readChannels.size(); i++)
		{
			readChannels[i]->handleEvent(IO_OP_READ);
		}

		for (uint i = 0; i < writeChannels.size(); i++)
		{
			writeChannels[i]->handleEvent(IO_OP_WRITE);
		}

		for (uint i = 0; i < exceptChannels.size(); i++)
		{
			exceptChannels[i]->handleEvent(IO_OP_NONE);
		}
	}

}