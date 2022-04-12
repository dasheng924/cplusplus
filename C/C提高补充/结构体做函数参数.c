#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
    char name[64];
    int age;
    int id;
} Teacher;

void show(Teacher *t, int num)
{
    for (int i = 0; i < num; ++i)
    {
        printf("%s %d %d\n", t[i].name, t[i].age, t[i].id);
    }
}

void swap(Teacher *t1, Teacher *t2)
{
    Teacher tmp;
    tmp = *t1;
    *t1 = *t2;
    *t2 = tmp;
}

void ageSoft(Teacher *arr, int num)
{
    Teacher tmp;
    for (int i = 0; i < num; ++i)
    {
        for (int j = i + 1; j < num; ++j)
        {
            if (arr[i].age < arr[j].age)
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

Teacher *createTeacher(int num)
{
    Teacher *tmp = NULL;
    tmp = (Teacher *)malloc(sizeof(Teacher) * num);
    if (tmp == NULL)
        return NULL;
    return tmp;
}

void feeeTeacher(Teacher *p)
{
    if (p != NULL)
    {
        free(p);
    }
}

int main(void)
{

    Teacher arr[3] = {
        {"alex", 22, 12},
        {"lucy", 28, 13},
        {"perr", 21, 14}};
    int num = 3;

    Teacher *pp = createTeacher(num);
    for (int i = 0; i < num; ++i)
    {
        sprintf(pp[i].name, "%d%d%d", i, i, i);
        pp[i].age = i * 10 + 10;
        pp[i].id = i;
    }

    show(pp, num);

    //打印arr
    show(arr, num);

    //对age进行排序
    ageSoft(arr, num);
    show(arr, num);

    feeeTeacher(pp);

    return 0;
}