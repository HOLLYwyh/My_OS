/*************************************************************************//**
 *****************************************************************************
 * @file   shell.c
 * @brief  
 * @author HOLLYwyh
 * @date   2021
 *****************************************************************************
 *****************************************************************************/

#include "shell.h"
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

#define DELAY_TIME 3300


PRIVATE void clear();

PRIVATE void loading_1();

PRIVATE void loading_2();

PRIVATE void result();

PRIVATE void empty_window();

// boot animation
void boot_animation()
{	
	empty_window();
	loading_2();
	loading_1();
	loading_2();
	loading_1();
	loading_2();
	result();
}

PRIVATE void clear()
{
	clear_screen(0, console_table[current_console].cursor);
	console_table[current_console].crtc_start = 0;
	console_table[current_console].cursor = 0;
}

PRIVATE void empty_window()
{
	printl("********************************************************************************");//80个*
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("*                                                                              *");
	printl("********************************************************************************");//80个*
	
	milli_delay(DELAY_TIME);
	clear();
}

PRIVATE void  loading_1()
{
	printl("********************************************************************************");//80个*
	printl("*               *                                                              *");
	printl("*              ***                                                             *");
	printl("*             *****                                                            *");
	printl("*            * * * *                                                           *");
	printl("*       * * *       * * *                                                      *");
	printl("*       * *           * *                                                      *");
	printl("*       *               *                                                      *");
	printl("*      *                 *                                                     *");
	printl("*    * *                 * *                                                   *");
	printl("*  * * *                 * * *                                                 *");
	printl("*    * *                 * *                                                   *");
	printl("*      *                 *                                                     *");
	printl("*       *               *                                                      *");
	printl("*       * *           * *                                                      *");
	printl("*       * * *       * * *                                                      *");
	printl("*            * * * *                                                           *");
	printl("*             *****                                                            *");
	printl("*              ***                                                             *");
	printl("*               *                                                              *");
	printl("********************************************************************************");//80个*
	
	milli_delay(DELAY_TIME);
	clear();
	
}

PRIVATE void  loading_2()
{
	printl("********************************************************************************");//80个*
	printl("*               *                                                              *");
	printl("*              ***                                                             *");
	printl("*             *****                                                            *");
	printl("*            * * * *                                                           *");
	printl("*       * * *       * * *                                                      *");
	printl("*       * *   *****   * *                                                      *");
	printl("*       *    **   **    *                                                      *");
	printl("*      *   **      **    *                                                     *");
	printl("*    * *     ** **  **   * *                                                   *");
	printl("*  * * *      **    **   * * *                                                 *");
	printl("*    * *           **    * *                                                   *");
	printl("*      *     **   **     *                                                     *");
	printl("*       *      ***      *                                                      *");
	printl("*       * *     *     * *                                                      *");
	printl("*       * * *       * * *                                                      *");
	printl("*            * * * *                                                           *");
	printl("*             *****                                                            *");
	printl("*              ***                                                             *");
	printl("*               *                                                              *");
	printl("********************************************************************************");//80个*
	
	milli_delay(DELAY_TIME);
	clear();
}

PRIVATE void result()
{
	printl("********************************************************************************");//80个*
	//这里输出*没有'\n'的原因是:屏幕横向最多容纳80个字符，所以不需要换行。
	printl("*               *                                                              *");
	printl("*              ***                             HearthStone_OS                  *");
	printl("*             *****                           Author: Hollywyh                 *");
	printl("*            * * * *                                                           *");
	printl("*       * * *       * * *             Welcome To The HearthStone_OS !!!        *");
	printl("*       * *   *****   * *                                                      *");
	printl("*       *    **   **    *             Description:                             *");
	printl("*      *   **      **    *              * There are Three TTYs, You can :      *");
	printl("*    * *     ** **  **   * *               Press F1, F2, F3 to change TTy.     *");
	printl("*  * * *      **    **   * * *                                                 *");
	printl("*    * *           **    * *            * You can input 'cmd' to See           *");
	printl("*      *     **   **     *                 All commands in the OS.             *");
	printl("*       *      ***      *                                                      *");
	printl("*       * *     *     * *               * Press 'details' to see details.      *");
	printl("*       * * *       * * *                                                      *");
	printl("*            * * * *                    * You can visit github.com/HOLLYwyh    *");
	printl("*             *****                       www.github.com/HOLLYwyh              *");
	printl("*              ***                        Or email 1053790247@qq.com           *");
	printl("*               *                         To contact author.                   *");
	printl("********************************************************************************");//80个*
}
