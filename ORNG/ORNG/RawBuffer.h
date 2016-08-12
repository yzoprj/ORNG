#ifndef __ORNG_RAWBUFFER__
#define __ORNG_RAWBUFFER__
#include "common.h"

namespace orng
{

namespace common
{



class RawBuffer
{
public:
	RawBuffer(void);

	RawBuffer(ubyte *rawData, uint len);
	
	RawBuffer(RawBuffer &&rb);
	
	RawBuffer(const RawBuffer &rb);
	
	RawBuffer& operator=(RawBuffer rb);	
	
	~RawBuffer(void);

	void	setRawData(ubyte *rawData, uint len);
	
	ubyte*	getData() const {return data;}
	
	uint	getLength() const {return length;}

	void	append(ubyte *rawData, uint len);
	
	void	append(const RawBuffer &rb);

protected:
	void	clear();
	void	defaultAlloc();
private:
	ubyte *data;
	uint length;
};

} // end namespace orng

} // end namesapce common

#endif


