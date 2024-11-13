/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:32:45 by tsuchen           #+#    #+#             */
/*   Updated: 2024/11/12 09:55:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

typedef struct  s_client
{
    int         id;
    char        msg[300000];
}   t_client;

t_client    clients[1024];
fd_set      read_set, write_set, current;
int         maxfd = 0;
int         gid = 0;
char        send_buffer[300000];
char        recv_buffer[300000];

void    err(char *msg)
{
    if (msg)
        write(STDERR_FILENO, msg, strlen(msg));
    else
        write(STDERR_FILENO, "Fatal error", 11);
    write(STDERR_FILENO, "\n", 1);
    exit(1);
}

void    send_to_all(int except)
{
    for (int fd = 0; fd <= maxfd; fd++)
    {
        if (FD_ISSET(fd, &write_set) && fd != except)
        {
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
                err(NULL);
        }
    }
}

int main(int ac, char *av[])
{
    if (ac != 2)
        err("Wrong number of arguments");
    struct sockaddr_in  serveraddr;
    socklen_t           len = sizeof(serveraddr);
    
    int     serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1)
        err(NULL);
    
    FD_ZERO(&current);
    FD_SET(serverfd, &current);
    bzero(clients, sizeof(clients));
    bzero(&serveraddr, sizeof(serveraddr));
    
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(av[1]));

    //bind and listen
    if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
        err(NULL);
    if (listen(serverfd, 100) < 0)
        err(NULL);
    
    while (1)
    {
        read_set = write_set = current;
        if (select(maxfd + 1, &read_set, &write_set, 0, 0) < 0)
            continue;
        for (int fd = 0; fd <= maxfd; fd++)
        {
            if (FD_ISSET(fd, &read_set))
            {
                if (fd == serverfd)
                {
                    int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);
                    if (clientfd == -1)
                        continue;
                    if (clientfd > maxfd)
                        maxfd = clientfd;
                    clients[clientfd].id = gid++;
                    FD_SET(clientfd, &current);
                    sprintf(send_buffer, "")
                }
            }
        }
    }
}