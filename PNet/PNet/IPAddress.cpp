#include "IPAddress.h"

namespace PNet
{
	IPAddress::IPAddress(std::string hostname, unsigned short port, IPVersion ipversion)
		:hostname(hostname), port(htons(port)), ipversion(ipversion)
	{
		ip_string = "";
		//Need to generate 32 bit integer representation of ip
		ip_int = INADDR_NONE;
		inet_pton(AF_INET, hostname.c_str(), &ip_int); //Attempt to convert ip from presentation to network format (string to 32 bit big endian integer)

		if (ip_int != INADDR_NONE)
		{
			ip_string = hostname; //If address was a valid ipv4/successfully converted then ip_string = hostname
			isValid = true;
		}
		
	}
	std::string IPAddress::GetHostname()
	{
		return hostname;
	}
	std::string IPAddress::GetIPAsString()
	{
		return ip_string;
	}
	uint32_t IPAddress::GetIPAsInt()
	{
		return ip_int;
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