// All Games
#include "stdio.h"
#include "shell.h"

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;  //使用num和argv两个变量来接收argv和argv

	if(num >= 2)
	{
		//help: -h or --help
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
		}
		//all: --all
		else if(strequal(array[1],all))
		{
		}

	}

}
