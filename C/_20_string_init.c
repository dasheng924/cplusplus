#include <stdio.h>
#include <string.h>




int MyCpy(char *dest,char * src)
{

	if(dest == NULL || src == NULL)
		return -1;
	int len = strlen(src);
	int i = 0;
	for(i = 0;i<len;++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return 1;
}
int MyCpy2(char * dest,char *src)
{
	if(dest == NULL || src == NULL)
		return -1 ;
	char * tmp = dest ;
	int len = strlen(src) ;
	int i = 0;
	for(i = 0;i<len;++i)
		*(tmp+i) = *(src+i);
	*(tmp+i) = '\0';
	return 1;
}
void MyCpy3(char *dest,const char * src)
{
	while(*src != '\0')
	{
		*dest = *src ;
		++dest;
		++src;
		*dest = '\0';
	}


}
void MyCpy4(char *dest,const char * src)
{
	while((*dest++ = *src++)) ;
}

void reserveStr(char * p)
{
	if(NULL == p)
		return ;
	int start = 0;
	int end = strlen(p)- 1 ;
	while(start < end)
	{
		char tmp = p[start];
		p[start] = p[end];
		p[end] = tmp ;
		++start;
		--end;
	}
}




int main(void)
{
#if 0
	char str1[] = {'h','e','l','l','o'};
	char str2[32] = {'h','e','l','l','o'};
	char str3[
	] = {"hello"} ;


	printf("%s\n",str1);
	printf("%s\n",str2);
	printf("%s\n",str3);


	printf("strlen(str1) = %lu\n",strlen(str1));
	printf("strlen(str2) = %lu\n",strlen(str2));
	printf("strlen(str3) = %lu\n",strlen(str3));

	printf("sizeof(str1) = %zu\n",sizeof(str1));
	printf("sizeof(str2) = %zu\n",sizeof(str2));
	printf("sizeof(str3) = %zu\n",sizeof(str3));
#endif



#if 1

	char *str1 = "hello";
	char buf[1024]  = {0};
#if 0
	MyCpy(buf,str1);

	printf("strlen(str1) = %lu\n",strlen(str1));
	printf("%s\n",buf);
#endif

#if 1
	MyCpy4(buf,str1);
	printf("%s\n", buf);

	reserveStr(buf);
	printf("%s\n",buf);
#endif
#endif


	return 0;
}