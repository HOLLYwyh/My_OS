//time 
#include "stdio.h"
#include "shell.h"

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;//使用num 和argv两个变量来接收argc和argv

	struct time tm;

	if(num >=2)
	{
		//help: -h or --help
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** time : Current time.               **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** time --all: see all detailed time  **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** time  -h (or --help)               **\n");
			printf("\t\t**      -- help about the time        **\n");
			printf("\t\t****************************************\n");  //40个*
		}
		else if(strequal(array[1],all))
		{
			gettime(&tm);
			printf("year -- %d\n",tm.year);
			printf("month -- %d\n",tm.month);
			printf("day --  %d\n",tm.day);
			printf("time -- %d:%d:%d\n",tm.hour,tm.minute,tm.second);
		}
		else
		{
			gettime(&tm);
			printf("time -- %d:%d:%d\n",tm.hour,tm.minute,tm.second);
		}
	}
	//time
	else
	{
		gettime(&tm);
		printf("time -- %d:%d:%d\n", tm.hour, tm.minute, tm.second);
	}
	return 0;
}
