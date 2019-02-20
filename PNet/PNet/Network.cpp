#include "Network.h"
#include <iostream>

bool PNet::Network::Initialize()
{
	WSADATA wsaData;

	int result = WSAStartup(MAKEWORD(2, 2), &wsaData); //Attempt to startup winsock api
	if (result != 0) //If winsock api failed to start
	{
		std::cerr << "WSA Startup failed with error: " << result << std::endl;
		return false;
	}

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) //If winsock api version doesn't match
	{
		std::cerr << "Could not find a usable version of Winsock.dll" << result << std::endl;
		return false;
	}

	return true;
}

void PNet::Network::Shutdown()
{
	WSACleanup();
}
