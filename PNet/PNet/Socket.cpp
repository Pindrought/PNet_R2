#include "Socket.h"
#include <assert.h>

namespace PNet
{
	Socket::Socket(Protocol protocol, IPVersion ipversion, SocketHandle handle)
		:protocol(protocol),ipversion(ipversion),handle(handle)
	{
		assert(protocol == Protocol::TCP);
		assert(ipversion == IPVersion::IPV4);
	}

	PResult Socket::Create()
	{
		assert(protocol == Protocol::TCP);
		assert(ipversion == IPVersion::IPV4);

		if (handle != INVALID_SOCKET) //If socket already initialized
		{
			return PResult::P_NotYetImplemented;
		}

		if (protocol != Protocol::TCP && protocol != Protocol::UDP) //If protocol is not TCP or UDP (Invalid)
		{
			return PResult::P_NotYetImplemented;
		}

		handle = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create IPV4 TCP Socket

		if (handle == INVALID_SOCKET) //If socket failed to create
		{
			return PResult::P_NotYetImplemented;
		}

		return PResult::P_Success;
	}

	PResult Socket::Close()
	{
		if (handle == INVALID_SOCKET)
			return PResult::P_NotYetImplemented;

		int result = closesocket(handle);
		if (result == 0)
		{
			handle = INVALID_SOCKET;
			return PResult::P_Success;
		}
		else
		{
			return PResult::P_NotYetImplemented;
		}
	}

	SocketHandle Socket::GetHandle()
	{
		return handle;
	}

	IPVersion Socket::GetIPVersion()
	{
		return ipversion;
	}
}
