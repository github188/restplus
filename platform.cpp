#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pthread.h>

#include "restplus.h"

namespace restplus
{
	bool Platform::shouldStop = false;

	int Platform::Daemonize()
	{
		int fd;

		switch(fork())
		{
			case -1:
				return -1;

			case 0:
				break;

			default:
				_exit(EXIT_SUCCESS);
		}

		if(setsid() == -1)
		{
			perror("setsid");
			return -1;
		}

		if(chdir("/") != 0)
		{
			perror("chdir");
			return -1;
		}

		if((fd = open("/dev/null", O_RDWR, 0)) != -1)
		{
			if(dup2(fd, STDIN_FILENO) < 0)
			{
				perror("dup2 stdin");
				return -1;
			}

			if(dup2(fd, STDOUT_FILENO) < 0)
			{
				perror("dup2 stdout");
				return -1;
			}

			if(dup2(fd, STDERR_FILENO) < 0)
			{
				perror("dup2 stderr");
				return -1;
			}

			if(fd > STDERR_FILENO)
			{
				if(close(fd) < 0)
				{
					perror("close");
					return -1;
				}
			}
		}

		return 0;
	}

	int Platform::NewSocket()
	{
		int sfd;
		int flags;
		
		if((sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			return -1;
		}

/*
		if((flags = fcntl(sfd, F_GETFL, 0)) < 0 ||
			fcntl(sfd, F_SETFL, flags | O_NONBLOCK) < 0)
		{
			perror("setting O_NONBLOCK");
			close(sfd);
			return -1;
		}
*/

		return sfd;
	}

	int Platform::ServerSocket()
	{
		int sfd;
		int error;
		int flags = 1;
		struct sockaddr_in sin;
		sin.sin_family = AF_INET;
		sin.sin_addr.s_addr = 0;
		sin.sin_port = htons(Settings::port);

		if((sfd = NewSocket()) == -1)
		{
			return -1;
		}

		//TODO: judge the return value
		setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (void*)&flags, sizeof(flags));
		setsockopt(sfd, SOL_SOCKET, SO_KEEPALIVE, (void*)&flags, sizeof(flags));
		setsockopt(sfd, SOL_SOCKET, SO_LINGER, (void*)&flags, sizeof(flags));
		setsockopt(sfd, IPPROTO_TCP, TCP_NODELAY, (void*)&flags, sizeof(flags));

		if(bind(sfd, (struct sockaddr*)&sin, sizeof(sin)) < 0)
		{
			perror("bind");
			close(sfd);
			return -1;
		}
		
		if(listen(sfd, Settings::backlog) < 0)
		{
			perror("listen");
			close(sfd);
			return -1;
		}

		return sfd;
	}
	
	void Platform::DoRequest(int clientSock)
	{
		Request request = ParseRequest(clientSock);
			
	}

	Request Platform::ParseRequest(int fd)
	{
		const int maxLine = 1024;
		char buf[maxLine];
		int n;
		
		while((n = read(clientSock, buf, maxLine)) > 0)
		{
			printf("%s", buf);
			write(clientSock, buf, n);
		}
	}
	
	void Platform::DoAccept(int sfd)
	{
		int clientSock = -1;
		struct sockaddr_in clientSA;
		socklen_t clientSALen;
		pthread_t newThread;

		while(!shouldStop)
		{
			clientSock = accept(sfd, (struct sockaddr*)&clientSA, &clientSALen);
			
			if(clientSock == -1)
			{
				perror("accept");
				exit(-1);
			}

/*
			if(pthread_create(&newThread, NULL, DoRequest, clientSock) != 0)
			{
				perror("pthrea_create");
			}
*/
			DoRequest(clientSock);
		}

		close(sfd);
	}
}
