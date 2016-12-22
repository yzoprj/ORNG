// ORNG.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "tools/StringBuffer.h"

#include <iostream>

using namespace std;

// using std::tr1::function;
// using std::bind;
// using namespace std::placeholders;

class A
{
public:
	void func(const char *){}
	void func(int) {}
};

template<typename U, typename T>
struct is_same1
{
	static const int value = false;
};//#1

template<typename T>
struct is_same1<T, T> 
{
	static const int value = true;
};//#1

struct AB
{
	int a;
	char d;
	//char b;
	//char c;
	double dd;

};

int _tmain(int argc, _TCHAR* argv[])
{

// 	void (StringBuffer::*func1)(const char *) = &StringBuffer::append;
// 	std::tr1::function<void (const char *)> callback1 = std::bind(&StringBuffer::append, &str,  _1);
	
	


	AB a = {0};
	a.a = 0x12345678;
	printf("%d----0x%X--0x%X--0x%X\n", sizeof(AB), &a.a, &a.d, &a.dd);
	return 0;
}

