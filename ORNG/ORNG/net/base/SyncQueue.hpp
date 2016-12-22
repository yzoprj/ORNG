#ifndef __ORNG_SYNCQUEUE_HPP__
#define __ORNG_SYNCQUEUE_HPP__
#include "../../thread/SyncObjects.h"
#include "../../tools/ObjectProxy.hpp"
#include "../../tools/Common.h"
#include <deque>


namespace orng
{
namespace net
{
using thread::MutexGuard
using thread::CriticalSection
using common::ObjectProxy
using std::deque;

template<typename T>
class SyncQueue
{
public:
	SyncQueue() {}
	~SyncQueue() {}

	void push_back(T *context)
	{
		MutexGuard guard(cs);
		objQueue.push_back(ObjectProxy(context));
	}

	ObjectProxy<T *> pop()
	{
		MutexGuard guard(cs);
		ObjectProxy<T *> op = objQueue.front();
		objQueue.pop_front();
		return op;
	}

	uint size() { return objQueue.size();}

private:
	CriticalSection cs;
	deque<ObjectProxy<T *> > objQueue;
};

}
}

#endif