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
### 2.3 运行操作系统
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

10. rm  
功能：删除文件  

11. ls  
功能：列举所有的文件  

12. cat  
功能：查看文件信息  

13. write
功能：写文件  

14. details
功能：查看操作系统详细信息  
![Image text](https://github.com/HOLLYwyh/My_OS/blob/main/pictures/details.png)  
15. game  
功能：玩游戏  

16. 输入其他内容  
Shell会检测用户的输入并给出一定的提示  

## 4. 操作系统设计与描述
### 4.1进程设计

### 4.2 文件系统设计

### 4.3 内存设计

### 4.4 Shell设计




















