// createfile
// 创建文件

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


PUBLIC void init_files()
{
	// '/'
	system_files[0][0] = '/';
	system_files[0][1] = 0;
	
       // "dev_tty0"	
	system_files[1][0] = 'd';
	system_files[1][1] = 'e';
	system_files[1][2] = 'v';
	system_files[1][3] = '_';
	system_files[1][4] = 't';
	system_files[1][5] = 't';
	system_files[1][6] = 'y';
	system_files[1][7] = '0';
	system_files[1][8] =  0;
	
       // "dev_tty1"	
	system_files[2][0] = 'd';
	system_files[2][1] = 'e';
	system_files[2][2] = 'v';
	system_files[2][3] = '_';
	system_files[2][4] = 't';
	system_files[2][5] = 't';
	system_files[2][6] = 'y';
	system_files[2][7] = '1';
	system_files[2][8] =  0;
	
	// "dev_tty2"	
	system_files[3][0] = 'd';
	system_files[3][1] = 'e';
	system_files[3][2] = 'v';
	system_files[3][3] = '_';
	system_files[3][4] = 't';
	system_files[3][5] = 't';
	system_files[3][6] = 'y';
	system_files[3][7] = '2';
	system_files[3][8] =  0;
	
	// "cmd.tar"
	system_files[4][0] = 'c';
	system_files[4][1] = 'm';
	system_files[4][2] = 'd';
	system_files[4][3] = '.';
	system_files[4][4] = 't';
	system_files[4][5] = 'a';
	system_files[4][6] = 'r';
	system_files[4][7] =  0 ;	
	
	// "kernel.bin"
	system_files[5][0] = 'k';
	system_files[5][1] = 'e';
	system_files[5][2] = 'r';
	system_files[5][3] = 'n';
	system_files[5][4] = 'e';
	system_files[5][5] = 'l';
	system_files[5][6] = '.';
	system_files[5][7] = 'b';
	system_files[5][8] = 'i';
	system_files[5][9] = 'n';
	system_files[5][10] = 0 ;
	
	//echo
	system_files[6][0] = 'e';
	system_files[6][1] = 'c';
	system_files[6][2] = 'h';
	system_files[6][3] = 'o';
	system_files[6][4] =  0 ;
	
	// "pwd"
	system_files[7][0] = 'p';
	system_files[7][1] = 'w';
	system_files[7][2] = 'd';
	system_files[7][3] =  0 ;
	
	// "author"
	system_files[8][0] = 'a';
	system_files[8][1] = 'u';
	system_files[8][2] = 't';
	system_files[8][3] = 'h';
	system_files[8][4] = 'o';
	system_files[8][5] = 'r';
	system_files[8][6] =  0 ;
	
	// "cal"
	system_files[9][0] = 'c';
	system_files[9][1] = 'a';
	system_files[9][2] = 'l';
	system_files[9][3] =  0 ;

	// "cmd"
	system_files[10][0] = 'c';
	system_files[10][1] = 'm';
	system_files[10][2] = 'd';
	system_files[10][3] =  0 ;
	
	// "ps"
	system_files[11][0] = 'p';
	system_files[11][1] = 's';
	system_files[11][2] =  0 ;
	
	// "game"
	system_files[12][0] = 'g';
	system_files[12][1] = 'a';
	system_files[12][2] = 'm';
	system_files[12][3] = 'e';
	system_files[12][4] =  0 ;
	
	// "details"
	system_files[13][0] = 'd';
	system_files[13][1] = 'e';
	system_files[13][2] = 't';
	system_files[13][3] = 'a';
	system_files[13][4] = 'i';
	system_files[13][5] = 'l';
	system_files[13][6] = 's';
	system_files[13][7] =  0 ;
	
	// "kill"
	system_files[14][0] = 'k';
	system_files[14][1] = 'i';
	system_files[14][2] = 'l';
	system_files[14][3] = 'l';
	system_files[14][4] =  0 ;
	
	// "time"
	system_files[15][0] = 't';
	system_files[15][1] = 'i';
	system_files[15][2] = 'm';
	system_files[15][3] = 'e';
	system_files[15][4] =  0 ;
	
	// "rm"
	system_files[16][0] = 'r';
	system_files[16][1] = 'm';
	system_files[16][2] =  0 ;
	
	// "touch"
	system_files[17][0] = 't';
	system_files[17][1] = 'o';
	system_files[17][2] = 'u';
	system_files[17][3] = 'c';
	system_files[17][4] = 'h';
	system_files[17][5] =  0 ;

}


PUBLIC int createfile(char* filename)
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
			
	// 创建文件
	int fd = (open(filename,O_CREAT));
	
	//存在用户文件
	if(fd == -1)
	{
		return USR_FILE;
	}
	else
	{		
		return CREATED;
	}
}
