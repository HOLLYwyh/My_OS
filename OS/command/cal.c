// 这是一个简易的计算器
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
			printf("\t\t** cal : A calculator.                **\n");
			printf("\t\t** For example : cal 1+1	      **\n");
			printf("\t\t** You will get : 2		   **\n");
			printf("\t\t****************************************\n");  //40个*

			return 0;
		}
	}

	//calculator
	printf("This is a simple calculator\n");
	return 0;
}
