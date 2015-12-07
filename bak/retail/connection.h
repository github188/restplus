namespace restplus
{
	enum ConnectionStates
	{
		connListening,
		connRead,
		connWrite,
		connClosed
	};

	class Connection
	{
		public:
			Connection(int fd, ConnectionStates connState);

			int GetFd();
			ConnectionStates GetConnectionState();
			
			void SetFd(int fd);
			void SetConnectionState(ConnectionStates connState);

		private:
			int fd;
			ConnectionStates connState;	
	};
}
