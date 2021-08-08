/*************************************************************************//**
 *****************************************************************************
 * @file   shell.c
 * @brief  
 * @author HOLLYwyh
 * @date   2021
 *****************************************************************************
 *****************************************************************************/

#include "shell.h"

// "-h" and "--help"
char 		help1[3] = {'-','h'};
char		help2[7] = {'-','-','h','e','l','p'};

// boot animation
void boot_animation()
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
	printl("*       * *     *     * *               * Pree F4 to see details.              *");
	printl("*       * * *       * * *                                                      *");
	printl("*            * * * *                    * You can visit github.com/HOLLYwyh    *");
	printl("*             *****                       www.github.com/HOLLYwyhOr            *");
	printl("*              ***                        Or email 1053790247@qq.com           *");
	printl("*               *                         To contact author.                   *");
	printl("********************************************************************************");//80个*
}
