
* 找到socket对应的fd号
    
        lsof -np <pid> 

* gdb 挂载进程后执行
  
        call close(fd)
  
* 退出 gdb
