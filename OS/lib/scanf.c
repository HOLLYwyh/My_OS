/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              scanf.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    HOLLY, 2021
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"

// 从shell读取值
int read_buf(char* rdbuf,int * argc, char* argv[])
{
	int r;
	while(1)
	{
		r = read(0,rdbuf,70);
		if(r != -1)
		{
			rdbuf[r] = 0;
			
			char * p =rdbuf;
			char *s;
			int word = 0;
			char ch;
			do
			{
				ch = *p;
				if(*p != ' '&& *p !=0 && !word)
				{
					s = p;
					word = 1;
				}
				if((*p == ' ' || *p == 0) && word)
				{
					word = 0;
					argv[(*argc)++] = s;
					*p = 0;
				}
				p++;
			}
			while(ch);
			argv[(*argc)] = 0;

			break;
		}
	}
	return r;
}

PUBLIC int scanf(const char*fmt, ...)
{
	char rdbuf[128];   //从shell读取
	int argc = 0;
	char * argv[PROC_ORIGIN_STACK];    
	int result;
	char buf[STR_DEFAULT_LEN];
	va_list arg = (va_list)((char*)(&fmt) + 4); /*4 是参数fmt所占堆栈中的大小*/


	//首先读取Shell
	read_buf(rdbuf, &argc, argv);
	
	//进行值的写入
	result = vsscanf(buf, fmt, argc, argv, arg);
	
	return result;
}
