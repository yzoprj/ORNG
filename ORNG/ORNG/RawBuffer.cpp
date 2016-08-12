#include "RawBuffer.h"
#include <memory.h>

using namespace orng::common;

RawBuffer::RawBuffer(void)
{
	length = 0;
	data = NULL;
	defaultAlloc();
	
}

RawBuffer::RawBuffer(const RawBuffer &rb)
{
	length = rb.length;
	data = new ubyte[length];
	memcpy(data, rb.data, length);
}


RawBuffer::RawBuffer(RawBuffer &&rb)
	:data(rb.data), length(rb.length)
{
	rb.data = NULL;
	rb.length = 0;
}


RawBuffer::RawBuffer(ubyte *rawData, uint len)
{
	if (rawData == NULL  || len <= 0 )
	{
		defaultAlloc();
	}else
	{
		length = len;
		data = new ubyte[len];
		memcpy(data, rawData, len);
	}
}

RawBuffer& RawBuffer::operator =(RawBuffer rb)
{
	length = rb.length;
	data = new ubyte[length];
	memcpy(data, rb.data, length);
	return *this;
}

RawBuffer::~RawBuffer(void)
{
	clear();
}


void RawBuffer::clear()
{
	length = 0;
	if(data != NULL)
	{
		delete data;
		data = NULL;
	}
}

void RawBuffer::defaultAlloc()
{
	clear();
	length = 1;
	data = new ubyte[length];
	data[0] = 0x00;
}


void RawBuffer::append(ubyte *rawData, uint len)
{
	ubyte *newData = NULL;
	if (rawData == NULL  || len <= 0 )
	{
		return;
	}else
	{
		newData = new ubyte[length + len];
		memcpy(newData, data, length);
		memcpy(newData + length, rawData, len);
		length = length + len;

	}
}

void RawBuffer::append(const RawBuffer &rb)
{
	append(rb.data, rb.length);
}
