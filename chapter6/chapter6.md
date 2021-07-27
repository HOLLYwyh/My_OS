#Chapter6
## 一、最简单的进程
### 1. 进程切换
(1)大致流程  
a. 进程A运行中  
b. 中断发生，ring1->ring0  
c. 进程调度，下一个应运行的进程（B）被指定  
d. 进程B被恢复，ring1->ring0  
e. 进程B运行中  
(2)保存与恢复内容  
- 使用pushad的指令保存许多寄存器的值，使用pop恢复被调用指令的寄存器内容，使用ireted切换到相应指令  
- 进程有关的寄存器内容均存在pcb中  
(3)堆栈
- 进程栈——进程运行时自身的堆栈  
- 进程表(PCB)——存储进程状态信息的数据结构  
- 内核栈——进程调度模块运行时使用的堆栈  
(4)TSS、GDT和PCB的关系   
- PCB和GDT：  
进程表内的LDT Selector对应GDT中的一个描述符，而这个描述符所只想的内存空间就存在于进程内。  
- GDT和TSS。GDT中需要有一个描述符来对应TSS，需要事先初始化这个描述符。  
### 2.多进程
进程相关比较重要的内容有:进程表、进程体、GDT、TSS