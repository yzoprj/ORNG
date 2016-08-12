#include "HexBuffer.h"
#include "ByteTools.h"

using namespace orng::common;

HexBuffer::HexBuffer(const RawBuffer & rb)
{
	convert(rb.getData(), rb.getLength());
}

HexBuffer::HexBuffer(const HexBuffer &hb)
{
	sb = hb.sb;
}

HexBuffer::~HexBuffer(void)
{
}


RawBuffer HexBuffer::getRawBuffer()
{
	return recovert((const ubyte *)sb.getData(), sb.getLength());
}

StringBuffer HexBuffer::getBuffer()
{
	return sb;
}





void HexBuffer::convert(const ubyte *rawData, uint length)
{
	uint bufLen = length * 2 + 1;
	ubyte *buf = NULL;

	buf = new ubyte[bufLen];

	ByteTools::rawArrayToHexString(buf, bufLen, rawData, length);

	sb = (const char *)buf;
	delete buf;

}

RawBuffer HexBuffer::recovert(const ubyte *src, uint length)
{
	uint bufLen = length / 2;
	ubyte *buf = NULL;

	buf = new ubyte[bufLen];
	bufLen = ByteTools::hexStringToRawString(buf, bufLen, src, length);

	return RawBuffer(buf, bufLen);
}