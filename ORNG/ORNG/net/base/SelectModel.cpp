#include "SelectModel.h"
#include <WinSock2.h>
#include <utility>
#include "SocketChannel.h"
using namespace orng::net;

using std::make_pair;

SelectModel::SelectSet::SelectSet(int max_size)
{
	fset = (select_set *)malloc(sizeof(select_set) + sizeof(uint) * maxsize);
	memset(fset, 0, sizeof(select_set) + sizeof(uint) * maxsize);
	maxsize = max_size;
}

SelectModel::SelectModel(int max_size, int timeout)
{

	if (max_size > max_fd_size)
	{
		max_size = max_fd_size;
	}
	maxsize			= max_size;
	readSocketSet	= new SelectSet(maxsize);
	writeSocketSet	= new SelectSet(maxsize);
	exceptSocketSet = new SelectSet(maxsize);
}


SelectModel::~SelectModel(void)
{
	if (readSocketSet != NULL)
	{
		delete readSocketSet;
	}

	if (writeSocketSet != NULL)
	{
		delete writeSocketSet;
	}

	if (exceptSocketSet != NULL)
	{
		delete exceptSocketSet;
	}

	channels.clear();
}



void SelectModel::SelectSet::clearSelectSet()
{
	FD_ZERO(fset);
}

void SelectModel::SelectSet::addToSelectSet(uint fd)
{
	u_int __i; 
	for (__i = 0; __i < ((select_set FAR *)(fset))->fd_count; __i++) { 
		if (((select_set FAR *)(fset))->fd_array[__i] == (fd)) { 
			break; 
		} 
	} 
	if (__i == ((select_set FAR *)(fset))->fd_count) { 
		if (((select_set FAR *)(fset))->fd_count < maxsize) {
			((select_set FAR *)(fset))->fd_array[__i] = (fd); 
			((select_set FAR *)(fset))->fd_count++; 
		} 
	} 
}


uint SelectModel::SelectSet::getCount()
{
	return fset == NULL ? 0 : fset->fd_count;
}

void SelectModel::SelectSet::removeFromSelectSet(uint fd)
{
	FD_CLR(fd, fset);
}

bool SelectModel::SelectSet::isInSelectSet(uint fd)
{
	bool flag;

	uint __i;

	flag = false;
	for (__i = 0; __i < ((select_set FAR *)(fset))->fd_count; __i++) { 
		if (((select_set FAR *)(fset))->fd_array[__i] == (fd)) { 
			flag = false;
			break; 
		} 
	} 

	return flag;
}

uint SelectModel::getMaxFdNum()
{
	uint maxfd = 0;
	map<uint, SocketChannel *>::const_iterator iter = channels.cbegin();
	if (iter == channels.cend())
	{
		return 0;
	}
	while (iter != channels.cend())
	{
		
		if (maxfd > (*iter->second).getHandle())
		{
			maxfd = (*iter->second).getHandle();
		}
		iter++;
	}

	return maxfd;

}


bool SelectModel::SelectSet::isSocketSignal(uint fd)
{
	return FD_ISSET(fd, fset) == 1 ? true : false;
}

void SelectModel::registerChannel(SocketChannel *channel)
{
	if (channels.size() > max_fd_size)
	{
		return;
	}

// 	if (channel->canAccept() && channel->canRead())
// 	{
// 		readSocketSet->addToSelectSet(channel->getHandle());
// 	}else if (channel->canWrite())
// 	{
// 		writeSocketSet->addToSelectSet(channel->getHandle());
// 	}
	if (isAlreadyRegister(channel))
	{
		return;
	}

	channels.insert(make_pair(channel->getHandle(), channel));

}

void SelectModel::unregisterChannel(SocketChannel *channel)
{
// 	if (readSocketSet->isInSelectSet(channel->getHandle()))
// 	{
// 		readSocketSet->removeFromSelectSet(channel->getHandle());
// 	}
// 	if (writeSocketSet->isInSelectSet(channel->getHandle()))
// 	{
// 		writeSocketSet->removeFromSelectSet(channel->getHandle());
// 	}
// 	if (exceptSocketSet->isInSelectSetSelectSet(channel->getHandle()));
// 	{
// 		exceptSocketSet->removeFromSelectSet(channel->getHandle());
// 	}

	channels.erase(channel->getHandle());
}


bool SelectModel::isAlreadyRegister(SocketChannel *channel)
{
	map<uint, SocketChannel *>::iterator iter = channels.find(channel->getHandle());
	if (iter != channels.end())
	{
		return false;
	}
	return true;
}


uint SelectModel::getActivedChannels(vector<SocketChannel *> &readChannels, 
									 vector<SocketChannel *> &writeChannels, 
									 vector<SocketChannel *> &excptChannels, int timeout /* = 3000 */)
{
	readSocketSet->clearSelectSet();
	writeSocketSet->clearSelectSet();
	exceptSocketSet->clearSelectSet();
	readyReadSet.clear();
	readyWriteSet.clear();
	readyExceptSet.clear();

	map<uint, SocketChannel *>::iterator iter = channels.begin();
	while (iter != channels.end())
	{
		if (iter->second->canRead())
		{
			readyReadSet.push_back(iter->second);
			readSocketSet->addToSelectSet(iter->first);
		}else if (iter->second->canWrite())
		{
			readyWriteSet.push_back(iter->second);
			writeSocketSet->addToSelectSet(iter->first);
		}else if (iter->second->canAccept())
		{
			readyExceptSet.push_back(iter->second);
			readSocketSet->addToSelectSet(iter->first);
		}
		iter++;
	}
	timeval tm;
	tm.tv_sec = 0;
	tm.tv_usec = timeout;
	int result = select(getMaxFdNum(), (fd_set *)readSocketSet->getSelectSet(), 
						(fd_set *)writeSocketSet->getSelectSet(), (fd_set *)exceptSocketSet->getSelectSet(), &tm);

	
	if (result > 0)
	{
		for (uint i = 0; i < readyReadSet.size(); i++)
		{
			
			if (readSocketSet->isSocketSignal(readyReadSet[i]->getHandle()))
			{
				readChannels.push_back(readyReadSet[i]);
			}
		}

		for (uint i = 0; i < readyWriteSet.size(); i++)
		{

			if (writeSocketSet->isSocketSignal(readyWriteSet[i]->getHandle()))
			{
				writeChannels.push_back(readyWriteSet[i]);
			}
		}

		for (uint i = 0; i < readyExceptSet.size(); i++)
		{

			if (exceptSocketSet->isSocketSignal(readyExceptSet[i]->getHandle()))
			{
				excptChannels.push_back(readyExceptSet[i]);
			}
		}
	}
	return result;
}