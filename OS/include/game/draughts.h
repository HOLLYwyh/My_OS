// draughts
#include "stdio.h"
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK_FLAG 1
#define WHITE_FLAG 2
#define BLACK_KING 3
#define WHITE_KING 4

typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define MAX_STEP 15
#define MAX_FLAG 12

#define MAXDEPTH 4 //搜索层数
#define FLAG 5
#define KING 6

#define START "START"
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"
#define EXIT "EXIT"

#define INT_MIN   -100000 
#define INT_MAX   100000
struct Command
{
    int x[MAX_STEP];
    int y[MAX_STEP];
    int numStep;
};

int myFlag;
int otherFlag;
int myKing;
int otherKing;

//相关函数
//初始化结构体
void init_command(struct Command* cmd);

//打印棋盘
void printBoard();

//判断边界
BOOL isInBound(int x, int y);

//判断方向
void judgeDir(int x, int y);

//走子
int tryToMove(int x, int y, int tempi);

//记录中间被吃掉子的情况
void noteMap(struct Command cmd[]);

// 退回被吃掉的棋子
void backMap(int backmap[], struct Command backCommand);

//尝试吃子并找出最长的吃子路径
int tryToJump(int x, int y, int currentStep, int curFlag);

//判断王棋
void judgeKing();

//走子
void place(struct Command cmd);

//回退
void backPlace(struct Command cmd, struct Command backCommand, int tempMap[], int num);

//游戏结束
int gameOver(int curFlag);

//估值函数
int evaluation(int curFlag);

int checkKing(struct Command cmd);

int checkMyChessMove(int depth, int curFlag);

int checkOtherChessMove(int depth, int curFlag);

//开局检查是否能够吃子
int checkMyChessJump();

//进行能够吃子时的模拟走子
int  makeMyChessJump(int depth, int curFlag);

//开局检查是否能够吃子
int checkOtherChessJump();

int makeOtherChessJump(int depth, int curFlag);

//负极大值搜索
int negaMaxSearch(int depth, int curFlag);

struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me);

void turn();

void end(int x);

void loop();

int draughts();
