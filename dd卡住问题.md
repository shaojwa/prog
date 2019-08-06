#### 这个问题不是个伪问题实际的原因并不是dd卡主

问题现象是write.sh脚本用dd写文件，然后写10000个以后会sleep一小时，通过shell运行write.sh脚本。

#### shell启动脚本的流程和相关进程
  
  这种问题会有相关的三个进程，第1个是当前的shell，第2个是当前shell创建的用于执行write.sh的子shell，最后一个是子shell启动的dd进程。
  
    [dev ~]$ ps -elf  | grep 11146
    0 S w     11146 11145  0  80   0 - 29095 do_wai Jul22 pts/9    00:00:00 -bash
    0 S w     19874 11146  0  80   0 - 28298 do_wai 18:01 pts/9    00:00:00 /bin/bash ./write.sh
    
    运行的时候，bash是(Ss状态,大S表示Sleep，小s表示 session leader)和   
    执行write.sh的bash进程是(S+状态，+表示在前台进程组in the foreground process group)
    
当运行ctrl+z停止之后的状态是：

    [dev ~]$ ps aux | grep -e 14012 -e 11146
    w     11146  0.0  0.0 116380  4452 pts/9    Ss+  Jul22   0:00 -bash
    w     14012  0.0  0.0 113192  2908 pts/9    T    11:50   0:00 /bin/bash ./write.sh

#### 当前shelll的bash进程

    [dev ~]$ cat /proc/11146/stack
    [<ffffffff8b48e8f7>] do_wait+0x1c7/0x240
    [<ffffffff8b48fc89>] kernel_wait4+0x89/0x140
    [<ffffffff8b48fdc6>] SYSC_wait4+0x86/0x90
    [<ffffffff8b48fe6e>] SyS_wait4+0xe/0x10
    [<ffffffff8b403917>] do_syscall_64+0x67/0x1b0
    [<ffffffff8bbd36a7>] entry_SYSCALL64_slow_path+0x25/0x25
    [<ffffffffffffffff>] 0xffffffffffffffff
  
  用户态：
  
    [dev ~]$ pstack 11146
    #0  0x00007f97bb8d8a3c in waitpid () from /lib64/libc.so.6
    #1  0x0000000000440b24 in waitchld.isra.10 ()
    #2  0x0000000000441ddc in wait_for ()
    #3  0x0000000000433aae in execute_command_internal ()
    #4  0x0000000000433cce in execute_command ()
    #5  0x000000000041e305 in reader_loop ()
    #6  0x000000000041c96e in main ()

  当执行ctrl-z之后： 

    [dev ~]$ cat /proc/11146/stack
    [<ffffffff8b4d1f85>] wait_woken+0x65/0x80
    [<ffffffff8b892493>] n_tty_read+0x3d3/0x8c0
    [<ffffffff8b88dcf2>] tty_read+0x92/0xf0
    [<ffffffff8b652877>] __vfs_read+0x37/0x160
    [<ffffffff8b652a2c>] vfs_read+0x8c/0x130
    [<ffffffff8b652fd5>] SyS_read+0x55/0xc0
    [<ffffffff8b403917>] do_syscall_64+0x67/0x1b0
    [<ffffffff8bbd36a7>] entry_SYSCALL64_slow_path+0x25/0x25
    [<ffffffffffffffff>] 0xffffffffffffffff

用户态：

    [dev ~]$ pstack 11146
    #0  0x00007f97bb902f70 in __read_nocancel () from /lib64/libc.so.6
    #1  0x000000000049dd59 in rl_getc ()
    #2  0x000000000049e584 in rl_read_key ()
    #3  0x000000000048a4e3 in readline_internal_char ()
    #4  0x000000000048ab55 in readline ()
    #5  0x000000000041e6ea in yy_readline_get ()
    #6  0x0000000000420692 in shell_getc ()
    #7  0x000000000042305a in read_token.constprop.6 ()
    #8  0x0000000000426429 in yyparse ()
    #9  0x000000000041dfca in parse_command ()
    #10 0x000000000041e08c in read_command ()
    #11 0x000000000041e28c in reader_loop ()
    #12 0x000000000041c96e in main ()

    
#### 正常情况下，bash write.sh进程sleep时的内核调用栈
 
    [@dev ~]$ cat /proc/11146/stack
    [<ffffffff8b48e8f7>] do_wait+0x1c7/0x240
    [<ffffffff8b48fc89>] kernel_wait4+0x89/0x140
    [<ffffffff8b48fdc6>] SYSC_wait4+0x86/0x90
    [<ffffffff8b48fe6e>] SyS_wait4+0xe/0x10
    [<ffffffff8b403917>] do_syscall_64+0x67/0x1b0
    [<ffffffff8bbd36a7>] entry_SYSCALL64_slow_path+0x25/0x25
    [<ffffffffffffffff>] 0xffffffffffffffff
  
   很多情况下，也会用pstack查看，但是pstack返回的是用户态的栈：
   
    [dev ~]$ pstack 14012
    #0  0x00007f43fd716a3c in waitpid () from /lib64/libc.so.6
    #1  0x0000000000440b24 in waitchld.isra.10 ()
    #2  0x0000000000441ddc in wait_for ()
    #3  0x0000000000433aae in execute_command_internal ()
    #4  0x0000000000432953 in execute_command_internal ()
    #5  0x0000000000433cce in execute_command ()
    #6  0x0000000000432917 in execute_command_internal ()
    #7  0x0000000000433cce in execute_command ()
    #8  0x0000000000433da5 in execute_while_or_until ()
    #9  0x0000000000432410 in execute_command_internal ()
    #10 0x0000000000433cce in execute_command ()
    #11 0x000000000041e305 in reader_loop ()
    #12 0x000000000041c96e in main ()  

    wait4是系统调用，当一个进程等待另外一个进程结束时调用。  
    
    执行ctrl-z之后：    
    write.sh 进程的内核调用栈：
    [dev ~]$ cat /proc/14012/stack
    [<ffffffff8b499cd7>] do_signal_stop+0xf7/0x220
    [<ffffffff8b49b289>] get_signal+0x289/0x5c0
    [<ffffffff8b425007>] do_signal+0x37/0x6a0
    [<ffffffff8b403e8d>] exit_to_usermode_loop+0x51/0xad
    [<ffffffff8b403a32>] do_syscall_64+0x182/0x1b0
    [<ffffffff8bbd36a7>] entry_SYSCALL64_slow_path+0x25/0x25
    [<ffffffffffffffff>] 0xffffffffffffffff

用户态：

    #0  0x00007f7ac8ea2a3c in waitpid () from /lib64/libc.so.6
    #1  0x0000000000440b24 in waitchld.isra.10 ()
    #2  0x0000000000441ddc in wait_for ()
    #3  0x0000000000433aae in execute_command_internal ()
    #4  0x0000000000432953 in execute_command_internal ()
    #5  0x0000000000433cce in execute_command ()
    #6  0x0000000000432917 in execute_command_internal ()
    #7  0x0000000000433cce in execute_command ()
    #8  0x0000000000433da5 in execute_while_or_until ()
    #9  0x0000000000432410 in execute_command_internal ()
    #10 0x0000000000433cce in execute_command ()
    #11 0x000000000041e305 in reader_loop ()
    #12 0x000000000041c96e in main ()
    
 用户态堆栈没有变化。
