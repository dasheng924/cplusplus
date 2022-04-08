#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int getlines(FILE * fp) 
{
	
	if(fp == NULL)
		perror("open file fail");
	char buf[1024] = {0};
	unsigned int lines = 0;
	while((fgets(buf,sizeof(buf),fp) != NULL))
	{
		lines++;
	}
	return (int)lines;
	
}


void getFileContents(FILE * fp,int lines,char ** Contents)
{
	
	if(fp == NULL || lines <= 0 || Contents ==NULL)
		perror("file fail");

	char buf[1024] = {0};

	char *ret = NULL ;
	int i = 0;
	while((NULL != fgets(buf,sizeof(buf),fp)))
	{
		//printf("%s",buf); //fgets读取换行了
		
		Contents[i] = malloc(sizeof(char) * (strlen(buf)+1)) ;
		strcpy(Contents[i],buf);
		//printf("%s",Contents[i]);
		memset(buf,0,1024);
		i++ ;
		
	}

}

void show(char ** Contents,int lines)
{	
	if(Contents == NULL || lines <= 0)
		return ;

	for(int i = 0;i< lines;++i)
	{
		printf("%s",Contents[i]);
	}

	printf("\n");
}


void freeSpace(char **Contents,int lines)
{
	if(Contents == NULL || lines <= 0)
		return ;
	for(int i = 0;i<lines;++i)
	{
		if(Contents[i] != NULL)
		{	
			free(Contents[i]);
			Contents[i] = NULL;
		}
	}

	if(Contents != NULL)
	{
		free(Contents);
		Contents = NULL ;
	}

	
}

int main(void)
{
	char * filename = "_30_test.txt" ;
	FILE * fp = fopen(filename,"r");

	int lines = getlines(fp);
	printf("lines:%d\n",lines) ;
	
	fseek(fp,0,SEEK_SET);//前面统计行数已经打开文件，文件指针走到最后了

	char ** Contents = malloc(sizeof(char *) * lines) ;
	getFileContents(fp,lines,Contents);
	fclose(fp);

	show(Contents,lines);
	freeSpace(Contents,lines) ;

	
	return 0;
}
