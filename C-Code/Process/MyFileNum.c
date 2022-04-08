/*************************************************************************
	> File Name: MyFileNum.c
	> Created Time: 日  3/ 1 14:30:51 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int GetFileNum(char * root)
{
	if(NULL == root)//判断输入是否为空
	{
		printf("输入为空\n");
		exit(1);
	}
	//open dir
	DIR * dir = NULL;//opendir()函数返回的是目录指针
	dir = opendir(root);
	if(dir == NULL)
	{
		perror("opendir");
		exit(1);
	}
	
	//遍历当前打开的目录
	struct dirent* ptr = NULL;
	char path[1024] = {0};
	int total = 0;
	while((ptr = readdir(dir)) != NULL)//readdir()函数返回的是一个目录结构体，d_type d_name
	{
		//过滤. ..
		if(strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0)
		{
			continue;
		}
		//如果是目录
		if(ptr->d_type == DT_DIR)
		{
			//递归读目录
			sprintf(path,"%s/%s",root,ptr->d_name);
			total += GetFileNum(path);
		}
		//如果是普通文件
		if(ptr->d_type == DT_REG)
		{
			total++;
		}
	}

	int ret = closedir(dir);
	if(-1 == ret)
	{
		perror("closedir fail");
		exit(1);
	}

	return total;

}

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		perror("./ is not ok");
		exit(1);
	}
	int totals = GetFileNum(argv[1]);
	printf("%s all dir is %d\n",argv[1],totals);
	return 0;
}
