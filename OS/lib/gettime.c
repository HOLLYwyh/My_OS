// getTime
// 获取时间

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

PUBLIC void gettime(struct time* tm)
{
	MESSAGE msg;
	
	msg.type = GET_RTC_TIME;
	send_recv(BOTH,TASK_SYS,&msg);
	assert(msg.type == SYSCALL_RET);

	*tm = *(struct time*)msg.BUF;
}
