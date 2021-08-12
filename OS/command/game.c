// All Games
#include "stdio.h"
#include "shell.h"
#include "game/draughts.h"

int main(int argc, char* argv[])
{
	int num = argc;
	char ** array = argv;  //使用num和argv两个变量来接收argv和argv

	if(num == 2)
	{
		//help: -h or --help
		if((strequal(array[1],help1))||(strequal(array[1],help2)))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**                Help                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** game : All Games Related           **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** game --all: see all games          **\n");
			printf("\t\t** 			           **\n");
			printf("\t\t** game [gameName] -h (or --help)     **\n");
			printf("\t\t**      -- details about the gameName **\n");
			printf("\t\t** 				   **\n");
			printf("\t\t** game gameName: start the game      **\n");
			printf("\t\t****************************************\n");  //40个*
			return 0;
		}
		//all: --all
		else if(strequal(array[1],all))
		{
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t**           Game List                **\n");
			printf("\t\t****************************************\n");  //40个*
			printf("\t\t** 1- draughts			**\n");
			printf("\t\t** 	:Play draughts with AI.    **\n");
			printf("\t\t****************************************\n");  //40个*
			return 0;
		}
		//draughts
		else if(strequal(array[1],"draughts"))
		{
			draughts();
		}
	}
	else if(num == 3)
	{
		//draughts --help or draughts -h
		if(strequal(array[1],"draughts")&&((strequal(array[2],help1))||(strequal(array[2],help2))))
		{
			printf("\n");
			printf("* Start the game:\n");
			printf("\tPress 'game draughts' to start the game.\n\n");
			printf("* Description:\n");
			printf("\tThis is a little draughts game,you can \n");
			printf("\tchoose Black chess(X) or White chess(O)\n");
			printf("\tto play with the computer.\n\n");
			printf("* Playing method:\n");
			printf("\t 1.start: Press 'START' to start the game\n");
			printf("\t          then press 1 or 2 to choose the camp\n");
			printf("\t          1 -- White Chess  2-- Black Chess.\n");
			printf("\t 2.AI move and player move:\n");
			printf("\t          Press 'TURN' to let AI move.\n");
			printf("\t          Press 'PLACE' to move:\n");
			printf("\t          First input the number of steps\n");
			printf("\t          Second input the path coordinate\n");
			printf("\t          for example :'PLACE 2 3 0 4 1'\n");
			printf("\t 3.end game:\n");
			printf("\t          Press 'END num' to end the game\n");
			printf("\t          'num' can be 1 or 2\n");
			printf("\t          1--BLACK chess wins,2--WHITE chess wins.\n");
			printf("\t 4.exit:\n");
			printf("\t          Press 'EXIT' to exit the game\n");
		}
	}
	else
	{
		printf("Welcome to the games!!\n");
		printf("\t Press 'game -h' or 'game --help' to see the details.\n");
	}

}
