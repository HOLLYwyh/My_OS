# include "data_structure/stack.h"
# include "stdio.h"

char ch_push(struct ch_stack* stk, char val)
{
	if(stk -> length >= MAX_SIZE)
	{
		return val;
	}
	else
	{
		*(stk -> top) = val;
		stk -> length++;
		stk -> top++;
		return val;
	}
}

char ch_pop(struct ch_stack* stk)
{
	if(stk -> length <= 0)
	{
		return 0;
	}
	else
	{
		stk -> length--;
		stk -> top--;
		char result = *(stk ->top);
		return result;
	}
}

double db_push(struct db_stack* stk , double val)
{
	if(stk -> length >= MAX_SIZE)
	{
		return val;
	}
	else
	{
		*(stk -> top) = val;
		stk -> length++;
		stk -> top++;
		return val;
	}
}

double db_pop(struct db_stack* stk)
{
	if(stk -> length <= 0)
	{
		return 0;
	}
	else
	{
		stk -> length--;
		stk -> top--;
		double result = *(stk -> top);
		return result;
	}
}

int int_push(struct int_stack* stk, int val)
{
	if(stk -> length >= MAX_SIZE)
	{
		return val;
	}
	else
	{
		*(stk -> top) = val;
		stk -> length++;
		stk -> top++;
		return val;
	}
}

int int_pop(struct int_stack* stk)
{
	if(stk -> length <= 0)
	{
		return 0;
	}
	else
	{
		stk -> length--;
		stk -> top--;
		int result = *(stk -> top);
		return result;
	}
}

//init_stack
void init_ch_stack(struct ch_stack* stk)
{
	stk -> top = stk -> stack_area;
	stk -> length = 0;
}

void init_db_stack(struct db_stack* stk)
{
	stk -> top = stk -> stack_area;
	stk -> length = 0;
}

void init_int_stack(struct int_stack* stk)
{
	stk -> top = stk -> stack_area;
	stk -> length = 0;
}

//clear_stack
void clear_ch_stack(struct ch_stack* stk)
{
	stk -> top = stk ->stack_area;
	stk -> length = 0;
}

void clear_db_stack(struct db_stack* stk)
{
	stk -> top = stk -> stack_area;
	stk ->length = 0;
}

void clear_int_stack(struct int_stack* stk)
{
	stk -> top = stk -> stack_area;
	stk -> length = 0;
}

// get topData
char stack_ch_data(struct ch_stack* stk)
{
	if(stk -> length ==0)
	{
		return 0;
	}
	else
	{ 	
		return *((stk ->top) - 1);
	}
}

double stack_db_data(struct db_stack* stk)
{
	if(stk -> length == 0)
	{
		return 0;
	}
	else
	{
		return *((stk -> top) - 1);
	}
}

int stack_int_data(struct int_stack* stk)
{
	if(stk -> length == 0)
	{
		return 0;
	}
	else
	{
		return *((stk -> top) - 1);
	}
}

