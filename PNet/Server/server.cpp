//Tutorial 8
//server.cpp
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
			result = socket.Listen(IPAddress("0.0.0.0", 8000, IPVersion::IPV4));
			if (result == PResult::P_Success)
			{
				std::cout << "Socket successfully listening on port 8000." << std::endl;
			}
			socket.Close();
		}
	}
	Network::Shutdown();
	return 0;
}