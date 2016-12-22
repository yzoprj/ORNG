#ifndef __ORNG_BASESOCKET_H__
#define __ORNG_BASESOCKET_H__

#include "../../tools/common.h"
#include "InetAddress.h"

#include <WinSock2.h>
namespace orng
{
	
namespace net
{

const int MAX_BUFFER_LENGTH = 8192;

struct SocketOption
{
	enum SOCKET_LEVEL
	{
		LEVEL_SOL_SOCKET = 0xFFFF
	};

	enum SOCKET_OPTION_FLAGS
	{
		OPTION_SO_KEEPALIVE		= 0x0008,
		OPTION_SO_BROADCAST		= 0x0020,
		OPTION_SO_LINGER		= 0x0080,
		OPTION_SO_OOBINLINE		= 0x0100,
		OPTION_SO_SNDBUF		= 0x1001,
		OPTION_SO_RCVBUF		= 0x1002,
		OPTION_SO_SNDTIMEO		= 0x1005,
		OPTION_SO_RCVTIMEO		= 0x1006
	};


	int		level;
	int		optName;

	union _Timeval
	{
		int nVal;
		struct
		{
			uint tv_sec;
			uint tv_usec;
		}nTime;
	}optVal;
	int		valLen;

};

class BaseSocket
{
public:
	
	enum SOCKET_BLOCK_FLAGS
	{
		SOCKET_BLOCK = 0,
		SOCKET_NONBLOCK = 1
	};

	BaseSocket(void);
	BaseSocket(uint fd);

	virtual ~BaseSocket(void);

	void			setNonBlock(BaseSocket::SOCKET_BLOCK_FLAGS flags = SOCKET_BLOCK);
	
	void			useOverlapped();

	void			setSocketOption(const SocketOption &opt);
	
	void			getSocketOption(SocketOption &opt);
	
	virtual bool	open();

	virtual bool	open( InetAddress &hostAddr);

	virtual void	close();

	bool			isUsedOverlapped() {return usedOverlapFlag;}

	OVERLAPPED*		getOverlaped() {return ol;}

	WSABUF*			getWSABuf() {return &wsaBuf;}

	bool			isValidHandle() {return true;}

	bool			isConnected(){ return true;}

	InetAddress		getLocalAddress();

	InetAddress		getRemoteAddress();
	
	uint			getHandle() const {return fd;}

	uint			fd;
	bool			usedOverlapFlag;
	OVERLAPPED		*ol;
	char			*buf;
	WSABUF			wsaBuf;
	
private:


};



}

}

#endif
