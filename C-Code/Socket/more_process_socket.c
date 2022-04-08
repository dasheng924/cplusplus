#include "err_sock.h"
#define PORT 9999


void func(int signum)
{
	while(waitpid(0,NULL,WNOHANG) > 0);
	return ;
}

int main()
{
	pid_t pid;
	int n,i;
	char buf[BUFSIZ];

	int ser_fd,cli_fd;

	//create socket
	ser_fd = Socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in ser_addr,cli_addr;
	socklen_t cli_addr_len;

	bzero(&ser_addr,sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(PORT);
	ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(ser_fd,(struct sockaddr*)&ser_addr,sizeof(ser_addr));

	Listen(ser_fd,128);

	while(1)
	{
		cli_addr_len = sizeof(cli_addr);
		cli_fd = Accept(ser_fd,(struct sockaddr*)&cli_addr,&cli_addr_len);

		pid = fork();
		if(pid == -1)
			perror_exit("fork error");
		else if(pid == 0)
		{
			close(ser_fd);
			break;
		}
		else if(pid > 0)
		{
			close(cli_fd);
			signal(SIGCHLD,&func);
		}
	}

	if(pid == 0)
	{
		char str[80];
		while(1)
		{

			printf("receive from %s at port: %d\n",inet_ntop(AF_INET,&cli_addr.sin_addr.s_addr,str,sizeof(str)),ntohs(cli_addr.sin_port));

			n = Read(cli_fd,buf,sizeof(buf));
			printf("%d-----%s\n",n,buf);
			for(i = 0;i<n;i++)
				buf[i] = toupper(buf[i]);
			Write(cli_fd,buf,n);
		}
	}




	return 0;
}