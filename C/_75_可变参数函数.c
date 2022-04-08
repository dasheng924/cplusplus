#include <stdio.h>
#include <stdarg.h>

//可变参数求平均值

double average(int num,...)
{
    va_list va;
    int sum = 0;

    va_start(va,num);
    for(int i = 0;i< num;++i)
    {
        sum+= va_arg(va,int);
    }

    va_end(va);

    return sum/num;
}

int sum(int count,...)
{
    va_list ap;
    int sum = 0;

    va_start(ap,count);

    for(int i = 0;i<count;++i)
    {
        sum += va_arg(ap,int);
    }

    va_end(ap);

    return sum;
}

int main()
{
    double ret = average(4,1,33,2,10);
    printf("%lf\n",ret);

    int sumNum = sum(3,10,23,100);
    printf("sum = %d \n",sumNum);

    return 0;
}