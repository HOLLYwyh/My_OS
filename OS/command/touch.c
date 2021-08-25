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
		}
		//touch
		else
		{
		}
				
	}
	return 0;
}
