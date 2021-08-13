// getproc
// 获取进程

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

PUBLIC void getproc(struct rt_proc* table,int type, int* begin, int* end)
{
	MESSAGE msg;
	msg.type	= GET_PROC; 

	send_recv(BOTH,TASK_SYS,&msg);
	assert(msg.type == SYSCALL_RET);
	switch(type)
	{
		case USER_PROC:
			*begin = msg.pos.userbegin;
			*end = msg.pos.userend;
			break;
		case SYS_PROC:
			*begin = msg.pos.sysbegin; 
			*end = msg.pos.sysend;
			break;
		case ALL_PROC:
			*begin = msg.pos.sysbegin; 
			*end = msg.pos.userend;
			break;
		default:
			*begin = -1;
			*end = -1;
			break;
	}

	for(int i= msg.pos.sysbegin;i<msg.pos.userend;i++)
	{
		table[i] = msg.proc_table[i];
	}
}
