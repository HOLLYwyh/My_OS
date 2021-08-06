#include "stdio.h"
#include "shell.h"

int main(int argc, char * argv[])
{
	int num = argc;
	char ** array = argv; //使用num和argv两个变量来接收argc和argv

	//help: -h or --help
	if(num>=2)
	{
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("HaHa\n");
			return 0;
		}
	}

	//echo 
	for(int j=1;j<num;j++)
	{
		printf("%s%s", j==1 ? "" : " ",array[j]);
	}

	printf("\n");

	return 0;
}
