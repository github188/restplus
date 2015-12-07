#include <netdb.h>

#include "restplus.h"

static struct event_base *mainBase = event_base_new();
Connection **conns;

static int NewSocket(struct addrinfo* ai)
{
	int sfd;
	int flags;

	if((sfd = socket(ai->ai_family, ai->socktype, ai->ai_protocol)) == -1)
	{
		return -1;
	}

	if((flags = fcntl(sfd, F_GETFL, 0)) < 0 ||
		fcntl(sfd, F_SETFL, flags | O_NONBLOCK) < 0)
	{
		perror("setting O_NONBLOCK");
		close(sfd);
		return -1;
	}

	return sfd;
}

static int ServerSocket(const char* interface, int port)
{
	int sfd;
	struct addrinfo *ai;
	struct addrinfo *next;
	struct addrinfo hints = 
	{
		.ai_flags = AI_PASSIVE,
		.ai_family = AF_UNSPEC
	};

	char port_buf[NI_MAXSERV];
	int error;
	int success = 0;
	int flags = 1;

	hints.ai_socktype = SOCK_STREAM;

	if(port == -1)
	{
		port = 0;
	}

	snprintf(port_buf, sizeof(port_buf), "%d", port);
	
	error = getaddrinfo(interface, port_buf, &hints, &ai);
	if(error != 0)
	{
		if(error != EAI_SYSTEM)
		{
			fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(error));
		}
		else
		{
			perror("getaddrinfo()");
		}
		return 1;
	}

	for(next = ai; next; next = next->ai_next)
	{
		if((sfd = NewSocket(next)) == -1)
		{
			continue;
		}

		//TODO: judge the return value
		error = setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (void*)&flags, sizeof(flags));
		error = setsockopt(sfd, SOL_SOCKET, SO_KEEPALIVE, (void*)&flags, sizeof(flags));
		error = setsockopt(sfd, SOL_SOCKET, SO_LINGER, (void*)&ling, sizeof(ling));
		error = setsockopt(sfd, IPPROTO_TCP, TCP_NODELAY, (void*)&flags, sizeof(flags));

		if(bind(sfd, next->ai_addr, next->ai_addrlen) == -1)
		{
			close(sfd);
			continue;
		}
		else
		{
			success++;
			
			if(listen(sfd, Settings.backlog) == -1)
			{
				perror("listen()");
				close(sfd);
				freeaddrinfo(ai);
				return 1;
			}
			
			struct event *listen_event = event_new(mainBase, sfd, EV_READ|EV_PERSIST, DoAccept, (void*)mainBase);
			event_add(listen_event, NULL);
		}
	}
}


