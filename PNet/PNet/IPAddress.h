#pragma once
#include <WS2tcpip.h>
#include "IPVersion.h"
#include <string>

namespace PNet
{
	class IPAddress
	{
	public:
		IPAddress(std::string ip, unsigned short port, IPVersion ipversion);
		std::string ToString();
		uint32_t GetAddress();
		unsigned short GetPort();

		bool IsValid();
		IPVersion GetIPVersion();
	private:
		std::string ip;
		uint32_t address;
		unsigned short port;
		IPVersion ipversion;
		bool isValid = false;
	};
}