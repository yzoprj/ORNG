#include "Event.h"

using namespace orng::thread;
Event::Event(void)
{
	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
}

void Event::setEvent()
{
	::SetEvent(hEvent);
}

void Event::resetEvent()
{
	::ResetEvent(hEvent);
}

Event::~Event(void)
{
}
