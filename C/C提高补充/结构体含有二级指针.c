#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
    char name[64];
    char *aliasName;     //包含一级指针
    char **pStudentName; //包含二级指针
    int age;
    int id;
} Teacher;

//需要为aliasName也分配一块内存
int createTeacher(Teacher **p, int num, int studentNum)
{
    if (p == NULL)
        return -1;
    Teacher *tmp = (Teacher *)malloc(sizeof(Teacher) * num);
    if (tmp == NULL)
        return -1;

    int i = 0;
    for (; i < num; ++i)
    {
        tmp[i].aliasName = (char *)malloc(sizeof(char) * 100);
        if (tmp[i].aliasName == NULL)
        {
            return -1;
        }
        memset(tmp[i].aliasName, 0, 100);

        tmp[i].pStudentName = (char **)malloc(sizeof(char *) * studentNum);
        if (tmp[i].pStudentName == NULL)
            return -1;

        for (int j = 0; j < studentNum; ++j)
        {
            tmp[i].pStudentName[j] = (char *)malloc(sizeof(char) * 100);
            if (tmp[i].pStudentName[j] == NULL)
                return -1;
        }
    }

    *p = tmp;
    return 0;
}

int freeteacher(Teacher **p, int num, int studentNum)
{
    if (p == NULL)
        return -1;
    int i = 0;
    Teacher *tmp = NULL;
    tmp = *p;
    for (; i < num; ++i)
    {
        for (int j = 0; j < studentNum; ++j)
        {
            if (tmp[i].pStudentName[j] != NULL)
            {
                free(tmp[i].pStudentName[j]);
                tmp[i].pStudentName[j] = NULL;
            }
        }

        if (tmp[i].pStudentName != NULL)
        {
            free(tmp[i].pStudentName);
            tmp[i].pStudentName = NULL;
        }

        if (tmp[i].aliasName != NULL)
        {
            free(tmp[i].aliasName);
        }
    }
    free(tmp);
    return 0;
}

void show(Teacher **p, int num, int studentNum)
{
    if (p == NULL)
        return;
    int i = 0;
    Teacher *tmp = *p; //*p就到了分配的内存起始位置
    for (; i < num; ++i)
    {
        printf("name:%s\n", tmp[i].name);
        printf("aliasName:%s\n", tmp[i].aliasName);
        for (int j = 0; j < studentNum; ++j)
        {
            printf("    %s\n", tmp[i].pStudentName[j]);
        }
        printf("age:%d\n", tmp[i].age);
        printf("id:%d\n", tmp[i].id);
    }
}

int main(void)
{
    Teacher *pp = NULL;
    int num = 3;
    int studentNum = 5;
    int i = 0;
    int ret = createTeacher(&pp, num, studentNum);
    if (ret == -1)
    {
        printf("createTeacher() error:%d\n", ret);
        return ret;
    }

    for (; i < num; ++i)
    {
        strcpy(pp[i].name, "name");
        sprintf(pp[i].aliasName, "name%d%d%d", i, i, i);
        for (int j = 0; j < studentNum; ++j)
        {
            sprintf(pp[i].pStudentName[j], "studentName%d", i);
            // strcpy(pp[i].pStudentName[j],"student-name");
        }
        pp[i].age = i * 10 + 10;
        pp[i].id = i;
    }

    show(&pp, num, studentNum);
    freeteacher(&pp, num, studentNum);
    return 0;
}
