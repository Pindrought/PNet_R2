#pragma once
#include "SocketHandle.h"
#include "Protocol.h"
#include "IPAddress.h"
#include "PResult.h"
#include "SocketOption.h"

namespace PNet
{
	class Socket
	{
	public:
		Socket(Protocol protocol = Protocol::TCP, IPVersion ipversion = IPVersion::IPV4, SocketHandle handle = INVALID_SOCKET);
		SocketHandle GetHandle();
		IPVersion GetIPVersion();
		PResult Create();
		PResult Close();
		PResult SetSocketOption(SocketOption socketOption, BOOL flag);
		PResult Listen(IPAddress ipaddress, int backlog = 100);
		PResult Accept(Socket & socket);
		PResult Connect(IPAddress ipaddress);
		PResult Recv(void * buffer, int recvSize, int &bytesReceived);
		PResult Send(void * buffer, int sendSize, int &bytesSent);
		PResult RecvAll(void * buffer, int recvSize);
		PResult SendAll(void * buffer, int sendSize);
	private:
		PResult Bind(IPAddress ipaddress);

		Protocol protocol = Protocol::TCP;
		IPVersion ipversion = IPVersion::IPV4;
		SocketHandle handle = INVALID_SOCKET;
	};
}