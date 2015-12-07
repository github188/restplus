#include "restplush.h"

namespace restplus
{
	Connection::Connection(int fd, ConnectionStates connState)
	{
		this->fd = fd;
		this->connState = connState;
	}

	int Connection::GetFd()
	{
		return this->fd;
	}

	ConnectionStates GetConnectionState()
	{
		return this->connState;
	}

	void SetFd(int fd)
	{
		this->fd = fd;
	}

	void SetConnectionState(ConnectionStates connState)
	{
		this->connState = connState;
	}
}
