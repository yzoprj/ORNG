#ifndef __ORNG_NETCOMMON_H__
#define __ORNG_NETCOMMON_H__
#include "../../tools/Common.h"
namespace orng
{
namespace net
{

enum IO_OPERATION_KEY
{
	IO_OP_NONE		= 0x00,
	IO_OP_ACCEPT	= 0x01,
	IO_OP_READ		= 0x02,
	IO_OP_WRITE		= 0x04,
	IO_OP_EXCEPTION	= 0x08,
	IO_OP_CLOSE		= 0x10,
	IO_OP_CONNECTION= 0x20,
	IO_OP_REMOVE	= 0x40
};
}
}
#endif