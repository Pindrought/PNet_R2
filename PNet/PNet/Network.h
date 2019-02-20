#pragma once
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

namespace PNet
{
	class Network
	{
	public:
		static bool Initialize();
		static void Shutdown();
	};
}