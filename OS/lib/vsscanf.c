/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              vsscanf.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    HOLLYwyh, 2021
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

// int -> string
int a2i(int* m, int base,char* argv)
{
        int symbol = 1;
        int result = 0;
        int begin =0;
        int end = 0;
        
        // 符号位
        if(argv[0] == '-')
        {
                symbol = -1;
                begin++;
        }
        end = begin;
        //计算字符串的长度
        while(argv[end])
        {
                end++;
        }
        for(int i = end-1;i>=begin;i--)
        {
                if(((argv[i] >= '0')&&(argv[i] <='9'))||((base >10)&&(argv[i]>='A')&&(argv[i]<= (base -11+'A')))
                || ((base>10)&&(argv[i]>='a')&&(argv[i]<=(base-11+'a'))))
                {
                        int temp = 1;
                        for(int j = 0;j<end-1-i;j++)
                        {
                                temp *= base;
                        }
                        if((argv[i]>= '0')&&(argv[i] <='9'))
                        {
                                result += (argv[i] - '0') * temp;
                        }
                        else if((argv[i]>= 'A')&&(argv[i]<=(base-11+'A')))
                        {
                                result += (argv[i] - 'A'+10) * temp;
                        }
                        else
                        {
                                result += (argv[i] - 'a'+ 10) *temp;
                        }
                }
                else
                {
                        return 0;
                }
        }

        result *= symbol;
        *m = result;

        return *m;
}

// long ->string
long l2i (long*l, int base, char* argv)
{
       int symbol = 1;
        long result = 0;
        int begin =0;
        int end = 0;
        
        // 符号位
        if(argv[0] == '-')
        {
                symbol = -1;
                begin++;
        }
        end = begin;
        //计算字符串的长度
        while(argv[end])
        {
                end++;
        }
        for(int i = end-1;i>=begin;i--)
        {
                if(((argv[i] >= '0')&&(argv[i] <='9'))||((base >10)&&(argv[i]>='A')&&(argv[i]<= (base -11+'A')))
                || ((base>10)&&(argv[i]>='a')&&(argv[i]<=(base-11+'a'))))
                {
                        int temp = 1;
                        for(int j = 0;j<end-1-i;j++)
                        {
                                temp *= base;
                        }
                        if((argv[i]>= '0')&&(argv[i] <='9'))
                        {
                                result += (argv[i] - '0') * temp;
                        }
                        else if((argv[i]>= 'A')&&(argv[i]<=(base-11+'A')))
                        {
                                result += (argv[i] - 'A'+10) * temp;
                        }
                        else
                        {
                                result += (argv[i] - 'a'+ 10) *temp;
                        }
                }
                else
                {
                        return 0;
                }
        }

        result *= symbol;
        *l = result;

        return *l;
}

double f2i (double* db, char* argv)
{
 	int symbol = 1;
        double result = 0;
        int integer_begin =0;
        int integer_end = 0;
        int fraction_begin = 0;
        int fraction_end = 0;
        
        // 符号位
        if(argv[0] == '-')
        {
                symbol = -1;
                integer_begin++;
        }
        integer_end = integer_begin;
        //计算整数部分的长度
        while((argv[integer_end] != '.')&&(argv[integer_end]))
        {
                integer_end++;
        }
        //计算小数部分的长度
        fraction_begin = integer_end;
        fraction_end = integer_end;
        while(argv[fraction_end])
        {
                if(argv[fraction_end] == '.')
                {
                        fraction_begin++;
                        fraction_end++;
                }
                else
                {
                        fraction_end++;
                }
        }
        //计算整数部分
        for(int i = integer_end-1;i>=integer_begin;i--)
        {
		if((argv[i] >= '0')&&(argv[i] <='9'))
                {
                        int temp = 1;
                        for(int j = 0;j<integer_end-1-i;j++)
                        {
                                temp *= 10;
                        }

                        result += (argv[i] - '0') * temp;
                }
                else
                {
                        return 0;
                }
        }

        //计算小数部分
        for(int i = fraction_begin;i<= fraction_end-1;i++)
        {
		if((argv[i] >= '0')&&(argv[i] <='9'))
                {
                        double temp = 1;
                        for(int j = 0;j<=i-fraction_begin;j++)
                        {
                                temp *= 0.1;
                        }
                        if((argv[i]>= '0')&&(argv[i] <='9'))
                        {
                                result += (argv[i] - '0') * temp;
                        }
                }
                else
                {
                        return 0;
                }
        }

        result *= symbol;
        *db = result;

        return *db;
}

PUBLIC int vsscanf(char* buf, const char* fmt, int argc, char* argv[], va_list args)
{
	char* p;
        char* next;

        va_list  p_next_arg = args;
        int m;                  //读取int 相关的值
        double db;              //读取double 相关的值
        long l;                 //读取long相关的值
        int is_combine = 0;     //是否有复合输出

        int i = 0;
        char cs;
        int align_nr;

        for(p = buf;*fmt;fmt++)
        {
                if((*fmt != '%')&&(!is_combine))
                {
                        *p++ = *fmt;
                        continue;
                }
                else    // a format string begins
                {
                        align_nr = 0;
                }
                fmt++;

                if(*fmt == '%')
                {
                        *p++ = *fmt;
                        continue;
                }
                else if(*fmt == '0')
                {
                        cs = '0';
                        fmt++;
                }
                else
                {
                        cs = ' ';
                }
                while(((unsigned char)(*fmt) >= '0')&&
                ((unsigned char)(*fmt)<= '9'))
                {
                        align_nr *= 10;
                        align_nr += *fmt - '0';
                        fmt++;
                }

                //筛选fmt
                switch (*fmt)
                {
                        case 'c':
                                **(char**)p_next_arg = argv[i][0];  // char只取第一个即可
                                p_next_arg +=4;
                                i++;
                                break;
                        case 'x': 
                                **(int**)p_next_arg = a2i(&m,16,argv[i]);
                                p_next_arg +=4;
                                i++;
                                break;
                        case 'd':
                                **(int**)p_next_arg = a2i(&m,10,argv[i]);
                                p_next_arg +=4;
                                i++;
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
                                        **(long**)p_next_arg = l2i(&l,10,argv[i]);
                                        p_next_arg += 4;
                                        i++;
                                        break;
                                }
                        case 'f':
                                if(is_combine)
                                {
                                        is_combine = 0;
                                        **(double**)p_next_arg = f2i(&db,argv[i]);
                                }
                                else
                                {
                                        **(float**)p_next_arg = (float)f2i(&db,argv[i]);
                                }
                                p_next_arg +=4;
                                i++;
                                break;
                        case 's':
                                strcpy(*(char**)p_next_arg,argv[i]);
                                p_next_arg += 4;
                                i++;
                                break;
                        default : 
                                printf("az\n");
                                break;
                }

        }

        return ( p- buf);
}
