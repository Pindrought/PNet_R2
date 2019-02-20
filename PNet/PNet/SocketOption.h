#pragma once

namespace PNet
{
	enum SocketOption
	{
		ReuseAddress, //Allows the socket to be bound to an address that is already in use.
		NoDelay
	};
}