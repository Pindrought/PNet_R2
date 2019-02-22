//Tutorial 01
//server.cpp
#include <PNet/IncludeMe.h>

int main()
{
	if (PNet::Network::Initialize())
	{
		
	}
	PNet::Network::Shutdown();
	return 0;
}