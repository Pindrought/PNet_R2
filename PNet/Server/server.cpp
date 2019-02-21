//Tutorial 5
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
			result = socket.Bind(IPAddress("0.0.0.0", 8000, IPVersion::IPV4));
			if (result == PResult::P_Success)
			{
				std::cout << "Socket successfully bound to port 8000." << std::endl;
			}
			socket.Close();
		}
	}
	Network::Shutdown();
	return 0;
}