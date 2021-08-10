# ifndef _QUEUE_H_
# define _QUEUE_H_

/*====================================================
 *		    说明
 * 由于内存部分还没有完全优雅地实现，即暂时不支持alloc和malloc
 * 也即暂时无法实现链式队列，目前的队列为连续型队列
 *===================================================*/

 # define MAX_SIZE 512
 # define CH_QUEUE struct ch_queue  //字符栈
 # define DB_QUEUE struct db_queue  //浮点队列
 # define INT_QUEUE struct int_queue //整型栈

// char queue
struct ch_queue{
	char queue_area[MAX_SIZE];
	char* top;
	char* tail;
	int length;
};

// double queue
struct db_queue{
	double queue_area[MAX_SIZE];
	double* top;
	double* tail;
	int length;
};

// int queue
struct int_queue{
	int queue_area[MAX_SIZE];
	int* top;
	int* tail;
	int length;
};

// init queue
void init_ch_queue(struct ch_queue* queue);

void init_db_queue(struct db_queue* queue);

void init_int_queue(struct int_queue* queue);

// in queue
char ch_in_queue(struct ch_queue* queue , char val);

double db_in_queue(struct db_queue* queue , double val);

int int_in_queue(struct int_queue* queue , int val);

// out queue
char ch_out_queue(struct ch_queue* queue);

double db_out_queue(struct db_queue* queue);

int int_out_queue(struct int_queue* queue);

// clear queue
void clear_ch_queue(struct ch_queue* queue);

void clear_db_queue(struct db_queue* queue);

void clear_int_queue(struct int_queue* queue);

//get topData
char queue_ch_data(struct ch_queue* queue);

double queue_db_data(struct db_queue* queue);

int queue_int_data(struct int_queue* queue);

 # endif