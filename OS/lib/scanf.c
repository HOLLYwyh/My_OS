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

PUBLIC int scanf(const char*fmt, ...)
{
	char rdbuf[128];
	while(1)
	{
		int r = read(0,rdbuf,70);
		if(r != -1)
		{
			printf("Haha\n");
			break;
		}
	}
	
	return 0;
}
