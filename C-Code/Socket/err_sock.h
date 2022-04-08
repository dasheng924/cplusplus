#ifndef _ERR_H_
#define _ERR_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <strings.h>
#include <pthread.h>
void perror_exit(const char *str);
int Socket(int domain, int type, int protocol);//传输类型，协议类型，默认协议

int Bind(int sockfd, const struct sockaddr* addr,socklen_t addrlen);


int Listen(int fd,int backlog);



int Accept(int sockfd,struct sockaddr * addr, socklen_t *addrlen);


int Connect(int fd,const struct sockaddr*sa,socklen_t salen);


size_t Read(int fd,void *ptr,size_t nbytes);
size_t Write(int fd,const void *ptr,size_t nbytes);
int Close(int fd);
ssize_t Readn(int fd,void *vptr,size_t n);//指定要读的字节数
ssize_t Writen(int fd,const void * vptr,size_t n);
#endif

