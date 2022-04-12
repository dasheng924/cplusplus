#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
    char name[64];
    int age;
    int id;
} Teacher;

void copy(Teacher *from ,Teacher *to)
{
    *to = *from;
}

int main(void)
{
    Teacher t1 = {"alex", 22, 12};
    Teacher t2 = t1;

    printf("name = %s\n", t2.name);
    printf("age = %d\n", t2.age);
    printf("id = %d\n", t2.id);

    Teacher t3;
    copy(&t1,&t3);
    printf("name = %s\n", t3.name);
    printf("age = %d\n", t3.age);
    printf("id = %d\n", t3.id);


    return 0;
}