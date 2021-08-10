// 这是一个简易的计算器
#include "stdio.h"
#include "shell.h"
#include "data_structure/stack.h"
#include "data_structure/queue.h"

//其他函数
//获取栈外值
int getIcp(char data)
{
	int result;
	switch (data)
	{
		case '=':
			result = 0;
			break;
		case '(':
			result = 8;
			break;
		case '+':
		case '-':
			result = 2;
			break;
		case '*':
		case '/':
		case '%':
			result = 4;
			break;
		case '^':
			result = 6;
			break;
		case ')':
			result = 1;
			break;
		default:
			result = -1;
			break;

	}
	return result;
}

//获取栈内值
int getIsp(char data)
{
	int result;
	switch (data)
	{
		case '=':
			result = 0;
			break;
		case '(':
			result = 1;
			break;
		case '+':
		case '-':
			result = 3;
			break;
		case '*':
		case '/':
		case '%':
			result = 5;
			break;
		case '^':
			result = 7;
			break;
		case ')':
			result = 8;
			break;
		default:
			result = -1;
			break;
	}
	return result;
}

//判断一个字符是不是数字
int isNumber(char data)
{
	if((data >= '0')&&(data <= '9'))
		return 1;
	else 
		return 0;
}

// 判断是不是正负号
int isPlusOrMinus(char data)
{
	if(('+' == data)||('-' == data))
		return 1;
	else
		return 0;
}

//判断是不是其他数学符号
int isMathSign(char data)
{
	if(('*' == data) || ('/' == data) || ('%' == data)
	||('^' == data) || ('(' == data) || (')' == data) || ('=' == data))
	{
		return 1;
	}
	else
		return 0;
}

//判断是不是小数点
int isPoint(char data)
{
	return ('.' == data) ? 1 : 0;
}

//中缀字符串转换为后缀字符串
int inToPost(CH_QUEUE* infix_queue, CH_STACK* stack, CH_QUEUE* postfix_queue, INT_QUEUE* isSign,
		INT_QUEUE* bitNum, INT_QUEUE* intNum)
{
	int length = infix_queue -> length;
	int begin;				//循环开始位置
	char frontChar;				//当前队列元素前一个元素的data值
	char temp;				//暂存队列元素
	char data;				//栈顶元素的值
	CH_QUEUE tempQueue;			//暂存小数点中间值的队列
	init_ch_queue(&tempQueue);
       
	if(!infix_queue -> length)   //中缀字符串为空
	{
		return 0;
	}
	else
	{
		ch_push(stack,'=');
		//检测第一个元素的值
		//如果一个字符是数字
		if(isNumber(queue_ch_data(infix_queue)))
		{
			frontChar = queue_ch_data(infix_queue);
			begin = 0;
		}
		//其他字符
		else
		{
			begin = 1;
			temp = ch_out_queue(infix_queue);
			if(isPoint(temp))  //如果是小数点，非法
			{
				return 0;
			}
			else if(isPlusOrMinus(temp))   //是正负号
			{
				frontChar = temp;
				ch_in_queue(postfix_queue,temp);
				int_in_queue(isSign, 1);
				int_in_queue(bitNum,0);
				int_in_queue(intNum,1);
			}
			else if('(' == temp)             //是左括号
			{
				frontChar = temp;
				ch_push(stack, temp);
			}
			else
			{
				return 0;
			}

		}
			//排查后面的元素
		for(int i = begin;i < length; i++)
		{
			temp = ch_out_queue(infix_queue);
			//如果是一个数字
			if(isNumber(temp))
			{
				int num = 1;     //记录这个数的整数位数
				char queue_data;  //暂存整数部分其他位的内容
				frontChar = temp;
				while(isNumber(queue_ch_data(infix_queue)))
				{
					queue_data = ch_out_queue(infix_queue);
					i++;
					frontChar = queue_data;
					ch_in_queue(&tempQueue,queue_data);
					num++;
				}
				ch_in_queue(postfix_queue,temp);
				int_in_queue(isSign, 0);
				int_in_queue(bitNum, 0);
				int_in_queue(intNum, num);
				
				queue_data = ch_out_queue(&tempQueue);
				while(queue_data)
				{
					ch_in_queue(postfix_queue,queue_data);
					int_in_queue(isSign, 0);
					int_in_queue(bitNum, 0);
					int_in_queue(intNum, 1);						
					queue_data = ch_out_queue(&tempQueue);
				}
			}
			//是'+'或'-'
			else if(isPlusOrMinus(temp))
			{
				//前一个字符是数字或是')'则一定是加减号
				if(isNumber(frontChar) || (')' == frontChar))
				{
					data = stack_ch_data(stack);
					frontChar = temp;
					if(getIcp(temp) > getIsp(data)) //进栈
					{
						ch_push(stack , temp);
					}
					else if(getIcp(temp) < getIsp(data))
					{
						while(getIcp(temp) <= getIsp(data))  
						{
							if(getIcp(temp)== getIsp(data)) //遇到左括号和右括号
							{
								data = ch_pop(stack);
								break;
							}
							else
							{
								data = ch_pop(stack);
								ch_in_queue(postfix_queue,data);
								int_in_queue(isSign, 0);
								int_in_queue(bitNum, 0);
								int_in_queue(intNum, 1);									
								data = stack_ch_data(stack);
							}
						}
						if((getIcp(temp) > getIsp(data))&& (temp != ')'))
						{
							ch_push(stack, temp);
						}
					}
					else     //只可能是'(' 与 ')' 或者是两个'='
					{
						data = ch_pop(stack);
					}
				}
				//是正负号
				else
				{
					frontChar = temp;
					ch_in_queue(postfix_queue,temp);
					int_in_queue(isSign, 1);
					int_in_queue(bitNum, 0);
					int_in_queue(intNum, 1);
				}
			}
			// 是其他的数学符号
			else if(isMathSign(temp))
			{
				data = stack_ch_data(stack);
				frontChar = temp;
				if(getIcp(temp) > getIsp(data))     //进栈
				{
					ch_push(stack, temp);
				}
				else if(getIcp(temp) < getIsp(data))
				{
					while(getIcp(temp) <= getIsp(data))
					{
						if(getIcp(temp) == getIsp(data))
						{
							data = ch_pop(stack);
							break;
						}
						else
						{
							data = ch_pop(stack);
							ch_in_queue(postfix_queue,data);
							int_in_queue(isSign, 0);
							int_in_queue(bitNum, 0);
							int_in_queue(intNum, 1);
							data = stack_ch_data(stack);
						}
					}
					if(getIcp(temp) > getIsp(data))
					{
						if(temp != ')')
						{
							ch_push(stack,temp);
						}
						else
						{
							if(data != '(')
							{
								return 0;
							}
						}
					}
				}
				else
				{
					data = ch_pop(stack);
				}
			}
			//是小数点
			else if(isPoint(temp))
			{
				int num = 0;      //用于计算小数点控制的位数
				char queue_data;    //暂存小数点后的数字
				while(isNumber(queue_ch_data(infix_queue)))
				{
					queue_data = ch_out_queue(infix_queue);
					i++;
					frontChar = queue_data;
					ch_in_queue(&tempQueue, queue_data);
					num++;
				}
				ch_in_queue(postfix_queue,temp);
				int_in_queue(isSign, 0);
				int_in_queue(bitNum, num);
				int_in_queue(intNum, 1);
				
				queue_data = ch_out_queue(&tempQueue);
				while(queue_data)
				{
					ch_in_queue(postfix_queue,queue_data);
					int_in_queue(isSign, 0);
					int_in_queue(bitNum, 0);
					int_in_queue(intNum, 1);
					queue_data = ch_out_queue(&tempQueue);
				}
			}
			else                          //输入不合法
			{
				return 0;
			}
		}
		return 1;
		
	}
}

//计算
int calculate(DB_STACK* stack, CH_QUEUE* queue, INT_QUEUE* isSign, INT_QUEUE* bitNum, INT_QUEUE* intNum)
{
	//QueueNode<char> temp;  暂时表示队列节点
	int symbol = 1;   //表示符号位
	double num1;
	double num2;
	double stack_elem = 0;
	double result = 0;

	char temp;
	int tmpIsSign;
	int tmpBitNum;
	int tmpIntNum;

	if(! queue -> length)
	{
		return 0;
	}

	while(queue -> length)
	{
		temp = ch_out_queue(queue);
		tmpIsSign = int_out_queue(isSign);
		tmpBitNum = int_out_queue(bitNum);
		tmpIntNum = int_out_queue(intNum);

		//是一个数学符号但不是正负号，退栈
		if((isMathSign(temp))||((isPlusOrMinus(temp))&&(!tmpIsSign)))
		{
			//能够正常从栈中退出两个数，进行相应的计算
			num2 = db_pop(stack);
			num1 = db_pop(stack);

			switch(temp)
			{
				case '+':
					result = num1 + num2;
					db_push(stack,result);
					break;
				case '-':
					result = num1 - num2;
					db_push(stack,result);
					break;
				case '*':
					result = num1 * num2;
					db_push(stack,result);
					break;
				case '/':
					if(num2 == 0)
					{
						printf("0 can not be divisor!\n");
						return 0;
					}
					else
					{
						result = num1 / num2;
						db_push(stack,result);
						break;
					}
				case '%':
					if(num2 == 0)
					{
						printf("0 can not be divisor!\n");
						return 0;
					}
					else
					{
						result = (int)num1%(int)num2;
						db_push(stack,result);
						break;
					}
				case '^':
					//由于没有引用math.h，这是一个简陋的算法
					if(num2 == 0)
					{
						result = 1;
						db_push(stack,result);
						break;
					}
					else if(num2 > 0)
					{
						double tempData = 1;
						for(int i = 0;i<(int)num2;i++)
						{
							tempData *= num1;
						}
						result = tempData;
						db_push(stack,result);
						break;
					}
					else
					{
						num2 *= -1;
						double tempData = 1;
						for(int i=1; i<(int)num2;i++)
						{
							tempData *= num1;
						}
						result = (double)(1/tempData);
						db_push(stack,result);
						break;
					}
				default:
					return 0;
			}
		}
		//是一个正负号位(符号位)
		else if(tmpIsSign)
		{
			if(isNumber(queue_ch_data(queue)))   //下一个元素是数字
			{
				switch(temp)
				{
					case '+' :
						symbol = 1;
						break;
					case '-' :
						symbol = -1;
						break;
					default:
						return 0;
				}
			}
			else		//下一个元素不是数字，说明存在问题
			{
				return 0;
			}
		}
		//是一个数字
		else if(isNumber(temp))
		{
			double temp1 = 1;
			for(int i=0; i<tmpIntNum-1;i++)
			{
				temp1 *= 10;
			}
			stack_elem += (double)(temp1*(temp - '0'));
			for(int i = tmpIntNum - 2 ; i>=0 ;i--)    //计算整数部分
			{
				temp = ch_out_queue(queue);
				tmpIsSign = int_out_queue(isSign);
				tmpBitNum = int_out_queue(bitNum);
				tmpIntNum = int_out_queue(intNum);

				temp1 = 1;
				for(int j =0; j<i; j++)
				{
					temp1 *= 10;
				}
				stack_elem += (double)(temp1*(temp - '0'));
			}
			if(!isPoint(queue_ch_data(queue)))     //数字下一个元素不是小数点，计算整数部分
			{
				stack_elem *= symbol;
				db_push(stack, stack_elem);
				stack_elem = 0;  //复位操作
				symbol = 1;
			}
			else				//数字下一个是小数点
			{
				temp = ch_out_queue(queue);
				tmpIsSign = int_out_queue(isSign);
				tmpBitNum = int_out_queue(bitNum);
				tmpIntNum = int_out_queue(intNum);

				for(int i=1; i<= tmpBitNum;i++)
				{
					temp = ch_out_queue(queue);
					tmpIsSign = int_out_queue(isSign);
					tmpBitNum = int_out_queue(bitNum);
					tmpIntNum = int_out_queue(intNum);

					temp1 = 1;
					for(int j=0; j<i;j++)
					{
						temp1 *= 0.1;
					}
					stack_elem += (double)(temp1 * (temp - '0'));
				}
				stack_elem *= symbol;
				db_push(stack, stack_elem);
				stack_elem = 0;			//复位操作
				symbol = 1;
			}

		}
		//是小数点
		else if(isPoint(temp))
		{
			//正常情况下，小数点会在遇到数字的时候被删除，若出现则出错
			return 0;
		}
		//以上都不是，那必然是出错了
		else
		{
			return 0;
		}
	}
	return 1;
}


//主函数
int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv; //使用num和argv两个变量来接收argc和argv

	CH_STACK ch_stk;//字符表达式
	init_ch_stack(&ch_stk);

	DB_STACK db_stk;//double表达式
	init_db_stack(&db_stk);

	CH_QUEUE infix_queue;  //中缀表达式
	init_ch_queue(&infix_queue);

	CH_QUEUE postfix_queue;  //后缀表达式
	init_ch_queue(&postfix_queue);

	INT_QUEUE isSign;		//符号位
	init_int_queue(&isSign);

	INT_QUEUE bitNum;
	init_int_queue(&bitNum);

	INT_QUEUE intNum;
	init_int_queue(&intNum);

	//help: -h or --help
	if(num>=2)
	{
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** cal : A calculator.                **\n");
			printf("\t\t** For example : cal 1+1=(or 1+1)     **\n");
			printf("\t\t** You will get : 2		   **\n");
			printf("\t\t****************************************\n");  //40个*

			return 0;
		}
	}

	//calculator
	if(num < 2)
	{
		printf("Please Input an Expression!!\n");
	}
	else
	{
		char ch;
		int i = 0;
		ch = array[1][i];
		while(ch)
		{
			if(ch == '=')
			{
				break;
			}
			else
			{
				ch_in_queue(&infix_queue,ch);
			}
			i++;
			ch = array[1][i];
		}

		ch_in_queue (&infix_queue, '=');
		//进行计算
		if(inToPost(&infix_queue,&ch_stk,&postfix_queue,&isSign ,&bitNum,&intNum))
		{
			if(calculate(&db_stk,&postfix_queue,&isSign,&bitNum,&intNum))
			{
				printf("%lf\n",stack_db_data(&db_stk));
			}
			else
			{
				printf("Please enter the correct expression!!\n");
			}
		}
		else
		{
			printf("Please enter the correct expression!!\n");
		}
	}
	
	return 0;
}
