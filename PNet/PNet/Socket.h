#pragma once
#include "SocketHandle.h"
#include "Protocol.h"
#include "IPVersion.h"
#include "PResult.h"

namespace PNet
{
	class Socket
	{
	public:
		Socket(Protocol protocol = Protocol::TCP, IPVersion ipversion = IPVersion::IPV4, SocketHandle handle = INVALID_SOCKET);
	public:
		SocketHandle GetHandle();
		IPVersion GetIPVersion();
		PResult Create();
		PResult Close();
	private:
		Protocol protocol = Protocol::TCP;
		IPVersion ipversion = IPVersion::IPV4;
		SocketHandle handle = INVALID_SOCKET;
		bool isBlocking = false;
	};
}