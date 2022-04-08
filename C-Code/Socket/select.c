#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>

#define PORT 9999
#define MAXBUF 1024
int main()
{
	fd_set rset;
	int fds[5];
	int max = 0;
	char buffer[MAXBUF];
	int i = 0,n,j;
	int opt = 1;

	int sfd,cfd;
	socklen_t  addrlen;
	sfd = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in saddr,caddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sfd,(struct sockaddr *)&saddr,sizeof(saddr));
	setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	listen(sfd,5);


	for(i = 0;i< 5;i++)
	{
		memset(&caddr,0,sizeof(caddr));
		addrlen = sizeof(caddr);
		fds[i] =  accept(sfd,(struct sockaddr*)&caddr,&addrlen);
		if(fds[i] > max)
		{
			max = fds[i];
		}
	}

	while(1)
	{
		FD_ZERO(&rset);
		for(i = 0;i<5;i++)
		{
			FD_SET(fds[i],&rset);
		}

		puts("round again");

		select(max+1,&rset,NULL,NULL,NULL);

		for(i = 0;i < 5;i++)
		{
			if(FD_ISSET(fds[i],&rset))
			{
				memset(buffer,0,MAXBUF);
				n = read(fds[i],buffer,MAXBUF);
				for(j = 0;j<n;j++)
				{
					buffer[i] = toupper(buffer[i]);
				}
				write(fds[i],buffer,n);
			}
				
		}
	}

	for(i = 0;i< 5;i++)
		close(fds[i]);

	return 0;
}