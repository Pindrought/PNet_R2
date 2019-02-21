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

		if (SetSocketOption(PNet::SocketOption::NoDelay, TRUE) != PResult::P_Success)
			return PResult::P_NotYetImplemented;

		if (SetSocketOption(PNet::SocketOption::ReuseAddress, TRUE) != PResult::P_Success)
			return PResult::P_NotYetImplemented;

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

	PResult Socket::SetSocketOption(SocketOption socketOption, BOOL flag)
	{
		int result = SOCKET_ERROR;
		switch (socketOption)
		{
		case SocketOption::NoDelay: //Nagle's Algorithm
			result = setsockopt(handle, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(BOOL));
			break;
		case SocketOption::ReuseAddress:
			result = setsockopt(handle, SOL_SOCKET, SO_REUSEADDR, (char*)&flag, sizeof(BOOL));
			break;
		}

		if (result == SOCKET_ERROR)
		{
			int error = WSAGetLastError();
			return PResult::P_NotYetImplemented;
		}

		return PResult::P_Success;
	}

	PResult Socket::Listen(IPAddress ipaddress, int backlog)
	{
		PResult result = Bind(ipaddress);
		if (result != PResult::P_Success)
			return result;

		if (listen(handle, backlog) == SOCKET_ERROR)
		{
			int error = WSAGetLastError();
			return PResult::P_NotYetImplemented;
		}

		return PResult::P_Success;
	}

	PResult Socket::Bind(IPAddress ipaddress)
	{
		sockaddr_in addr = {};
		addr.sin_family = AF_INET; //IPV4
		addr.sin_port = ipaddress.GetPort();
		addr.sin_addr.s_addr = ipaddress.GetIPAsInt();
		if (bind(handle, (sockaddr*)&addr, sizeof(sockaddr_in)) == SOCKET_ERROR)
		{
			int error = WSAGetLastError();
			return PResult::P_NotYetImplemented;
		}
		return PResult::P_Success;
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
