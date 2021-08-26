/*************************************************************************//**
 *****************************************************************************
 * @file   stdio.h
 * @brief  
 * @author Forrest Y. Yu
 * @modified HOLLYwyh
 * @date   2008
 *****************************************************************************
 *****************************************************************************/

#ifndef	_ORANGES_STDIO_H_
#define	_ORANGES_STDIO_H_

#include "type.h"

/* the assert macro */
#define ASSERT
#ifdef ASSERT
void assertion_failure(char *exp, char *file, char *base_file, int line);
#define assert(exp)  if (exp) ; \
        else assertion_failure(#exp, __FILE__, __BASE_FILE__, __LINE__)
#else
#define assert(exp)
#endif

/* EXTERN */
#define	EXTERN	extern	/* EXTERN is defined as extern except in global.c */

/* string */
#define	STR_DEFAULT_LEN	1024

#define	O_CREAT		1
#define	O_RDWR		2
#define	O_TRUNC		4

#define SEEK_SET	1
#define SEEK_CUR	2
#define SEEK_END	3

#define	MAX_PATH	128

//Proc_table
#define ALL_PROC	1
#define SYS_PROC 	2
#define USER_PROC	3
#define NO_PROC		4
#define SELF_PROC	5
#define PROC_NUM	37   //这里需要和proc.h保持一致！！！

//Proc status
#define KILL_STATUS    360

// FILES
#define SYS_FILE 1
#define USR_FILE 2
#define CREATED  3
#define DELETED  4
#define SYS_FILE_NUM  18
char system_files[25][15];

/**
 * @struct stat
 * @brief  File status, returned by syscall stat();
 */
struct stat {
	int st_dev;		/* major/minor device number */
	int st_ino;		/* i-node number */
	int st_mode;		/* file mode, protection bits, etc. */
	int st_rdev;		/* device ID (if special file) */
	int st_size;		/* file size */
};

/**
 * @struct time
 * @brief  RTC time from CMOS.
 */
struct time {
	u32 year;
	u32 month;
	u32 day;
	u32 hour;
	u32 minute;
	u32 second;
};

#define  BCD_TO_DEC(x)      ( (x >> 4) * 10 + (x & 0x0f) )

/*========================*
 * printf, printl, printx *
 *========================*
 *
 *   printf:
 *
 *           [send msg]                WRITE           DEV_WRITE
 *                      USER_PROC ------------→ FS -------------→ TTY
 *                              ↖______________↙↖_______________/
 *           [recv msg]             SYSCALL_RET       SYSCALL_RET
 *
 *----------------------------------------------------------------------
 *
 *   printl: variant-parameter-version printx
 *
 *          calls vsprintf, then printx (trap into kernel directly)
 *
 *----------------------------------------------------------------------
 *
 *   printx: low level print without using IPC
 *
 *                       trap directly
 *           USER_PROC -- -- -- -- -- --> KERNEL
 *
 *
 *----------------------------------------------------------------------
 */

/* printf.c */
PUBLIC  int     printf(const char *fmt, ...);
PUBLIC  int     printl(const char *fmt, ...);

/* vsprintf.c */
PUBLIC  int     vsprintf(char *buf, const char *fmt, va_list args);
PUBLIC	int	sprintf(char *buf, const char *fmt, ...);

/* scanf.c */
PUBLIC int 	scanf(const char *fmt, ...);
/* vsscanf.c */
PUBLIC int 	vsscanf(char *buf, const char *fmt, int argc, char* argv[], va_list args);

/*--------*/
/* 库函数 */
/*--------*/

#ifdef ENABLE_DISK_LOG
#define SYSLOG syslog
#endif

/* lib/open.c */
PUBLIC	int	open		(const char *pathname, int flags);

/* lib/close.c */
PUBLIC	int	close		(int fd);

/* lib/read.c */
PUBLIC int	read		(int fd, void *buf, int count);

/* lib/write.c */
PUBLIC int	write		(int fd, const void *buf, int count);

/* lib/lseek.c */
PUBLIC	int	lseek		(int fd, int offset, int whence);

/* lib/unlink.c */
PUBLIC	int	unlink		(const char *pathname);

/* lib/getpid.c */
PUBLIC int	getpid		();

/* lib/fork.c */
PUBLIC int	fork		();

/* lib/exit.c */
PUBLIC void	exit		(int status);

/* lib/wait.c */
PUBLIC int	wait		(int * status);

/* lib/exec.c */
PUBLIC int	exec		(const char * path);
PUBLIC int	execl		(const char * path, const char *arg, ...);
PUBLIC int	execv		(const char * path, char * argv[]);

/* lib/stat.c */
PUBLIC int	stat		(const char *path, struct stat *buf);

/* lib/syslog.c */
PUBLIC	int	syslog		(const char *fmt, ...);

/* lib/strequal.c */
PUBLIC int	strequal	(const char * str1,const char * str2);

/* lib/getproc.c */
PUBLIC void 	getproc(struct rt_proc table[],int type, int* begin, int * end);

/* lib/killproc.c */
PUBLIC int	killproc(int pid);

/* lib/gettime.c*/
PUBLIC void 	gettime(struct time* tm);

/* lib/createfile.c */
PUBLIC int 	createfile(char* filename);

/* lib/deletefile.c */
PUBLIC int	deletefile(char* filename);

/* lib/createfile.c */
PUBLIC void init_files();

#endif /* _ORANGES_STDIO_H_ */
