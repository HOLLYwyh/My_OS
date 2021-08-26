// create a txt file
#include "stdio.h"
#include "shell.h"

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;//使用num 和argv两个变量来接收argc和argv

	if(num >=2)
	{
		//help: -h or --help
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** touch : create a file              **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** touch file :                       **\n");
			printf("\t\t** create a file with filename        **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** You can't create an existed file   **\n");
			printf("\t\t****************************************\n");  //40个*
		}
		//touch
		else
		{
			int result = createfile(array[1]);
			switch (result)
			{
				case SYS_FILE:
					printf("File has existed\n");
					break;
				case USR_FILE:
					printf("File has existed\n");
					break;
				case CREATED:
					printf("Done.\n");
					break;
				default :
					printf("ERROR.\n");
				
			}
		}
				
	}
	return 0;
}
