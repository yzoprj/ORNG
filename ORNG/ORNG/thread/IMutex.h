
#ifndef __ORNG_IMUTEX_H__
#define __ORNG_IMUTEX_H__

namespace orng
{

namespace thread
{

class IMutex
{
public:
	IMutex(void) {}
	virtual ~IMutex(void) {}

	virtual void lock() = 0;
	virtual void unlock() = 0;
};


class MutexGuard
{
public:
	MutexGuard(IMutex &mtx)
		:mutex(mtx)
	{
		mutex.lock();
	}

	~MutexGuard()
	{
		mutex.unlock();
	}

private:
	IMutex& mutex;
};

} // end namespace orng

} // end namesapce common

#endif



