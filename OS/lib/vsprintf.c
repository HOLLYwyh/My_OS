
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              vsprintf.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
						    HOllywyh  , 2021
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



/*======================================================================*
                                i2a
 *======================================================================*/
PRIVATE char* i2a(int val, int base, char ** ps)
{
	int m = val % base;
	int q = val / base;
	if (q) {
		i2a(q, base, ps);
	}
	*(*ps)++ = (m < 10) ? (m + '0') : (m - 10 + 'A');

	return *ps;
}

/*=========================================================================*
				l2a
*==========================================================================*/
PRIVATE char* l2a(long val, int base, char ** ps)
{
	long m = val % base;
	long q = val / base;
	if (q) 
	{
		l2a(q, base, ps);
	}
	*(*ps)++ = (m<10) ? (m + '0') : (m - 10 + 'A');
	return *ps;
}

/*=========================================================================*
				f2a
*==========================================================================*/
PRIVATE char* f2a(double val, int base,char ** ps,int length)
{
	int  integer;//整数部分
	double fraction;//小数部分
	double temp_fraction;
	int m;
	int fra_length = 0; //小数部分的位数
	int max_size = 100;  //所能处理的最大精度，主要为了防止无限小数

	integer = (int)val;
	fraction = val - integer;
	//计算整数部分
	i2a(integer,base,ps);
	//小数部分
	//首先计算小数的位数
	temp_fraction = fraction;
	while(temp_fraction)
	{
		fra_length ++ ;
		m = (int)(temp_fraction * base);
		temp_fraction = temp_fraction * base - (double)m;
		if(fra_length >= max_size)
		{
			break;
		}
	}
	fra_length = (fra_length <= length) ? fra_length : length;
	//小数点
	if(fra_length > 0)
	{
		*(*ps)++ = '.';
	}
	//采用截短法进行输出
	for(int i=0; i<fra_length; i++)
	{
	    	m = (int)(fraction * base);
	    	fraction = fraction* base - (double)m;
	    	*(*ps)++ =(m < 10) ? (m + '0') : (m- 10 + 'A');
	}
	return *ps;
}


/*======================================================================*
                                vsprintf
 *======================================================================*/
/*
 *  为更好地理解此函数的原理，可参考 printf 的注释部分。
 */
PUBLIC int vsprintf(char *buf, const char *fmt, va_list args)
{
	char*	p;
	char*   next;

	va_list	p_next_arg = args;
	int	m;   //读取int相关的值  %x %d
	double  db;  //读取double相关的值 %f %lf
	long	l;   //读取long相关的值   %l
	int 	is_combine = 0;   //是否有复合输出

	char	inner_buf[STR_DEFAULT_LEN];
	char	cs;
	int	align_nr;

	for (p=buf;*fmt;fmt++) {
		if ((*fmt != '%')&&(!is_combine)) {
			*p++ = *fmt;
			continue;
		}
		else {		/* a format string begins */
			align_nr = 0;
		}

		fmt++;

		if (*fmt == '%') {
			*p++ = *fmt;
			continue;
		}
		else if (*fmt == '0') {
			cs = '0';
			fmt++;
		}
		else {
			cs = ' ';
		}
		while (((unsigned char)(*fmt) >= '0') && ((unsigned char)(*fmt) <= '9')) {
			align_nr *= 10;
			align_nr += *fmt - '0';
			fmt++;
		}

		char * q = inner_buf;
		memset(q, 0, sizeof(inner_buf));

		switch (*fmt) {
		case 'c':
			*q++ = *((char*)p_next_arg);
			p_next_arg += 4;
			break;
		case 'x':
			m = *((int*)p_next_arg);
			i2a(m, 16, &q);
			p_next_arg += 4;
			break;
		case 'd':
			m = *((int*)p_next_arg);
			if (m < 0) {
				m = m * (-1);
				*q++ = '-';
			}
			i2a(m, 10, &q);
			p_next_arg += 4;
			break;
		case 'l':
			next = fmt + 1;
			if(*next == 'f')
			{
				is_combine = 1;
				fmt--;
				continue;
			}
			else
			{			
				l = *((long*)p_next_arg);
				if(m < 0){
					m = m * (-1);
					*q++ = '-';
				}
				l2a(m, 10, &q);
				p_next_arg +=4;
				break;
			}
		case 'f':    //新增输出浮点数
			db = *((double*)p_next_arg);
			if (db < 0) {
				db = db * (-1);
				*q++ = '-';
			}
			if(is_combine)  //说明输出的是double
			{
				is_combine = 0;
				f2a(db, 10, &q, 6);
			}
			else
			{
				f2a(db, 10, &q, 4);
			}
			p_next_arg += 4;
			break;
		case 's':
			strcpy(q, (*((char**)p_next_arg)));
			q += strlen(*((char**)p_next_arg));
			p_next_arg += 4;
			break;
		default:
			break;
		}

		int k;
		for (k = 0; k < ((align_nr > strlen(inner_buf)) ? (align_nr - strlen(inner_buf)) : 0); k++) {
			*p++ = cs;
		}
		q = inner_buf;
		while (*q) {
			*p++ = *q++;
		}
	}

	*p = 0;

	return (p - buf);
}


/*======================================================================*
                                 sprintf
 *======================================================================*/
int sprintf(char *buf, const char *fmt, ...)
{
	va_list arg = (va_list)((char*)(&fmt) + 4);        /* 4 是参数 fmt 所占堆栈中的大小 */
	return vsprintf(buf, fmt, arg);
}
