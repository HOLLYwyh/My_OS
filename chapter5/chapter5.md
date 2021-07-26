# Chapter5
## 一、MakefIle
### 1. 相关概念
(1)# 表示注释  
(2)= 定义变量  
eg. ASM  =nasm  
在引用变量的时候需要用$()括起来  如$(ASM)  
(3)最重要语法：  
target : prerequisites  
	command  
上述形式代表的意思是：  
- 想要得到target,需要执行命令command  
- target依赖prerequisites,当prerequisites中至少有一个文件比target新时，
command才被执行  
(4)
$@ 代表target  
$< 代表prerequisites的第一个名字  
(5) .PHONY
关键词.PHONY后跟着的是方法名  

