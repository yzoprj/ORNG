#ifndef __ORNG_EVENT_H__
#define __ORNG_EVENT_H__
#endif
#include <Windows.h>
#include "../tools/Common.h"
namespace orng
{
namespace thread
{

class Event
{
public:
	Event(void);
	~Event(void);
	void setEvent();
	void resetEvent();
	HANDLE getHandle() {return hEvent;}

private:
	HANDLE hEvent;
	};


}
}

