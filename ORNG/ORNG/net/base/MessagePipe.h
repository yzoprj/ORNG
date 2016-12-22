#ifndef __ORNG_MESSAGEPIPE_H__
#define __ORNG_MESSAGEPIPE_H__
#include "../../tools/Common.h"
#include "NetCommon.h"

namespace orng
{

namespace net
{





struct IO_MESSAGE
{
	IO_OPERATION_KEY key;
	void *data;
};

class MessagePipe
{
public:
	MessagePipe(void);
	~MessagePipe(void);
	int init();
	int readMessage(IO_MESSAGE &msg);
	int writeMessage(const IO_MESSAGE &msg);
private:

	void *readHandle;
	void *writeHandle; 
};


}
}

#endif
