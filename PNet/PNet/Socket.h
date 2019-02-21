#pragma once
#include "SocketHandle.h"
#include "Protocol.h"
#include "IPVersion.h"
#include "PResult.h"
#include "SocketOption.h"

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
		PResult SetSocketOption(SocketOption socketOption, BOOL flag);
	private:
		Protocol protocol = Protocol::TCP;
		IPVersion ipversion = IPVersion::IPV4;
		SocketHandle handle = INVALID_SOCKET;
	};
}