#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>

typedef	struct	s_client
{
	int	id;
	char	msg[300000];
}	t_client;

t_client	clients[1024];
fd_set		read_set, write_set, current;
// maxfd: current biggest fd; gid: global id counter
int		maxfd = 0, gid = 0;
char		send_buffer[300000], recv_buffer[300000];

void	err(char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, strlen(msg));
	else
		write(STDERR_FILENO, "Fatal error", 11);
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	send_to_all(int except)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != except)
		{
			printf("Sending to fd %d: %s\n", fd, send_buffer);
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				err(NULL);
		}
	}
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		err("Wrong number of arguments");
	struct	sockaddr_in	serveraddr;
	socklen_t		len = sizeof(serveraddr);
	// Socket Creation
	// AF_INET: IPV4 domain
	// SOCK_STREAM: TCP type
	// 0: protocal value for IP
	int	serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd == -1)
		err(NULL);
	// set up maxfd and init client, current, serveraddr
	maxfd = serverfd;
	FD_ZERO(&current);
	FD_SET(serverfd, &current);
	bzero(clients, sizeof(clients));
	bzero(&serveraddr, sizeof(serveraddr));

	// Forcefully attaching socket to desired port
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(av[1]));

	// bind the server to server address and start to listen
	if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0 || listen(serverfd, 3) < 0)
		err(NULL);
	
	printf("Server is listening on port %s...\n", av[1]);

	while (1)
	{
		// copy current_set to read and write set
		read_set = write_set = current;
		// if there is any error, continue to next while loop
		if (select(maxfd + 1, &read_set, &write_set, 0, 0) == -1)
			continue;
		// after select, the fds in read_set will only contain the fds that are "READY" to be read
		// ex. current {3, 4, 5, 6}, read_set {3, 5}, write_set {6}
		// iterate through fds up to maxfds
		for (int fd = 0; fd <= maxfd; fd++)
		{
			// check if current fd is part of read_set, means new fd events awaiting to be read
			if (FD_ISSET(fd, &read_set))
			{
				// Handling new connections if fd is not exits yet, it will be equal to serverfd
				if (fd == serverfd)
				{
					// accept new connection
					int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);
					if (clientfd == -1)
						continue;
					if (clientfd > maxfd)
						maxfd = clientfd;
					clients[clientfd].id = gid++;
					// Add to current connecting fd set
					FD_SET(clientfd, &current);
					sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
					send_to_all(clientfd);
				}
				// Handling client activity
				else
				{
					int	ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
					if (ret <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						send_to_all(fd);
						// Remove from current connecting set
						FD_CLR(fd, &current);
						close(fd);
						bzero(clients[fd].msg, strlen(clients[fd].msg));
					}
					else
					{
						for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
						{
							clients[fd].msg[j] = recv_buffer[i];
							if (clients[fd].msg[j] == '\n')
							{
								clients[fd].msg[j] = '\0';
								sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
								send_to_all(fd);
								bzero(clients[fd].msg, strlen(clients[fd].msg));
								j = -1;
							}

						}
					}
				}
				// The break here make sure each iteration handle only 1 fd. This can keep the current program responsive
				break;
			}
		}
	}
	return (0);
}
