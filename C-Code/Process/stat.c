/*************************************************************************
	> File Name: stat.c
	> Created Time: 五  2/28 18:33:00 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>



int main(int argc,char *argv[])
{
	//判断输入的是否有第二个参数
	if(argc < 2)
	{
		printf("input is not ok\n");
		exit(1);
	}
	//定义作为输出文件信息的结构体指针
	struct stat st;

	int ret = stat(argv[1],&st);
	if(-1 == ret)
	{
		perror("stat fail");
		exit(1);
	}

	//存储文件类型和访问权限
	char perms[11] = {0};

	//判断文件类型
	switch(st.st_mode & S_IFMT)
	{
		case S_IFLNK:
			perms[0] = 'l';
			break;
		case S_IFDIR:
			perms[0] = 'd';
			break;
		case S_IFREG:
			perms[0] = '-';
			break;
		case S_IFCHR:
			perms[0] = 'c';
			break;
		case S_IFBLK:
			perms[0] = 'b';
			break;
		case S_IFSOCK:
			perms[0] = 's';
			break;
		case S_IFIFO:
			perms[0] = 'p';
			break;
		default:
			perms[0] = '?';
			break;
	}
	//判断文件访问权限：
	//文件所有者
	perms[1] = (st.st_mode & S_IRUSR) ? 'r':'-';
	perms[2] = (st.st_mode & S_IWUSR) ? 'w':'-';
	perms[3] = (st.st_mode & S_IXUSR) ? 'x':'-';
	//文件所属组
	perms[4] = (st.st_mode & S_IRGRP) ? 'r':'-';
	perms[5] = (st.st_mode & S_IWGRP) ? 'w':'-';
	perms[6] = (st.st_mode & S_IXGRP) ? 'x':'-';
	//其他人
	perms[7] = (st.st_mode & S_IROTH) ? 'r':'-';
	perms[8] = (st.st_mode & S_IWOTH) ? 'w':'-';
	perms[9] = (st.st_mode & S_IXOTH) ? 'x':'-';

	//硬链接计数
	int linkNum = st.st_nlink;
	//文件所有者
	char *fileUser = getpwuid(st.st_uid)->pw_name;
	//文件所属组
	char *fileGrp = getgrgid(st.st_gid)->gr_name;

	//文件大小
	int fileLen = (int)st.st_size;
	//修改时间
	char *time = ctime(&st.st_mtime);
	char mtime[512] = {0};
	strncpy(mtime,time,strlen(time)-1);

	char buf[1024];
	sprintf(buf,"%s %d %s %s %d %s %s",perms,linkNum,fileUser,fileGrp,fileLen,mtime,argv[1]);

	printf("%s\n",buf);


	return 0;
}
