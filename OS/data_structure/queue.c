# include "data_structure/queue.h"
# include "stdio.h"

// init queue
void init_ch_queue(struct ch_queue* queue)
{
	queue -> top = queue -> queue_area;
	queue -> tail = queue -> queue_area;
	queue -> length = 0;
}

void init_db_queue(struct db_queue* queue)
{
	queue -> top = queue -> queue_area;
	queue -> tail = queue -> queue_area;
	queue -> length = 0;
}

void init_int_queue(struct int_queue* queue)
{
	queue -> top = queue -> queue_area;
	queue -> tail = queue -> queue_area;
	queue -> length = 0;
}

// in queue
char ch_in_queue(struct ch_queue* queue, char val)
{
	if(queue -> length >= MAX_SIZE)
	{
		return val;
	}
	else
	{
		queue -> length++;
		*(queue -> tail) = val;
		queue -> tail ++;
		if((queue->tail - queue->queue_area)/sizeof(val) >= MAX_SIZE)  //回到起点
		{
			queue->tail = queue->queue_area;
		}
		return val;
	}
}

double db_in_queue(struct db_queue* queue, double val)
{
	if(queue -> length >= MAX_SIZE)
	{
		return val;
	}
	else
	{
		queue -> length++;
		*(queue -> tail) = val;
		queue -> tail ++;
		if((queue->tail - queue->queue_area)/sizeof(val) >= MAX_SIZE)  //回到起点
		{
			queue->tail = queue->queue_area;
		}
		return val;
	}
}

int int_in_queue(struct int_queue* queue, int val)
{
	if(queue -> length >= MAX_SIZE)
	{
		return val;
	}
	else
	{
		queue -> length++;
		*(queue -> tail) = val;
		queue -> tail ++;
		if((queue->tail - queue->queue_area)/sizeof(val) >= MAX_SIZE)  //回到起点
		{
			queue->tail = queue->queue_area;
		}
		return val;
	}
}

// out queue
char ch_out_queue(struct ch_queue* queue)
{
	if(queue -> length <= 0)
	{
		return 0;
	}
	else
	{
		char result;
		queue ->length--;
		result = *(queue->top);
		queue-> top ++;
		if((queue->top - queue->queue_area)/sizeof(result) >= MAX_SIZE)
		{
			queue -> top = queue -> queue_area;
		}
		return result;
	}
}

double db_out_queue(struct db_queue* queue)
{
	if(queue -> length <= 0)
	{
		return 0;
	}
	else
	{
		double result;
		queue ->length--;
		result = *(queue->top);
		queue-> top ++;
		if((queue->top - queue->queue_area)/sizeof(result) >= MAX_SIZE)
		{
			queue -> top = queue -> queue_area;
		}
		return result;
	}
}

int int_out_queue(struct int_queue* queue)
{
	if(queue -> length <= 0)
	{
		return 0;
	}
	else
	{
		int result;
		queue ->length--;
		result = *(queue->top);
		queue-> top ++;
		if((queue->top - queue->queue_area)/sizeof(result) >= MAX_SIZE)
		{
			queue -> top = queue -> queue_area;
		}
		return result;
	}
}

// clear queue
void clear_ch_queue(struct ch_queue* queue)
{
	queue-> tail = queue->top = queue ->queue_area;
	queue-> length = 0;
}

void clear_db_queue(struct db_queue* queue)
{
	queue-> tail = queue->top = queue->queue_area;
	queue-> length = 0;
}

void clear_int_queue(struct int_queue* queue)
{
	queue-> tail = queue->top = queue->queue_area;
	queue-> length = 0;
}

//get topData
char queue_ch_data(struct ch_queue* queue)
{
	if(queue->length == 0)
	{
		return 0;
	}
	else
	{
		return *(queue->top);
	}
}

double queue_db_data(struct db_queue* queue)
{
	if(queue->length ==0)
	{
		return 0;
	}
	else
	{
		return *(queue->top);
	}
}

int queue_int_data(struct int_queue* queue)
{
	if(queue->length == 0)
	{
		return 0;
	}
	else
	{
		return *(queue->top);
	}
}