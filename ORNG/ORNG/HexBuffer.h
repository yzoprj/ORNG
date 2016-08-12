#ifndef __ORNG_HEXBUFFER_H__
#define __ORNG_HEXBUFFER_H__

#include "RawBuffer.h"
#include "StringBuffer.h"

namespace orng
{

namespace common
{


class HexBuffer
{
public:
	HexBuffer(const RawBuffer &rb);
	HexBuffer(const HexBuffer &hb);
	//HexBuffer(HexBuffer &&hb);

	HexBuffer& operator =(const HexBuffer &hb);
	HexBuffer& operator =(const RawBuffer &hb);

	~HexBuffer(void);

	StringBuffer	getBuffer();
	RawBuffer		getRawBuffer();

protected:
	void convert(const ubyte *rawData, uint length);
	RawBuffer recovert(const ubyte *src, uint length);

private:
	StringBuffer sb;
};

} // end namespace orng

} // end namesapce common


#endif
