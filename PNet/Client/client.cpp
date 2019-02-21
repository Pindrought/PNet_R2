//Tutorial 8
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
			if (socket.Connect(IPAddress("127.0.0.1", 8000, IPVersion::IPV4)) == PResult::P_Success)
			{
				std::cout << "Successfully connected!" << std::endl;
			}
			else
			{
				std::cout << "Failed to connect." << std::endl;
			}
			socket.Close();
		}
	}
	Network::Shutdown();

	system("pause");
	return 0;
}