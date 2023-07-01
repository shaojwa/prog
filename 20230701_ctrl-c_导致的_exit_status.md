如果是通过信号而退出的，那么exit status就是信号的值+128，比如如果是按ctrl-c导致的退出，那exit status是 128+2=130。
```
When a command terminates on a fatal signal N, bash uses the value of 128+N as the exit status.
```
