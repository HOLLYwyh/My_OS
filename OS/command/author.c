#include "stdio.h"
#include "shell.h"

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv; //使用num和argv两个变量来接收argc和argv

	//help: -h or --help
	if(num>=2)
	{
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** author : OS's author.              **\n");
			printf("\t\t** For example : author               **\n");
			printf("\t\t** You will get : The Author's Name   **\n");
			printf("\t\t****************************************\n");  //40个*

			return 0;
		}
	}

	//author 
	printf("Author : HOLLYwyh\n");
	return 0;
}
