#pragma once
class RawBuffer
{
public:
	RawBuffer(void);
	~RawBuffer(void);

private:
	unsigned char *data;
	unsigned long *length;
};

