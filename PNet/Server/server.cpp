//Tutorial 03
//server.cpp
#include <PNet/IncludeMe.h>

using namespace PNet;

int main()
{
	if (Network::Initialize())
	{
		Socket socket;
		PResult result = socket.Create();
		if (result == PResult::P_Success)
		{
			socket.Close();
		}
	}
	Network::Shutdown();
	return 0;
}