#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * getDateTime()
{
    //当前时间戳
    struct timeval tv;
    struct tm* ptm;
    char  *time_str  = (char*)malloc(sizeof(char)*128);
    memset(time_str,0,128);
    

    //使用函数gettimeofday()函数来得到时间。它的精度可以达到微妙
    gettimeofday(&tv, NULL);

    ptm = localtime(&tv.tv_sec);//把从1970-1-1零点零分到当前时间系统所偏移的秒数时间转换为本地时间
    //strftime() 函数根据区域设置格式化本地时间/日期，函数的功能将时间格式化，或者说格式化一个时间字符串
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", ptm);

    return time_str;
}

int main()
{
    //测试time函数
    time_t curtime;
    time_t time_sec = time(&curtime);
    printf("%lu\n",time_sec);
    //====================================  
    //获取当前时间的字符串
    char *curr_time_str = ctime(&curtime);
    puts(curr_time_str);
    //====================================  
    time_t seconds;
    seconds = time(NULL);
    printf("自1970-01-01 起的小时数:%ld\n",seconds/3600);

    //====================================  
   clock_t start_t, end_t;
   double total_t;
   int i;
    
   start_t = clock();
   printf("程序启动，start_t = %ld\n", start_t);
    
   printf("开始一个大循环，start_t = %ld\n", start_t);
   for(i=0; i< 100000000; i++)
   {
   }
   end_t = clock();
   printf("大循环结束，end_t = %ld\n", end_t);
   
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU 占用的总时间：%f\n", total_t  );



   struct tm t;

   t.tm_sec    = 10;
   t.tm_min    = 20;
   t.tm_hour   = 11;
   t.tm_mday   = 22;
   t.tm_mon    = 9;
   t.tm_year   = 20;
   t.tm_wday   = 5;

   puts(asctime(&t));
 



    

    return 0;
}