//Tutorial 6
//client.cpp
#include <PNet/IncludeMe.h>
#include <iostream>

using namespace PNet;

int main()
{
	if (Network::Initialize())
	{
		Socket socket;
		PResult result = socket.Create();
		if (result == PResult::P_Success)
		{
			result = socket.Connect(IPAddress("127.0.0.1", 8000, IPVersion::IPV4));
			if (result == PResult::P_Success)
			{
				std:
			}
			socket.Close();
		}
	}
	Network::Shutdown();
	return 0;
}