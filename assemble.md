http://asm.sourceforge.net/articles/linasm.html
https://gist.github.com/mishurov/6bcf04df329973c15044


```
// move rsp to rbp
mov    %rsp, %rbp 
```


```
// push rbp ti stack
push   %rbp 
```

```
// LEA (load effective address)
// https://stackoverflow.com/questions/1658294/whats-the-purpose-of-the-lea-instruction
lea    -20(%rbp), %rax 
```


```
sub   $32, %rsp
```
