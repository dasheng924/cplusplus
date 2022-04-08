#include <iostream>
#include <cstring>

using namespace std;

void*my_memcpy(void *dst, const void *src, size_t size)
{
    char *psrc;
    char *pdst;

    if(NULL == dst || NULL == src)
    {
        return NULL;
    }

    if((src < dst) && (char *)src +size > (char *)dst) // 自后向前拷贝
    {
        psrc = (char *)src + size - 1;
        pdst = (char *)dst + size - 1;
        while(size--)
        {
            *pdst-- = *psrc--;
        }
    }
    else
    {
        psrc = (char *)src;
        pdst = (char *)dst;
        while(size--)
        {
            *pdst++ = *psrc++;
        }
    }

    return dst;
}

void show(const char *buf)
{
    if(buf == nullptr)
        return;

    for(int i  = 0; i < static_cast<int>(strlen(buf));++i)
    {
        cout<<*(buf+i)<<" ";

    }
    cout<<endl;

}


int main()
{
    char src_buf[15];
    memset(src_buf,0,sizeof (src_buf));

    char dest_buf[15];
    memset(dest_buf,0,sizeof (dest_buf));

    for(int i = 0;i<15;++i)
    {
        src_buf[i] = 'a'+i;
    }

    show(src_buf);//a b c d e f g h i j k l m n o

    //不同的buf赋值
    //show(static_cast<char*>(my_memcpy(dest_buf,src_buf,10)));

    //向后赋值
    //show(static_cast<char*>(my_memcpy(src_buf+4,src_buf+3,3)));//d e f h i j k l m n o

    //向前赋值
    //show(static_cast<char*>(my_memcpy(src_buf+3,src_buf+4,3)));//e f g g h i j k l m n o

    //向后赋值
    //show(static_cast<char*>(memmove(src_buf+4,src_buf+3,3)));//d e f h i j k l m n o

    //向前赋值
    //show(static_cast<char*>(memmove(src_buf+3,src_buf+4,3)));//e f g g h i j k l m n o




    return 0;
}
