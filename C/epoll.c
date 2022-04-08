#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
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
	
    int epfd = epoll_create(100);
    if(epfd == -1)
    {
        perror("epoll_create fail!");
        exit(-1);

    }

    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = sfd;

    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);
    if(ret == -1)
    {
        perror("epoll_ctl fail!");
        exit(-1);
    }




    struct epoll_event evs[1024] ;
    int size = sizeof(evs)/sizeof(evs[0]);

	while(1)
	{
		
		int num = epoll_wait(epfd,evs,size,-1);
		if(num == -1)
		{
			perror("epoll fail!");
			exit(-1);
		}


        for(int i = 0;i<num;++i)
        {
            int curfd = evs[i].data.fd;
            if(curfd == sfd)
            {
                int cfd = accept(curfd,NULL,NULL);
                if(cfd == -1)
                {
                    perror("accept error!");
                    exit(-1);
                }

                ev.events = EPOLLIN;
                ev.data.fd = cfd;
                int ret = epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&ev);
                if(ret == -1)
                {
                    perror("epoll_ctl add cfd fail!");
                    exit(-1);
                }
                
            }
            else{
                char recv_buf[1024];
				bzero(recv_buf,1024);

				int len = recv(curfd,recv_buf,sizeof(recv_buf),0);
				if(len == 0)
				{
					epoll_ctl(epfd,EPOLL_CTL_DEL,curfd,NULL);
					close(curfd);
				}	
				else if(len > 0)
				{
					for(int i = 0;i<len;++i)
					{
						recv_buf[i] = toupper(recv_buf[i]);
					}
					send(curfd,recv_buf,sizeof(recv_buf),0);

				}
				else{
					close(curfd);
					exit(-1);
				}
            }

        }

    }
   
	close(sfd);

	exit(0);
}
