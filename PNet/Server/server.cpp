//Tutorial 10
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

					char buffer[256];
					int bytesReceived = 0;
					while (result == PResult::P_Success)
					{
						result = newConnection.Recv(buffer, 256, bytesReceived);
						if (result != PResult::P_Success)
							break;
						std::cout << buffer << std::endl;
					}
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