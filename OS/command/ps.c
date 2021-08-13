# include "stdio.h"
# include "shell.h"

//进程相关
int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;//使用num 和argv两个变量来接收argc和argv

	struct rt_proc proc_group[PROC_NUM];
	int begin;
	int end;

	if(num >=2)
	{
		//help: -h or --help
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
		}
		//all: --all
		else if(strequal(array[1],all))
		{
			getproc(&proc_group,ALL_PROC,&begin,&end);
		}
		else if(strequal(array[1],"--sys"))
		{
			getproc(&proc_group,SYS_PROC,&begin,&end);
		}
	}
	//ps
	else
	{
		getproc(&proc_group,USER_PROC,&begin,&end);
	}
	return 0;
}
