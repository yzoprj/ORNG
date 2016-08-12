#ifndef __ORNG_BYTETOOLS_H__
#define __ORNG_BYTETOOLS_H__

#include "common.h"

namespace orng
{

namespace common
{



class ByteTools
{
public:
	static ushort	byteToHex(ubyte val);
	static ubyte	hexToByte(ubyte val);
	static ubyte	twoHexToByte(ubyte highHex, ubyte lowHex);
	static uint		rawArrayToHexString(ubyte *dst, uint maxsize, const ubyte *src, uint len);
	static uint		hexStringToRawString(ubyte *dst, uint maxsize, const ubyte *src, uint len);
	

protected:
	static ubyte hexCodeArray[];
};

}
}


#endif
