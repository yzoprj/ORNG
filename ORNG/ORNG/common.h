#ifndef __ORNG_COMMON_H__
#define __ORNG_COMMON_H__

typedef unsigned char	ubyte;
typedef unsigned long	ulong;
typedef unsigned int	uint;	
typedef unsigned short	ushort;

#ifndef NULL
#define NULL 0
#endif

#define NAMESPACE_BEGIN(name) namespace name {
#define NAMESPACE_END }
#define USING_NAMESPACE(name) using namespace (name);
#define USING_SUB_NAMESPACE(main_name, sub_name) using main_name::sub_name;

#endif