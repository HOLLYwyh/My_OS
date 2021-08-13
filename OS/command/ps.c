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
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** ps : All Process Related           **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** ps --all: see all process          **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** ps  -h (or --help)                 **\n");
			printf("\t\t**      -- help about the process     **\n");
			printf("\t\t** 				   **\n");
			printf("\t\t** ps [--usr] : see user process      **\n");
			printf("\t\t** 				   **\n");
			printf("\t\t** ps --sys : see system process      **\n");
			printf("\t\t****************************************\n");  //40个*
		}
		//all: --all
		else if(strequal(array[1],all))
		{
			getproc(&proc_group,ALL_PROC,&begin,&end);
			for(int i=begin;i<end;i++)
			{
				printf("********\n");
				printf("*PID   :\t%d\n",proc_group[i].pid);
				printf("*NAME  :\t%s\n",proc_group[i].name);
				printf("*STATUS:\tRunning\n");
				printf("********\n");
			}
		}
		//sys: --sys
		else if(strequal(array[1],"--sys"))
		{
			getproc(&proc_group,SYS_PROC,&begin,&end);
			for(int i=begin;i<end;i++)
			{
				printf("********\n");
				printf("*PID   :\t%d\n",proc_group[i].pid);
				printf("*NAME  :\t%s\n",proc_group[i].name);
				printf("*STATUS:\tRunning\n");
				printf("********\n");
			}
		}
		//usr: --usr
		else if(strequal(array[1],"--usr"))
		{
			getproc(&proc_group,USER_PROC,&begin,&end);
			for(int i=begin;i<end;i++)
			{
				printf("********\n");
				printf("*PID   :\t%d\n",proc_group[i].pid);
				printf("*NAME  :\t%s\n",proc_group[i].name);
				printf("*STATUS:\tRunning\n");
				printf("********\n");
			}
		}		
	}
	//ps
	else
	{
		getproc(&proc_group,USER_PROC,&begin,&end);
		for(int i=begin;i<end;i++)
		{
			printf("********\n");
			printf("*PID   :\t%d\n",proc_group[i].pid);
			printf("*NAME  :\t%s\n",proc_group[i].name);
			printf("*STATUS:\tRunning\n");
			printf("********\n");
		}
	}
	return 0;
}
