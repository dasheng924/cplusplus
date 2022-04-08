/*
   1.sicket(),bind(),listen();
   2.epoll_create(),epoll_ctl();
   3.while(1){epoll_wait();判断是否是accept，还是read;}
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/epoll.h>//epoll在Linux中才有效，在Mac里无效
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 9999
#define MAXLINE 8000
#define OPENMAX 5000
#define IPLEN 64

int main()
{
	
	int sfd;//保存socket 返回值
	int opt = 1;//保存setsockopt 参数
	struct sockaddr_in saddr,caddr;//保存服务器地址，客户端地址
	int efd;//保存epoll_create 返回值
	int e_ctl;//保存epoll_ctl 返回值
	struct epoll_event even;//epoll_ctl 参数，结构体里保存对应事件EPOLLIN和需要监控的文件描述符
	int e_wait;//保存epoll_wait 返回值
	struct epoll_event event[OPENMAX];//epoll_wait 参数，对应是保存结构体的数组
	int i;//循环因子
	socklen_t caddrlen;//保存IP的数组长度
	int connfd;//accept后返回的新的文件描述符
	char str_ip[IPLEN];//保存IP的数组
	int num = 0;//计数客户端的编号
	int sockfd;//保存发送数据客户端的文件描述符 socket = event[i].data.fd;
	int n_read;//从客户端哪读到的字节数
	char buf[MAXLINE];//保存读到数据的buf




	sfd = socket(AF_INET,SOCK_STREAM,0);//socket 
	setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));//opt sock
	bzero(&saddr,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sfd,(struct sockaddr*)&saddr,sizeof(saddr));
	listen(sfd,20);

	efd = epoll_create(OPENMAX);//使用epoll的第一步，创建一颗红黑树，efd 为根节点
	if(efd == -1)
	{
		perror("epoll_create error");
		exit(1);
	}
	even.events = EPOLLIN;//epoll_ctl 参数分支
	even.data.fd = sfd;

	e_ctl = epoll_ctl(efd,EPOLL_CTL_ADD,sfd,&even);//1.epoll_create 返回值  2.添加动作 3.需要添加的文件描述符
	//4.该文件描述符需要监测的对应事件 EPOLLIN  / EPOLLOUT  /  EPOLLERR
	if(e_ctl == -1)
	{
		perror("epoll_ctl error");
		exit(1);
	}
	while(1)
		{
			e_wait = epoll_wait(efd,event,OPENMAX,-1);//对添加进去的文件描述符进行监测和返回
//1.根节点  2.传出参数，把发生变化的文件描述符传出（结构体数组）   3.数组长度   4.超时设置，阻塞返回
			if(e_wait == -1)//error
			{
				perror("epoll_wait error");
				exit(1);
			}
			for(i = 0;i<e_wait;i++)//循环取出每个事件
			{
				if(!(event[i].events & EPOLLIN))//若不是读事件，就跳过本次循环，下一次循环
					continue;
				if(event[i].data.fd == sfd)//若对应的是读事件，又是一个sfd，那肯定是一个accept 连接请求
				{
					caddrlen = sizeof(caddr);
					connfd = accept(sfd,(struct sockaddr*)&caddr,&caddrlen);//accept
					printf("receive from %s at PORT %d \n",inet_ntop(AF_INET,&caddr.sin_addr.s_addr,str_ip,sizeof(str_ip)),ntohs(caddr.sin_port));//print -IP -PORT
					printf("cfd %d-----client %d\n",connfd,++num);//num 
					even.events = EPOLLIN;
					even.data.fd = connfd;
					e_ctl = epoll_ctl(efd,EPOLL_CTL_ADD,connfd,&even);//把新出来的connfd 也加入监听
					if(e_ctl == -1)
					{
						perror("new epoll_ctl error");
						exit(1);
					}


				}
				else
				{
					sockfd = event[i].data.fd;//数据交互的fd
					n_read = read(sockfd,buf,MAXLINE);
					if(n_read == 0)//读到的字节数为0，表示该文件描述符对应的客户端关闭
					{
						e_ctl = epoll_ctl(efd,EPOLL_CTL_DEL,sockfd,NULL);//取消该节点的监听
						if(e_ctl == -1)
						{
							perror("close epoll_ctl error");
							exit(1);
						}
						close(sockfd);//关闭该客户端
						printf("client [%d] closed connection\n",sockfd);//提示该客户端关闭

					}
					else if(n_read < 0)//error
					{
						perror("read n< 0 error");
						exit(1);
						close(sockfd);
					}
					else//作对应数据交互
					{
						for(i = 0;i<n_read;i++)
						{
							buf[i] = toupper(buf[i]);
						}
						write(STDOUT_FILENO,buf,n_read);
						write(sockfd,buf,n_read);
					}


				}
			}
		}
	close(sfd);
	close(efd);

	return 0;
}