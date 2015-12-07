#ifndef _RESTPLUS_PLATFORM_H
#define _RESTPLUS_PLATFORM_H

namespace restplus
{
	class Platform
	{
		public:
			static int Daemonize();
			static int ServerSocket();
			static void DoAccept(int sfd);

		private:
			static int NewSocket();
			static void DoRequest(int clientSock);

			static bool shouldStop;
	};
}

#endif
