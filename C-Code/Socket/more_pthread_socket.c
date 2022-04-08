#include "err_sock.h"

#define PORT 1000
#define MAX 1024
#define STR_LEN 64

struct cli_info
{
	struct sockaddr_in client_addr;
	int client_fd;
};

void * func(void *arg)
{

	struct cli_info *info = (struct cli_info*)arg;

	char buf[MAX];
	char str[STR_LEN];
	while(1)
	{
		int n = Read(info->client_fd,buf,MAX);
		if(n == 0)
		{
			printf("client %d close\n",info->client_fd);
			break;
		}
		printf("%s receive at %d port\n",
				inet_ntop(AF_INET,&info->client_addr.sin_addr.s_addr,str,sizeof(str)),
				ntohs(PORT)
			  );
		for(int i = 0;i<n;i++)
		{
			buf[i] = toupper(buf[i]);
		}
		Write(STDOUT_FILENO,buf,n);
		Write(info->client_fd,buf,n);
	}
	Close(info->client_fd);
	return (void *)0;
}
int main()
{
	int sfd,cfd;
	int i = 0;//保存线程的个数
	struct cli_info cinfo[1024];//1024个线程的最大值
	socklen_t caddr_len;

	pthread_t tid;
	pthread_attr_t attr;


	sfd = Socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in saddr,caddr;
	bzero(&saddr,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(sfd,(struct sockaddr*)&saddr,sizeof(saddr));

	Listen(sfd,128);

	while(1)
	{
		caddr_len = sizeof(caddr);
		cfd = Accept(sfd,(struct sockaddr*)&caddr,&caddr_len);

		cinfo[i].client_addr = caddr;
		cinfo[i].client_fd = cfd;

		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
		int rett = pthread_create(&tid,NULL,func,(void *)&cinfo[i]);
		if(rett != 0)
		{
			fprintf(stderr,"pthread_create error %s\n",strerror(rett));
			exit(1);
		}	
		//pthread_detach(tid);

		pthread_attr_destroy(&attr);

		i++;


	}
	return 0;
}