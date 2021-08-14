// kill the process !!
#include "stdio.h"
#include "shell.h"

int a2i(int*pid ,const char*argv)
{
	//首先计算长度并判断字符
	int length = 0;
	*pid = 0;
	while(argv[length])
	{
		if((argv[length]>='0')&&(argv[length]<='9'))
		{
			length++;
		}
		else
		{
			return 0;
		}
	}

	//计算pid
	for(int i=length-1;i>=0;i--)
	{
		int temp = 1;
		for(int j=0;j<length-1-i;j++)
		{
			temp *= 10;
		}
		(*pid) +=(argv[i] - '0')*temp;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;//使用num 和argv两个变量来接收argc和argv
	int pid;             //需要终止的进程

	if(num >=2)
	{
		//help: -h or --help
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** kill : kill a process              **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** kill proc_pid :                    **\n");
			printf("\t\t** kill the process with pid proc_pid **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t**notice:You can't kill system process**\n");
			printf("\t\t****************************************\n");  //40个*
		}
		//pid
		else
		{
			if(a2i(&pid,array[1]))
			{
				int result = killproc(pid);
				switch(result)
				{
					case NO_PROC:
						printf("Process doesn't exist!\n");
						break;
					case SYS_PROC:
						printf("Can not kill a system related process.\n");
						break;
					case SELF_PROC:
					case USER_PROC:
						printf("Done.\n");
						break;
					default:
						break;

				}
			}
			else
			{
				printf("Please input a correct PID!\n");
			}
		}
				
	}
	//kill
	else
	{
		printf("Please input PID!!!\n");
	}
	return 0;
}
