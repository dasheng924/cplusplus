#include "library.h"

#include <stdio.h>


//1.注意发送的时候，sendMSG 里面发送的是构造的数据
//2.主要堆内存的释放操作

///////////////////////////////////////////////////
//////////////////// 服务器 ///////////////////////
///////////////////////////////////////////////////
//
int bindSocket(int lfd, unsigned short port)
{
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(lfd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret == -1)
    {
        perror("bind error!");
        return -1;
    }
    return  ret;
}
int setListen(int lfd)
{
    int ret = listen(lfd,128);
    if(ret == -1)
    {
        perror("listen error!");
        return -1;
    }
    return ret;
}

int acceptConn(int lfd, struct sockaddr_in *addr)
{

    socklen_t  len = sizeof(addr);

    int ret = accept(lfd,(struct sockaddr*)&addr,&len);
    if(ret == -1)
    {
        perror("accept error!");
        return -1;
    }
    return ret;
}


///////////////////////////////////////////////////
//////////////////// 客户端 ///////////////////////
///////////////////////////////////////////////////
int connectToHost(int fd, const char* ip, unsigned short port)
{
    struct sockaddr_in caddr;
    caddr.sin_family = AF_INET;
    caddr.sin_port = htons(port);
    inet_pton(AF_INET,ip,&caddr.sin_addr.s_addr);

    int ret = connect(fd,(struct sockaddr*)&caddr,sizeof(caddr));
    if(ret == -1)
    {
        perror("connect error!");
        return  -1;
    }
    return ret;
}


///////////////////////////////////////////////////
///////////////////// 共用 ////////////////////////
///////////////////////////////////////////////////
int createSocket()
{
    int ret = socket(AF_INET,SOCK_STREAM,0);
    if(ret == -1)
    {
        perror("socker error!");
        return -1;
    }
    return ret;
}
int sendMsg(int fd, const char* msg,int len)
{
    if(msg == NULL || len <=0 )
    {
        perror("input error!");
        return -1;
    }
    //头部的长度为4个字节
    //也即是 这四个字节用来放这个发送内容的长度
    char * data = (char *)malloc(len+4);
    if(data == NULL)
    {
        perror("malloc error!");
        return -1;
    }
    printf("转换之前:%s-->%d\n",__FUNCTION__ ,len);
    int bigLen = htonl(len);
    printf("转换之后的%s-->bigLen = %d\n",__FUNCTION__ ,bigLen);
    memcpy(data,&bigLen,4); //首部4个字节存放的是发送内容的长度
    memcpy(data+4,msg,len);//其余的位置是发送的内容

    int ret = writen(fd,data,len+4);

    free(data);
    return ret;
}

#if 0
int recvMsg(int fd, char** msg)
{
    //接受内容，解析出长度
    if(msg == NULL)
    {
        return -1;
    }
    //读数据头
    int len = 0;
    readn(fd,(char*)&len,4); //长度这一块的四个字节已经被读走了
    len = ntohl(len);
    printf("数据块的大小:%d\n",len);

    //根据读出的长度分配内存
    char *data = malloc(len+1);
    if(data == NULL)
    {
        return -1;
    }
    int ret = readn(fd,data,len); //这次读的就是要传输的内容
    if(ret == -1  || ret != len)
    {
        return -1;
    }
    data[len]  = '\0';
    *msg = data;
    return ret;
}
#endif

int closeSocket(int fd)
{
    int ret = close(fd);
    if(ret == -1)
    {
        perror("close error!");
        return -1;
    }
    return ret;
}

#if 0
int readn(int fd, char* buf, int size)
{
    if(buf == NULL)
    {
        perror("输入的内容有误！");
        return -1;
    }
    if(size <= 0)
    {
        perror("输入的内容的长度有误！");
        return -1;
    }

    char *p = buf;
    int len  = size;

    while(len > 0)
    {
        int ret = read(fd,p,len);
        if(ret == -1)
        {
            perror("read error!");
            return -1;
        }
        else if(ret ==0)
        {
            continue;
        }
        len-=ret;
        p+=ret;
    }
    return size;
}

#endif
// 接收指定的字节数
// 函数调用成功返回 size
int readn(int fd, char* buf, int size)
{
    int nread = 0;
    int left = size;
    char* p = buf;

    while(left > 0)
    {
        if((nread = read(fd, p, left)) > 0)
        {
            p += nread;
            left -= nread;
        }
        else if(nread == -1)
        {
            return -1;
        }
    }
    return size;
}


// 接收数据
int recvMsg(int fd, char** msg)
{
    if(msg == NULL || fd <= 0)
    {
        return -1;
    }
    // 接收数据
    // 1. 读数据头
    int len = 0;
    readn(fd, (char*)&len, 4);
    len = ntohl(len);
    printf("数据块大小: %d\n", len);

    // 根据读出的长度分配内存
    char *buf = (char*)malloc(len+1);
    int ret = readn(fd, buf, len);
    if(ret != len) 
    {
        return -1;
    }
    buf[len] = '\0';
    strcpy(*msg,buf);

    free(buf);

    return ret;
}




/*
 * fd:通信的文件描述符
 * msg: 要写入的数据
 * size: 要写入的数据的长度
 */

int writen(int fd, const char* msg, int size)
{
    if(msg  == NULL)
    {
        perror("要写入的内容不正确！");
        return -1;
    }
    if(size <= 0)
    {
        perror("写入的数据长度有错误！");
        return -1;
    }

    const char *p = msg;
    int len = size;

    while(len > 0)
    {
        int ret = write(fd,p,len) ;//也就是这个发送的数据不一定是一次就发送你指定的那么多
        if(ret == -1)
        {
            close(fd);
            return -1;
        }
        else if(ret ==0) //表示客户端和服务器之间是断开连接的
        {
            continue;
        }
        p+=ret;
        len-=ret;
    }

    return size;
}






