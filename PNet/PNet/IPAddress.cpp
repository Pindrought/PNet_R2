#include "IPAddress.h"

namespace PNet
{
	IPAddress::IPAddress(std::string ip, unsigned short port, IPVersion ipversion)
		:ip(ip), port(htons(port)), ipversion(ipversion)
	{
		//Need to generate 32 bit integer representation of ip
		address = INADDR_NONE;
		inet_pton(AF_INET, ip.c_str(), &address); //Attempt to convert ip from presentation to network format (string to 32 bit big endian integer)

		if (address != INADDR_NONE)
		{
			isValid = true;
		}
	}
	std::string IPAddress::ToString()
	{
		return ip;
	}
	uint32_t IPAddress::GetAddress()
	{
		return address;
	}
	unsigned short IPAddress::GetPort()
	{
		return port;
	}
	bool IPAddress::IsValid()
	{
		return isValid;
	}
	IPVersion IPAddress::GetIPVersion()
	{
		return ipversion;
	}
}