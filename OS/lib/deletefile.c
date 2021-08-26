// deletefile.c
// 删除文件

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

PUBLIC int deletefile(char* filename)
{
	init_files();
	
	//查看系统文件
	for(int i=0;i<SYS_FILE_NUM;i++)
	{
		if(strequal(system_files[i],filename))
		{
			return SYS_FILE;
		}
	}
	
	//删除文件
	int fd = unlink(filename);
	
	//判断删除情况
	if(fd == -1)
	{
		return FILE_ERROR;
	}
	else
	{
		return DELETED;
	}
}
