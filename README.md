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

## 4. 功能概述
























