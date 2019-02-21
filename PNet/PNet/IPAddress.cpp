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
		uint32_t test = htonl(ip_int);
		if (ip_int != INADDR_NONE)
		{
			ip_string = hostname; //If address was a valid ipv4 and not a hostname then ip_string = hostname
			isValid = true;
		}
		else //
		{
			// Not a valid address, try to resolve it as a host name
			addrinfo hints = {};
			hints.ai_family = AF_INET;
			addrinfo* result = NULL;
			if (getaddrinfo(hostname.c_str(), NULL, &hints, &result) == 0)
			{
				if (result)
				{
					ip_int = reinterpret_cast<sockaddr_in*>(result->ai_addr)->sin_addr.s_addr;
					ip_string.resize(16); //Resize ip to store ipv4 address in text format
					inet_ntop(AF_INET, &ip_int, &ip_string[0], 16); //Determine ip string from the integer representation of IPV4
					freeaddrinfo(result); //memory cleanup from getaddrinfo call
					isValid = true;
				}
				else
				{
					return; //Not valid
				}
			}
			else
			{
				return; //Not valid
			}
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