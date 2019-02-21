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
			result = socket.Listen(IPAddress("127.0.0.1", 8000, IPVersion::IPV4));
			if (result == PResult::P_Success)
			{
				std::cout << "Socket successfully bound & listening on port 8000." << std::endl;
				Socket newConnection;
				if (socket.Accept(newConnection) == PResult::P_Success)
				{
					std::cout << "Connection accepted!" << std::endl;
				}
				else
				{
					std::cout << "Failed to accept connection." << std::endl;
				}
			}
			else
			{
				std::cout << "Failed to listen." << std::endl;
			}
			socket.Close();
		}
	}
	Network::Shutdown();

	system("pause");
	return 0;
}