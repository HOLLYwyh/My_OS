#include "game/draughts.h"

int iFirst = 0, iLast = 0;//判断棋子移动方向

int moveDir[4][2] = { {1, -1}, {1, 1}, {-1, -1}, {-1, 1} };//移动方向左下，右下，左上，右上
int jumpDir[4][2] = { {2, -2}, {2, 2}, {-2, -2}, {-2, 2} };
struct Command moveCmd;
struct Command jumpCmd;
struct Command finalCmd;//存储最终的最优路径

char board[BOARD_SIZE][BOARD_SIZE] = { 0 };

//判断吃子数相同的最佳路径
struct Command longestJump[MAX_FLAG];
int jumpNum = 0;
struct Command otherMap[MAX_FLAG];
int anotherTempMap [MAX_FLAG][MAX_FLAG]= { 0 };

//初始化结构体
void init_command(struct Command* cmd)
{
    for(int i=0;i<MAX_STEP;i++)
    {
        cmd->x[i] = 0;
        cmd->y[i] = 0;
    }
    cmd ->numStep =0;
}

//打印棋盘
void printBoard()
{
    char visualBoard[BOARD_SIZE][BOARD_SIZE + 1] = { 0 };
    printf("=========\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            switch (board[i][j])
            {
            case EMPTY:
                visualBoard[i][j] = '.';
                break;
            case WHITE_FLAG:
                visualBoard[i][j] = 'O';
                break;
            case BLACK_FLAG:
                visualBoard[i][j] = 'X';
                break;
            case WHITE_KING:
                visualBoard[i][j] = '@';
                break;
            case BLACK_KING:
                visualBoard[i][j] = '*';
                break;
            default:
                break;
            }
        }
        printf("%s\n", visualBoard[i]);
    }
    printf("=========\n");
}

//判断边界
BOOL isInBound(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

//判断方向
void judgeDir(int x, int y)
{
    switch (board[x][y])
    {
    case BLACK_FLAG:
    {
        iFirst = 2;
        iLast = 3;
        break;
    }
    case WHITE_FLAG:
    {
        iFirst = 0;
        iLast = 1;
        break;
    }
    case BLACK_KING:
    case WHITE_KING:
    {
        iFirst = 0;
        iLast = 3;
        break;
    }
    }
}

//走子
int tryToMove(int x, int y, int tempi)//移动方向左下，右下，左上，右上
{
    int newX, newY;
    newX = x + moveDir[tempi][0];
    newY = y + moveDir[tempi][1];
    if (isInBound(newX, newY) && board[newX][newY] == EMPTY)
    {
        moveCmd.x[0] = x;
        moveCmd.y[0] = y;
        moveCmd.x[1] = newX;
        moveCmd.y[1] = newY;
        return TRUE;
    }
    else
        return FALSE;
}

//记录中间被吃掉子的情况
void noteMap(struct Command cmd[])
{
    int midX, midY;
    for (int i = 0; i <=jumpNum; i++)
    {
        for (int j = 0; j < cmd[i].numStep - 1; j++)
        {
            midX = (cmd[i].x[j] + cmd[i].x[j + 1]) / 2;
            midY = (cmd[i].y[j] + cmd[i].y[j + 1]) / 2;
            anotherTempMap[i][j] = board[midX][midY];
            otherMap[i].x[j] = midX;
            otherMap[i].y[j] = midY;
            otherMap[i].numStep++;
        }
    }
}

//退回被吃掉的棋子
void backMap(int backmap[], struct Command backCommand)
{
    for (int i = 0; i < backCommand.numStep; i++)
    {
        board[backCommand.x[i]][backCommand.y[i]] = backmap[i];
    }
}

int judgeJump(int midX, int midY, int curFlag)
{
    if ((board[midX][midY] != EMPTY) && (isInBound(midX, midY)))
    {
        if ((curFlag % 2) != 0)//说明当前是黑子
        {
            if ((board[midX][midY] % 2) == 0)//说明被吃的是白子
                return TRUE;
            else return FALSE;
        }
        else//说明是白棋
        {
            if ((board[midX][midY] % 2) != 0)//说明被吃掉的是黑子
                return TRUE;
            else return FALSE;
        }
    }
    else return FALSE;

}

//尝试吃子并找出最长的吃子路径
int tryToJump(int x, int y, int currentStep, int curFlag)
{
    int newX, newY, midX, midY, k = 0;
    char tmpFlag;
    jumpCmd.x[currentStep] = x;
    jumpCmd.y[currentStep] = y;
    jumpCmd.numStep++;
    for (int i = 0; i < 4; i++)
    {
        newX = x + jumpDir[i][0];
        newY = y + jumpDir[i][1];
        midX = (x + newX) / 2;
        midY = (y + newY) / 2;
        if (isInBound(newX, newY) && (judgeJump(midX, midY, curFlag)) && (board[newX][newY] == EMPTY))
        {
            board[newX][newY] = board[x][y];
            board[x][y] = EMPTY;
            tmpFlag = board[midX][midY];
            board[midX][midY] = EMPTY;
            k = tryToJump(newX, newY, currentStep + 1, curFlag);
            board[x][y] = board[newX][newY];
            board[newX][newY] = EMPTY;
            board[midX][midY] = tmpFlag;
        }
    }
    if ((jumpCmd.numStep == longestJump[jumpNum].numStep) && (longestJump[jumpNum].numStep > 1))//找到最大吃子数相同的不同路径
    {
        jumpNum++;
        memcpy(&longestJump[jumpNum], &jumpCmd, sizeof(jumpCmd));
    }
    if (jumpCmd.numStep > longestJump[jumpNum].numStep)
    {
        jumpNum = 0;
        memcpy(&longestJump[jumpNum], &jumpCmd, sizeof(jumpCmd));
    }
    jumpCmd.numStep--;
    return (longestJump[jumpNum].numStep > 1) ? TRUE : FALSE;
}

//判断王棋
void judgeKing()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == BLACK_FLAG)
        {
            board[0][i] = BLACK_KING;
        }
        if (board[BOARD_SIZE - 1][i] == WHITE_FLAG)
        {
            board[BOARD_SIZE - 1][i] = WHITE_KING;
        }
    }
}

//走子
void place(struct Command cmd)
{
    int midX, midY, curFlag;
    curFlag = board[cmd.x[0]][cmd.y[0]];
    for (int i = 0; i < cmd.numStep - 1; i++)
    {
        board[cmd.x[i]][cmd.y[i]] = EMPTY;
        board[cmd.x[i + 1]][cmd.y[i + 1]] = curFlag;
        if ((cmd.x[i] - cmd.x[i + 1] == 2)||(cmd.x[i] - cmd.x[i+1] == -2))
        {
            midX = (cmd.x[i] + cmd.x[i + 1]) / 2;
            midY = (cmd.y[i] + cmd.y[i + 1]) / 2;
            board[midX][midY] = EMPTY;
        }
    }
    judgeKing();
}

//回退
void backPlace(struct Command cmd, struct Command backCommand, int tempMap[], int num)
{
    int x = cmd.x[cmd.numStep - 1], y = cmd.y[cmd.numStep - 1];
    char tempFlag;
    tempFlag = board[x][y];
    if (num == 1)
    {
        board[x][y] -= 2;
        tempFlag = board[x][y];
    }
    board[x][y] = EMPTY;
    board[cmd.x[0]][cmd.y[0]] = tempFlag;
    backMap(tempMap, backCommand);

}

//游戏结束
int gameOver(int curFlag)
{
    int myTemp = 0; int otherTemp = 0;
    int myMove = 0; int otherMove = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((board[i][j] == myFlag) || (board[i][j] == myKing))
            {
                myTemp++;
                judgeDir(i, j);
                for (int mi = iFirst, mj = iLast; mi <= mj; mi++)
                    myMove += tryToMove(i, j, mi);
            }
            if ((board[i][j] == otherFlag) || (board[i][j] == otherKing))
            {
                otherTemp++;
                judgeDir(i, j);
                for (int oi = iFirst, oj = iLast; oi <= oj; oi++)
                    otherMove += tryToMove(i, j, oi);
            }
        }
    }
    if (((otherTemp == 0) || (myTemp == 0)) && (curFlag == myFlag))
    {
        return TRUE;
    }
    else if (((otherMove == 0) || (myMove == 0)) && (curFlag == otherFlag))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//估值函数
int evaluation(int curFlag)
{
    int otherValue = 0, myValue = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((board[i][j] == myFlag) || (board[i][j] == myKing))
                myValue += (board[i][j] == myFlag) ? 50 : 100;
            if ((board[i][j] == otherFlag) || (board[i][j] == otherKing))
                otherValue += (board[i][j] == otherFlag) ? 40 : 80;
        }
    }
    return (curFlag == myFlag) ? (myValue - otherValue) : (otherValue - myValue);
}

int checkKing(struct Command cmd)
{
    char curFlag = board[cmd.x[0]][cmd.y[0]];
    int num = 0;
    if (curFlag <= WHITE_FLAG)
    {
        if ((cmd.x[cmd.numStep - 1] == 0) && (curFlag == BLACK_FLAG))
            num = 1;
        if ((cmd.x[cmd.numStep - 1] == 7) && (curFlag == WHITE_FLAG))
            num = 1;
    }
    return num;
}


int checkMyChessMove(int depth, int curFlag)
{
    int negaMaxSearch(int depth, int curFlag);
    int best = INT_MIN, value = INT_MIN, bestValue = INT_MIN, num = 0;
    struct Command commandMove;
    struct Command commandBack;
    int backMap[MAX_FLAG] = { 0 };
    init_command(&commandMove);
    init_command(&commandBack);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((board[i][j] == myFlag) || (board[i][j] == myKing))
            {
                judgeDir(i, j);
                for (int mi = iFirst, mj = iLast; mi <= mj; mi++)
                {
                    if (tryToMove(i, j, mi))//说明可以在这个方向上移动
                    {
                        memcpy(&commandMove, &moveCmd, sizeof(moveCmd));
                        num = checkKing(commandMove);
                        place(commandMove);


                        value = -negaMaxSearch(depth - 1, 3 - curFlag);
                        backPlace(commandMove, commandBack, backMap, num);

                        if (value >= best)
                            best = value;
                        if ((depth == MAXDEPTH) && (best > bestValue))//说明回溯到最初层
                        {
                            bestValue = best;
                            memcpy(&finalCmd, &commandMove, sizeof(commandMove));
                        }
                    }
                }
            }
        }
    }
    return(depth == MAXDEPTH) ? bestValue : best;
}


int checkOtherChessMove(int depth, int curFlag)
{
    int negaMaxSearch(int depth, int curFlag);
    int best = INT_MIN, value = INT_MIN, num = 0;
    struct Command commandMove;
    struct Command commandBack;
    int backMap[MAX_FLAG] = { 0 };
    init_command(&commandMove);
    init_command(&commandBack);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((board[i][j] == otherFlag) || (board[i][j] == otherKing))
            {
                judgeDir(i, j);
                for (int oi = iFirst, oj = iLast; oi <= oj; oi++)
                {
                    if (tryToMove(i, j, oi))
                    {
                        memcpy(&commandMove, &moveCmd, sizeof(moveCmd));
                        num = checkKing(commandMove);
                        place(commandMove);

                        value = -negaMaxSearch(depth - 1, 3 - curFlag);
                        backPlace(commandMove, commandBack, backMap, num);

                        if (value >= best)
                            best = value;
                    }
                }
            }
        }
    }
    return best;
}

//开局检查是否能够吃子
int checkMyChessJump()
{
    int negaMaxSearch(int depth, int curFlag);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((board[i][j] == myFlag) || (board[i][j] == myKing))
            {
                int k = tryToJump(i, j, 0, myFlag);
            }
        }
    }
    memset(&otherMap, 0, sizeof(otherMap));
    noteMap(longestJump);
    return (longestJump[jumpNum].numStep > 1) ? 1 : 0;
}

//进行能够吃子时的模拟走子
int  makeMyChessJump(int depth, int curFlag)
{
    int negaMaxSearch(int depth, int curFlag);
    int best = INT_MIN, value = INT_MIN,bestValue = INT_MIN, num = 0,tempJumpNum = 0;
    struct Command commandJump[MAX_FLAG];
    struct Command commandBack[MAX_FLAG];
    int backMap[MAX_FLAG][MAX_FLAG] = { 0 };
    for(int i=0;i<MAX_FLAG;i++)
    {
        init_command(&commandJump[i]);
        init_command(&commandBack[i]);
    }
    tempJumpNum = jumpNum;
    memcpy(backMap, anotherTempMap, sizeof(anotherTempMap));
    memcpy(&commandJump, &longestJump, sizeof(longestJump));
    memcpy(&commandBack, &otherMap, sizeof(otherMap));
    for(int i = 0; i <=tempJumpNum; i++)
    {       
        num = checkKing(commandJump[i]);
        place(commandJump[i]);

        value = -negaMaxSearch(depth - 1, 3 - curFlag);
        backPlace(commandJump[i], commandBack[i], backMap[i], num);

        if (value >= best)
            best = value;
        if ((depth == MAXDEPTH) && (best > bestValue))//说明回溯到最初层
        {
            bestValue = best;
            memcpy(&finalCmd, &commandJump[i], sizeof(finalCmd));
        }
    }
    return(depth == MAXDEPTH) ? bestValue : best;
}

//开局检查是否能够吃子
int checkOtherChessJump()
{
    int negaMaxSearch(int depth, int curFlag);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((board[i][j] == otherFlag) || (board[i][j] == otherKing))
            {
                int k = tryToJump(i, j, 0, otherFlag);
            }
        }
    }
    memset(&otherMap, 0, sizeof(otherMap));
    noteMap(longestJump);
    return (longestJump[jumpNum].numStep > 1) ? 1 : 0;
}

int makeOtherChessJump(int depth, int curFlag)
{
    int negaMaxSearch(int depth, int curFlag);
    int best = INT_MIN, value = INT_MIN, bestValue = INT_MIN, num = 0, tempJumpNum = 0;
    struct Command commandJump[MAX_FLAG];
    struct Command commandBack[MAX_FLAG];
    int backMap[MAX_FLAG][MAX_FLAG] = { 0 };
    for(int i=0;i<MAX_FLAG;i++)
    {
        init_command(&commandJump[i]);
        init_command(&commandBack[i]);
    }
    tempJumpNum = jumpNum;
    memcpy(backMap, anotherTempMap, sizeof(anotherTempMap));
    memcpy(&commandJump, &longestJump, sizeof(longestJump));
    memcpy(&commandBack, &otherMap, sizeof(otherMap));
    for (int i = 0; i <=tempJumpNum; i++)
    {
        num = checkKing(commandJump[i]);
        place(commandJump[i]);

        value = -negaMaxSearch(depth - 1, 3 - curFlag);
        backPlace(commandJump[i], commandBack[i], backMap[i], num);

        if (value >= best)
            best = value;
    }
    return best;
}

//负极大值搜索
int negaMaxSearch(int depth, int curFlag)
{
    int best = INT_MIN;
    jumpNum = 0;
    longestJump[jumpNum].numStep = 1;
    if (gameOver(curFlag))//如果游戏结束
    {
        return evaluation(curFlag);
    }
    if (depth <= 0)//如果已经到了搜索树叶子结点
    {
        return evaluation(curFlag);
    }
    if (curFlag == myFlag)//如果是己方棋子走子
    {
        if (checkMyChessJump())//如果自己开局就能吃子
            best = makeMyChessJump(depth, myFlag);//吃子
        else//说明不能吃子
            best = checkMyChessMove(depth, myFlag);
    }
    if (curFlag == otherFlag)//如果是对方棋子走子
    {
        if (checkOtherChessJump())//如果自己开局就能吃子
            best = makeOtherChessJump(depth, otherFlag);//吃子
        else//说明不能吃子
            best = checkOtherChessMove(depth, otherFlag);
    }
    return best;
}

struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
    int value = INT_MIN;
    memset(&finalCmd, 0, sizeof(finalCmd));
    jumpNum = 0;
    longestJump[jumpNum].numStep = 1;

    value = negaMaxSearch(MAXDEPTH, myFlag);
    return finalCmd;
}

void start(int flag)
{
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j += 2)
        {
            board[i][j + (i + 1) % 2] = WHITE_FLAG;
        }
    }
    for (int i = 5; i < 8; i++)
    {
        for (int j = 0; j < 8; j += 2)
        {
            board[i][j + (i + 1) % 2] = BLACK_FLAG;
        }
    }
}

void turn()
{
    struct Command command = aiTurn((const char(*)[BOARD_SIZE])board, myFlag);
    place(command);
    printf("%d", command.numStep);
    for (int i = 0; i < command.numStep; i++)
    {
        printf(" %d,%d", command.x[i], command.y[i]);
    }
    printf("\n");
}

void end(int x)
{
    printf("Game Exits\n");
    exit(0);
}

void loop()
{
    char tag[10] = { 0 };
    struct Command command;
    int status;
    init_command(&command);
    while (TRUE)
    {
        memset(tag, 0, sizeof(tag));
        scanf("%s", tag);
        if (strcmp(tag, START) == 0)
        {
            scanf("%d", &myFlag);
            otherFlag = 3 - myFlag;
            myKing = myFlag + 2;
            otherKing = otherFlag + 2;
            start(myFlag);
            printf("OK\n");
        }
        else if (strcmp(tag, PLACE) == 0)
        {
            scanf("%d", &command.numStep);
            for (int i = 0; i < command.numStep; i++)
            {
                scanf("%d%d", &command.x[i], &command.y[i]);
            }
            place(command);
        }
        else if (strcmp(tag, TURN) == 0)
        {
            turn();
        }
        else if (strcmp(tag, END) == 0)
        {
            scanf("%d", &status);
            end(status);
        }
        else if(strcmp(tag, EXIT) == 0)
        {
            end(status);
        }

        printBoard();

    }
}

// 跳棋主函数
int draughts()
{
    init_command(&jumpCmd);
    init_command(&finalCmd);
    init_command(&moveCmd);
    for(int i=0;i<MAX_FLAG;i++)
    {
        init_command(&longestJump[i]);
        init_command(&otherMap[i]);
    }
    moveCmd.numStep = 2;

    printf("Draughts begins!\n");
    loop();
    return 0;
}
