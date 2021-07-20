# 一个操作系统的实现
## 第三章
1.在载入引导程序时记得执行以下代码：
- sudo mount -o loop pm.img ./mnt/floppy
- sudo cp pmtest1.com ./mnt/floppy
- sudo umount ./mnt/floppy
