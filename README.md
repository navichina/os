# os
operating system homework
created by @navichina, CTGU 12-18-2018
这是操作系统课程的作业代码。

学习环境：Ubuntu 16.04.4 LTS (GNU/Linux 4.4.0-117-generic x86_64)
编辑器：  Vim
编译器：  GCC（gcc version 5.4.0 20160609）


chap1： 关于进程  
  这个单元主要学习了fork（）函数的使用，了解了进程的创建过程，理解了进程树的创建。
  
chap2:  关于线程
  在上一个单元的基础上，了解了线程和进程的区别，学会了创建线程，并进行了同步与互斥操作。
  #在POSIX接口中，pthread不是linux下的默认的库，也就是在链接的时候，无法找到phread库中哥函数的入口地址，于是链接会失败。
  
chap3： 生产者与消费者问题
  有了前面的基础以后，进一步学习了线程的P、V操作,实现了一个单生产者单消费者问题。
