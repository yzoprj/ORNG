#ifndef __ORNG_SELECTMODEL_H__
#define __ORNG_SELECTMODEL_H__
#include "NetCommon.h"
#include "../../tools/Common.h"
#include <map>
#include <vector>
#include <iterator>
using std::map;
using std::vector;
using std::iterator;
namespace orng
{

namespace net
{

class SocketChannel;



class SelectModel
{
public:
	static const int max_fd_size = 60000;

	SelectModel(int max_size, int timeout = 3000);
	
	~SelectModel(void);
	
	void registerChannel(SocketChannel *channel);
	
	void unregisterChannel(SocketChannel *channel);

	bool isAlreadyRegister(SocketChannel *channel);
	
	uint getActivedChannels(vector<SocketChannel *> &readChannels, 
							vector<SocketChannel *> &writeChannels,
							vector<SocketChannel *> &excptChannels, int timeout = 3000);

protected:

	class SelectSet
	{
	public:
		SelectSet(int max_size) ;
		~SelectSet() {}
	public:
		struct select_set 
		{
			uint	fd_count;      /* how many are SET? */
			uint	fd_array[1];   /* an array of SOCKETs */
		};

		void		removeFromSelectSet(uint fd);
		void		addToSelectSet(uint fd);
		void		clearSelectSet();
		bool		isSocketSignal(uint fd);
		bool		isInSelectSet(uint fd);
		uint		getSocketHandle(int idx);
		uint		getCount();
		select_set* getSelectSet() {return fset;}

	private:
		select_set *fset;
		uint		maxsize;
	};

	uint			getMaxFdNum();
private:
	SelectSet				*readSocketSet;
	SelectSet				*writeSocketSet;
	SelectSet				*exceptSocketSet;
	vector<SocketChannel *> readyReadSet;
	vector<SocketChannel *> readyWriteSet;
	vector<SocketChannel *> readyExceptSet;
	map<uint, SocketChannel *>	channels;
	int timeout;
	int maxsize;

};
	
}

}

#endif

