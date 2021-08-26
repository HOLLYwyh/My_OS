// read a file
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
			printf("\t\t** cat : read a file                  **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** cat file :                         **\n");
			printf("\t\t** read a file with filename          **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t****************************************\n");  //40个*
		}
		//cat
		else
		{
			int fd = open(array[1],O_RDWR);
			if(fd == -1)
			{
				printf("File not found\n");
			}

			read(fd, (void*)buf, sizeof(buf));
			printf("%s\n", buf);

			close(fd);
		}
				
	}
	else
	{
		printf("Please input filename!\n");
	}
	
	return 0;
}
