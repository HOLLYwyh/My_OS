#include "type.h"
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
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** pwd : Current Dictionary Path      **\n");
			printf("\t\t** For example : pwd                  **\n");
			printf("\t\t** You may get : /	            **\n");
			printf("\t\t****************************************\n");  //40个*

			return 0;
		}
	}

	//pwd
	printf("/\n");          //目前只有一个文件夹(根目录)，以后可能还会有修改
	return 0;
}
