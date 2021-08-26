// List all files
#include "stdio.h"
#include "shell.h"

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;//使用num 和argv两个变量来接收argc和argv
	char (*file_list)[30];
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
			printf("\t\t** ls : All Files                     **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** ls --all: see all Files.           **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** ls  -h (or --help)                 **\n");
			printf("\t\t**      -- help about the files.      **\n");
			printf("\t\t** 				   **\n");
			printf("\t\t** ls [--usr] : see user files.       **\n");
			printf("\t\t** 				   **\n");
			printf("\t\t** ls --sys : see system files.       **\n");
			printf("\t\t****************************************\n");  //40个*
		}	
		//all: --all
		else if(strequal(array[1],all))
		{
			listfile(file_list,&begin,&end,ALL_FILE);
			for(int i=begin;i<end;i++)
			{
				printf("%s\n",file_list[i]);
			}
		}
		//sys: --sys
		else if(strequal(array[1],"--sys"))
		{
			listfile(file_list,&begin,&end,SYS_FILE);
			for(int i=begin;i<end;i++)
			{
				printf("%s\n",file_list[i]);
			}
		}
		//usr: --usr
		else if(strequal(array[1],"--usr"))
		{
			listfile(file_list,&begin,&end,USR_FILE);
			for(int i=begin;i<end;i++)
			{
				printf("%s\n",file_list[i]);
			}
		}
		else 
		{
			printf("Please input a correct expression!!\n");
		}	
	}
	//ls
	else
	{
		listfile(file_list,&begin,&end,USR_FILE);
		for(int i=begin;i<end;i++)
		{
			printf("%s\n",file_list[i]);
		}
	}
	return 0;
}
