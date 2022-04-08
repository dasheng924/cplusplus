#include "err_sock.h"
void perror_exit(const char *str)
{
	perror(str);
	exit(1);
}

int Socket(int domain, int type, int protocol)//传输类型，协议类型，默认协议
{
	int fd;
	if((fd = socket(domain,type,protocol)) == -1)
		perror_exit("socket error");

	return fd;
}

int Bind(int sockfd, const struct sockaddr* addr,socklen_t addrlen)
{
	int ret;
	if((ret = bind(sockfd,addr,addrlen)) == -1)
		perror_exit("bind error");

	return ret;
}
int Listen(int fd,int backlog)
{
	int n;
	if((n = listen(fd,backlog)) ==-1)
		perror_exit("listen error");
	return n;
}
int Accept(int sockfd,struct sockaddr * addr, socklen_t *addrlen)
{
	int newfd;
again:
	if((newfd = accept(sockfd,addr,addrlen)) == -1)
	{
		if((errno == ECONNABORTED)  || (errno == EINTR))
			goto again;
		else
			perror_exit("accept error");
	}

	return newfd;
}

int Connect(int fd,const struct sockaddr*sa,socklen_t salen)
{
	int n;
	if((n = connect(fd,sa,salen)) == -1)
			perror_exit("connect error");

	return n;

}

size_t Read(int fd,void *ptr,size_t nbytes)
{
	size_t n;
again:
	if((n = read(fd,ptr,nbytes)) == -1)
	{
		if(errno == EINTR)
			goto again;
		else
			return -1;

	}

	return n;

}

size_t Write(int fd,const void *ptr,size_t nbytes)
{
	size_t n;
again:
	if((n=write(fd,ptr,nbytes)) == -1)
	{
		if(errno == EINTR)
			goto again;
		else
			return -1;
	}
	return n;
}

int Close(int fd)
{

	int n;
	if((n= close(fd)) == -1)
		perror_exit("close err");

	return n;
}

ssize_t Readn(int fd,void *vptr,size_t n)//指定要读的字节数
{
	size_t nleft;//还剩多少字节没读
	ssize_t nread;
	char *ptr;

	ptr = vptr;//定位到buf的开头

	nleft = n;//开始的时候，剩下的就等于全部

	while(nleft > 0)//大于0表示还有没读够
	{

		if((nread = read(fd,ptr,nleft)) < 0)//若读到的值小于0，表示读的有错误
		{
			if(errno == EINTR)
				nread = 0;
			else
				return -1;
		}
		else if(nread == 0)//若等于0，表示读到文件末尾或对端关闭
			break;

		nleft -= nread;//计算出剩余的字节数
		ptr += nread;//指针向后偏移
	}
	
	return n-nleft;//返回没有读完的字节数
}


ssize_t Writen(int fd,const void * vptr,size_t n)
{
	size_t nleft;
	ssize_t nwrite;
	const char *ptr;

	ptr = vptr;
	nleft = n;

	while(nleft > 0)
	{
		if((nwrite = write(fd,ptr,nleft)) < 0)
		{
			if(nwrite < 0 && errno == EINTR)
				nwrite = 0;
			else
				return -1;
		}
		nleft -= nwrite;
		ptr += nwrite;
	}

	return n;
}





