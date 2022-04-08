#include <stdio.h>
#include <string.h>
#include <stdlib.h>






int main(void)
{

	
#if 0
	char *str = "2343vvbgrbdvgbg" ;

	char buf[1024] = {0} ;
	sscanf(str,"%*d%s",buf) ; //%*d 这个意思是跳过数字，直接把数字后面的字符串赋值给buf，要以数字开头


	puts(buf) ;

#endif

#if 0
	//------
	//%*s 忽略的是字符串，但是如果没有隔开，整个都是字符串
	char * str1 = "wdeee778" ;

	memset(buf,0,sizeof(buf)) ;
	
	sscanf(str1,"%*s%s",buf) ; //这样忽略的话，整个buf的结果就为空，要有一定的间隔，比如
	
	puts(buf);
#endif

#if 0
	//获取数字整个需要字符和数字之间是分割开的"
	char *str2 = "dedfef 839" ;
	int num = 0 ;
	sscanf(str2,"%*s%d",&num) ;
	printf("%d\n",num) ;
#endif

#if  0

	char *str3 = "cverv\t34r4343"; //忽略前半部分的字符串
	char buf[1024] = {0} ;
	memset(buf,0,sizeof(buf)) ;
	sscanf(str3,"%*s%s",buf) ;

	puts(buf) ;

#endif


#if 0

//%[width]s --指定读取字符的宽度
	
	char * str = "dedff9fe3f3" ;

	char buf[1024] = {0}; 

	sscanf(str,"%6s",buf) ;//指定读取的宽度

	printf("%s -->%lu\n",buf,strlen(buf)) ;

	memset(buf,0,sizeof(buf)) ;
	sscanf(str,"%[a-z]",buf) ;
	puts(buf);

	//sscanf(str,"%[de]",buf) ;
	//sscanf(str,"%[^d]",buf);
	//sscanf(str,"%[^0-9]",buf) ;



#endif

#if 0

	char *p = "name:alex age:23" ;
	char name[32] = {0} ;
	char age[32] = {0} ;

	sscanf(p,"name:%s age:%s",name,age) ;//两个字符串之间有空格，全部都用%s来获取

	puts(name);	//alex,age:23
					

	puts(age) ;


#endif


#if 1

	char *str = "abcde#12uiop@p1ju" ;
	char buf[1024] = {0} ;
	//sscanf(str,"abcde#%6s",buf) ;

	//sscanf(str,"%*[^#]#%[^@]",buf);
	sscanf(str,"%*[^#]#%[^@]",buf);//注意一旦匹配到符合规则的就会截止，不会继续走下去，[^#] 一旦匹配到#就结束往后的匹配
	puts(buf) ;

#endif




		return 0;
}