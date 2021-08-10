# ifndef _STACK_H_
# define _STACK_H_

/*=====================================================
 *			说明
 * 由于内存部分还没有完全优雅地实现，即暂时不支持alloc和malloc
 * 也即暂时无法实现链式栈，目前的栈为连续型栈
 *=====================================================*/

# define MAX_SIZE 512   //栈的最大值
# define CH_STACK struct ch_stack   //字符栈
# define DB_STACK struct db_stack   //浮点栈
# define INT_STACK struct int_stack //整型栈

// char stack
struct  ch_stack{
	char stack_area[MAX_SIZE];  //栈区域
	char* top;  //栈顶指针
	int length;
};

// double stack
struct db_stack{
	double stack_area[MAX_SIZE];
	double * top;
	int length;
};

// int stack
struct int_stack{
	int stack_area[MAX_SIZE];
	int * top;
	int length;
};

// push and pop
char ch_push(struct ch_stack* stk, char val);

char ch_pop(struct ch_stack* stk);

double db_push(struct db_stack* stk, double val);

double db_pop(struct db_stack* stk);

int int_push(struct int_stack* stk, int val);

int int_pop(struct int_stack* stk);

//init stack
void init_ch_stack(struct ch_stack* stk);

void init_db_stack(struct db_stack* stk);

void init_int_stack(struct int_stack* stk);

// clear stack
void clear_ch_stack(struct ch_stack* stk);

void clear_db_stack(struct db_stack* stk);

void clear_int_stack(struct int_stack* stk);

//get topData
char stack_ch_data(struct ch_stack* stk);

double stack_db_data(struct db_stack* stk);

int stack_int_data(struct int_stack* stk);

#endif