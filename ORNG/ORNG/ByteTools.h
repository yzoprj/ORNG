#ifndef __ORNG_BYTETOOLS_H__
#define __ORNG_BYTETOOLS_H__

#include "common.h"

namespace orng
{

namespace common
{



class CommonTools
{
public:
	static ushort	byteToHex(ubyte val);
	static ubyte	hexToByte(ubyte highHex, ubyte lowHex);
	static uint		rawArrayToHexString(u);

protected:
	static ubyte hexCodeArray[];
};

}
}


#endif
