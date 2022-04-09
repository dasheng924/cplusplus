    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>


    int getFiles(char **myP1,int *myLen1,char **myP2,int *myLen2)
    {
        int ret = 0;
        //因为不知道文件的大小,无法在main里面分配内存
        //被调函数里面分配内存

        char *tmp1 = (char*)malloc(100); //分配了一块堆内存
        strcpy(tmp1,"abcdefg");
        *myLen1 = 100;//一级指针间接赋值
        *myP1 = tmp1; //二级指针的间接赋值,*myP1实际上就是main中myP1内存块的值,保存的还是一块内存的地址

        char *tmp2 = (char*)malloc(200);
        strcpy(tmp2,"12345678");
        *myLen2 = 200;//一级指针间接赋值
        *myP2 = tmp2; //二级指针的间接赋值 //相当于main中的myP2指向了这块堆内存

        
        return ret;
    }


    int main(void)
    {
        char *myP1 = NULL;
        int myLen1 = 0;
        char *myP2 = NULL;
        int myLen2 = 0;

        int ret = getFiles(&myP1,&myLen1,&myP2,&myLen2);
        if(ret != 0)
        {
            printf("func getFiles error:%d\n",ret);
        }

        printf("myP1:%s\n",myP1);
        printf("myP2:%s\n",myP2);

        if(myP1 != NULL)
        {
            free(myP1);
            myP1 = NULL;
        }

        if(myP2 != NULL)
        {
            free(myP2);
            myP2 = NULL;
        }


        return ret;
    }