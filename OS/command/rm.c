// delete a txt file
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
			printf("\t\t** rm : delete a file                 **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** rm file :                          **\n");
			printf("\t\t** delete a file with filename        **\n");
			printf("\t\t**                                    **\n");
			printf("\t\t** You can't delete a system file     **\n");
			printf("\t\t****************************************\n");  //40个*
		}
		//rm
		else
		{
			int result = deletefile(array[1]);
			
			switch(result)
			{
				case SYS_FILE:
					printf("Can not delete system files!\n");
					break;
				case FILE_ERROR:
					printf("File not exists.\n");
					break;
				case DELETED:
					printf("Done.\n");
					break;
				default :
					printf("Error.!\n");
			}
		}
				
	}
	else
	{
		printf("Please input a filename!\n");
	}
	return 0;
}
