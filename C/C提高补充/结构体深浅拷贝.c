#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
    int id;
    int age;
    char *pName;
} Teacher;

//浅拷贝
int copy(Teacher *from, Teacher *to)
{
    *to = *from;
    return 0;
}

//深拷贝
//主要针对的是结构体里面套指针
int deepCopy(Teacher *from, Teacher *to)
{

    to->pName = (char *)malloc(100);
    strcpy(to->pName, from->pName);
    to->id = from->id;
    to->age = from->age;

    return 0;
}

int main(void)
{
    Teacher t1;
    Teacher t2;

    t1.id = 1;
    t1.age = 33;
    t1.pName = (char *)malloc(sizeof(char) * 100);
    if (t1.pName == NULL)
    {
        return -1;
    }
    strcpy(t1.pName, "sss");

    deepCopy(&t1, &t2);

    printf("id = %d\n", t2.id);
    printf("age = %d\n", t2.age);
    printf("name = %s\n", t2.pName);

    if (t1.pName != NULL)
    {
        free(t1.pName);
        t1.pName = NULL;
    }

    if (t2.pName != NULL)
    {
        free(t2.pName);
        t2.pName = NULL;
    }

    return 0;
}