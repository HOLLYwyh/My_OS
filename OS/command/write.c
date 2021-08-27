// write a file
#include "stdio.h"
#include "shell.h"

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;//使用num 和argv两个变量来接收argc和argv
	char buf[100];

	if(num >=2)
	{
		//help: -h or --help
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** write : write somethimg to a file. **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** write filename :                   **\n");
			printf("\t\t** write something to a file          **\n");
			printf("\t\t** with filename                      **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** You can't modify the system file   **\n");
			printf("\t\t****************************************\n");  //40个*
		}
		//write
		else
		{
			init_files();
			
			//查看系统文件	
			for(int i=0;i<SYS_FILE_NUM;i++)
			{
				if(strequal(system_files[i],array[1]))
				{
					printf("You can't modify system files!\n");
					return 0;
				}
			}

			int fd = open(array[1],O_RDWR);

			if(fd == -1)
			{
				printf("File not found\n");
				return 0;
			}

			printf("Please write something:\n\t");
			
			read(0,buf,sizeof(buf));

			write(fd,(void*)buf,sizeof(buf));
			close(fd);
		}		
	}
	else
	{
		printf("Please input filename!\n");
	}
	return 0;
}
