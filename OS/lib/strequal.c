/*************************************************************************//**
 *****************************************************************************
 * @file   strequal.c
 * @brief  
 * @author HOLLYwyh
 * @date   Fri Aug  6 22:03 2021
 *****************************************************************************
 *****************************************************************************/

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
#include "shell.h"

// "-h" and "--help"
void init_help()
{
	help1[0] = help2[0] = '-';
	help1[1] = 'h';
	help1[2] = 0;
	help2[1] = '-';
	help2[2] = 'h';
	help2[3] = 'e';
	help2[4] = 'l';
	help2[5] = 'p';
	help2[6] = 0;
}

// "--all"
void init_all()
{
	all[0] = '-';
	all[1] = '-';
	all[2] = 'a';
	all[3] =  'l';
	all[4] = 'l';
	all[5] = 0;
}



/*****************************************************************************
 *                                strequal
 *****************************************************************************/
/**
 * Compare one string is equal to anothor string
 * @param str1	The first string
 * @param str2	The second string
 * @return   On success, return a interger that not equal to 0
 *           On failure, return 0
 *****************************************************************************/

PUBLIC int strequal(const char* str1,const char* str2)
{
	init_help();
	init_all();
	//1.0可能还有需要改进的地方
	int result = 0;
	int tag = 0;
	while((*str1!=0)&&(*str2!=0))
	{
		if(*str1 == *str2)
		{
			result++;
			str1++;
			str2++;
		}
		else
		{
			tag = 1;//直接有两个不相等的字符
			break;
		}
	}
	if(tag == 1)
	{
		result = 0;
	}
	else if(!((*str1 == 0 )&&(*str2 == 0)))  //一个等于0另一个不等于0
	{
		result = 0;
	}
	return result;
}
