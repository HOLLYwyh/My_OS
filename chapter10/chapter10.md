# Chapter10
## 一、内存分配
1. 内存分配的宏  
具体见/include/sys/proc.h  
- 注意内存的起始地址要高于PROCS_BASE.尤其要避开所有缓冲区  

