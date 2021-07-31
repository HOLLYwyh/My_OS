# Chapter9
## 一、相关概念
- 操作硬盘的流程：先往命令块寄存器(Command)写入正确的值，再通过控制块寄存器(Control)发送命令。  
- 对不同的IDE通道的访问是通过I/O端口来区分的，对同一IDE通道上的主从设备的访问是通过Device寄存器上的第四位的值来区分的。(0-master 1-slave)  
## 二、为文件系统添加系统调用
- 步骤
1. 定义一种消息，比如MMM(可参照includes/sys/const.h中UNLINK的定义方法)  
2. 写一个函数来处理MMM消息(可参照fs/link.c中的do_unlink()的代码)  
3. 修改task_fs()，增加消息MMM的处理  
4. 写一个用户接口函数xxx(可参照lib/unlink.c中unlink()的代码)  
