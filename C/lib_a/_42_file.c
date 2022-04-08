#include <stdio.h>
#include <stdlib.h>

void test01()
{
    FILE * fp = fopen("./_42_test.txt","r");
    if(NULL == fp)
    {
        perror("file open fail!");
        return;
    }

    char ch;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if(feof(fp))  //最后的位置会有一个EOF
            break;
        printf("%c",ch);
    }

    fclose(fp) ;


}

int main(void)
{
    test01() ;
   // printf("%c",EOF) ;
    //printf("%c",-1);

    



    return 0;
}