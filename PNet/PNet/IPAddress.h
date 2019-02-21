#pragma once
#include <WS2tcpip.h>
#include "IPVersion.h"
#include <string>

namespace PNet
{
	class IPAddress
	{
	public:
		IPAddress(std::string hostname, unsigned short port, IPVersion ipversion);
		std::string GetHostname();

		std::string GetIPAsString();
		uint32_t GetIPAsInt();

		unsigned short GetPort();

		bool IsValid();
		IPVersion GetIPVersion();
	private:
		std::string hostname;
		std::string ip_string;
		uint32_t ip_int;
		unsigned short port;
		IPVersion ipversion;
		bool isValid = false;
	};
}