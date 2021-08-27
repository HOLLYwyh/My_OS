# HearthStone_OS--操作系统课程设计文档
## 1. 项目概述
### 1.1 项目简介
   本项目以Orange's操作系统作为基本框架，完成了三个系统级应用：多功能控制台、进程管理和文件管理。同时，还实现了15个用户级应用。包括计算器、日历、国际跳棋小游戏和touch、rm、cat、ps等常用Shell指令。系统将根据输入的命令进行不同的操作。  
   额外的，项目还有许多附加的小功能，例如开机动画等。  
### 1.2 项目配置
编写语言：汇编语言、C语言  
开发环境：Linux系统下的Bochs2.6.11  
运行环境：Ubuntu20.04  
### 1.3 小组成员
1953608 吴英豪  
### 1.4 项目地址
github地址： https://github.com/HOLLYwyh/My_OS  
## 2. 如何运行项目
### 2.1 安装Bochs
详见CSDN博客：https://blog.csdn.net/kuang_tian_you/article/details/81412364  
### 2.2 配置工作环境
- 进入到OS文件夹中  
- 修改bochsrc,将下图中的romimage、vgaromimage工作路径更换为自己的工作路径(bochs 安装路径)  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/bochsrc.png)  
### 2.3 挂载硬盘
- 由于挂载指令已经写在了OS文件夹下的Makefile中，用户无需输入更多内容。  
- 在OS文件夹下新建一个文件夹mnt，在mnt文件夹中新建一个floppy文件夹即可。  
即建立/OS/mnt/floppy  
### 2.4 运行操作系统
- 在OS目录下输入  
```
bochs  -f bochsrc
```
再输入 6 并输入c启动项目  
## 3. 操作说明
### 3.1开机动画
在开机过程中会有短暂的开机动画  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/开机动画.png)  
这里只截其中的一张图  
### 3.2主界面
- 下图为主界面  
- 按下按钮F1，F2，F3可以切换到不同的终端窗口  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/主界面.png)  
### 3.3 帮助功能
1. 在终端中输入 details 可以查看与操作系统相关的详细信息  
```
details
```
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/details.png)  
2. 在终端中输入cmd可以查看所有的shell指令和用户级应用指令  
```
cmd
```
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/cmd.png)  
3. 对任意指令 xx,可以输入 
```
xx -h
```
或
```
xx --help
```
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/-h.png)  
查看此指令的使用方法  
4. 按键盘的上下方向键可以上下翻页  
### 3.4 执行程序
输入相应的指令即可执行程序
1. echo  
功能： 输出用户输入的内容  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/echo.png)  
2. pwd  
功能：查看当前路径  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/pwd.png)  
3. author  
功能： 查看操作系统的作者  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/author.png)  
4. cal  
功能：计算器  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/cal.png)  
5. cmd  
功能：查看所有指令  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/cmd.png)  
6. ps  
功能：查看所有进程  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/ps.png)  
7. kill
功能：终止进程  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/kill.png)  
8. time  
功能：查看当前时间  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/time.png)  
9. touch  
功能：新建文件  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/touch.png)  
10. rm  
功能：删除文件  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/rm.png)  
11. ls  
功能：列举所有的文件  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/ls.png)  
12. cat  
功能：查看文件信息  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/cat.png)  
13. write
功能：写文件  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/write.png)  
14. details
功能：查看操作系统详细信息  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/details.png)  
15. game  
功能：玩游戏  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/draughts.png)  
16. 输入其他内容  
Shell会检测用户的输入并给出一定的提示  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/cmd_not_found.png)  
## 4. 操作系统设计与描述
### 4.1总体设计
1. 采用微内核，进程之间通过发送与接收消息的方式来传递消息。  
2. 采用分页的方式来管理磁盘。  
3. 内存共32M，10M的系统内存，22M的用户内存。  
4. 通过将程序压缩成压缩包后解压的方式安装程序。  

### 4.2进程设计
### 4.2.1 系统进程(Ring 0)
Ring0级别的系统进程有：  
- TTY(控制中断程序)  
- SYS(控制系统进程、时间等)  
- HD(控制硬件的读写)  
- FS(控制文件系统)  
- MM(控制内存管理，内存分配等)  
### 4.2.2 用户进程(Ring 1)
Ring1级别的用户级进程有：  
- Init(所有用户级进程的祖先)
- ps_monitor(实时监控进程，以防止进程错误)  
- fs_monitor(实时监控文件系统，以防止文件系统的错误)  
- mm_monitor(实时监控内存，以防止内存的错误)  
### 4.2.3 用户进程(Ring 3)
由进程fork()而成的进程，可以被终止。  
### 4.2.4 进程调度
进程调度采用时间片轮转法和非抢占式优先级调度的方式。  
- 当时间片时间结束之后，系统将选择优先级最高的进程执行  
- 当前进程因等待消息而阻塞时，系统将选择优先级最高的进程执行。  

### 4.3 文件系统设计
- 将磁盘的一部分开辟为系统的硬件区域，并将系统的文件挂载在磁盘上。  
- 采用分页的形式来管理磁盘文件。  
### 4.4 内存设计
- 内存共32M，10M的系统内存，22M的用户内存。  
- 每一个进程都会分配一定的内存单元，以确保系统的正常运行。  
### 4.5 Shell设计
首先创建名为shell对应指令的文件，将其安装在磁盘中，当用户输入对应指令之后，系统会
查找磁盘，fork()产生一个子进程并执行程序。执行完毕之后，子进程释放，返回父进程。  



















