#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/poll.h>
#include <ctype.h>

int main()
{
	
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd == -1)
	{
		perror("socket error!");
		exit(-1);
	}
	int ok =1;
	setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&ok,sizeof(ok));

	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8888);
	saddr.sin_addr.s_addr = INADDR_ANY;
	//inet_pton(AF_INET,"127.0.0.1",&saddr.sin_addr.s_addr);

	int ret = bind(sfd,(struct sockaddr*)&saddr,sizeof(saddr));
	if(ret == -1)
	{
		perror("bind error!");
		exit(-1);
	}
	ret = listen(sfd,128);
	if(ret == -1)
	{
		perror("listen error!");
		exit(-1);
	}
	
	struct pollfd fds[1024];
	for(int i = 0;i<1024;++i)
	{
		fds[i].fd = -1;
		fds[i].events = POLLIN;
	}
	fds[0].fd = sfd;
	int maxfd = 0;

	while(1)
	{
		
		int num = poll(fds,maxfd+1,3);
		if(num == -1)
		{
			perror("poll fail!");
			exit(-1);
		}

		//new connect
		if(fds[0].revents & POLLIN)
		{
			
			//accept 
			struct sockaddr_in caddr;
			socklen_t len = sizeof(caddr);
			int cfd = accept(fds[0].fd,(struct sockaddr*)&caddr,&len);
			
			if(cfd == -1)
			{
				
				perror("accept fail!");
				exit(-1);
			}
			
			for(int i = 0;i<1024;++i)
			{
				if(fds[i].fd == -1)
				{
					fds[i].fd = cfd;
					break;
				}
			}

			maxfd = cfd>maxfd?cfd:maxfd;
		}

		for(int i = 1;i<maxfd+1;++i)
		{
			
			if(fds[i].revents & POLLIN)
			{
				
				char recv_buf[1024];
				bzero(recv_buf,1024);

				int len = recv(fds[i].fd,recv_buf,sizeof(recv_buf),0);
				if(len == 0)
				{
					
					close(fds[i].fd);
					fds[i].fd = -1;
				}	
				else if(len > 0)
				{
					for(int i = 0;i<len;++i)
					{
						recv_buf[i] = toupper(recv_buf[i]);
					}
					send(fds[i].fd,recv_buf,sizeof(recv_buf),0);

				}
				else{
					close(fds[i].fd);
					exit(-1);
				}


			}
		}

	




	}

	close(sfd);

	exit(0);
}
