// listfile.c
// 列举所有文件

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
#include "proto.h"

PUBLIC void listfile(char (*list)[30], int* begin, int* end , int type)
{
	MESSAGE msg;

	msg.type	= LIST_FILE;
	msg.file_number = 0;

	send_recv(BOTH, TASK_FS, &msg);
	assert(msg.type == SYSCALL_RET);
	
	//赋值
	for(int i =0;i<msg.file_number-1;i++)
	{
		int j = 0;
		while(msg.file_table[i][j])
		{
			list[i][j] = msg.file_table[i][j];
			j++;
		}
		list[i][j] = 0;
	}

	//判断类型
	switch(type)
	{
		case SYS_FILE:
			*begin = 0;
			*end = SYS_FILE_NUM;
			break;
		case USR_FILE:
			*begin = SYS_FILE_NUM;
			*end = msg.file_number-1;
			break;
		case ALL_FILE:
			*begin = 0;
			*end = msg.file_number-1;
			break;
		default:
			*begin = SYS_FILE_NUM;
			*end = msg.file_number-1;
			break;
	}
}
