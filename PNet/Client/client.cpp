//Tutorial 10
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
				char buffer[256];
				strcpy_s(buffer, "Hello From the Client!\0");
				int bytesSent = 0;
				while (result == PResult::P_Success)
				{
					result = socket.SendAll(buffer, 256);
					std::cout << "Attempting to send chunk..." << std::endl;
					Sleep(100);
				}
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