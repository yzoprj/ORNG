#ifndef __ORNG_TASK_H__
#define __ORNG_TASK_H__

namespace orng
{
namespace thread
{
class Task
{

public:
	virtual void process() = 0;
};
}
}

#endif
