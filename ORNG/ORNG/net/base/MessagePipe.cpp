#include "MessagePipe.h"
#include <Windows.h>

//MessagePipe* MessagePipe::hPipe = NULL;
using namespace orng::net;

MessagePipe::MessagePipe(void)
{
	readHandle = NULL;
	writeHandle = NULL;
	init();
}


MessagePipe::~MessagePipe(void)
{
	CloseHandle(readHandle);
	CloseHandle(writeHandle);
}


int MessagePipe::init()
{

	return CreatePipe(&readHandle, &writeHandle, NULL, 0);

}


int MessagePipe::readMessage(IO_MESSAGE &msg)
{
	DWORD size = 0;
	return ReadFile(readHandle, &msg, sizeof(IO_MESSAGE), &size, NULL);
}

int MessagePipe::writeMessage(const IO_MESSAGE &msg)
{
	DWORD size = 0;
	return WriteFile(writeHandle, &msg, sizeof(IO_MESSAGE), &size, NULL);
}