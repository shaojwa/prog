在shell中通过`$(subcommand)`来运行，在fd中会多出一个pipe。
```
echo $(ls /proc/$$/fd) 
0 1 2 255 3
```
而直接在shell下运行
```
ls /porc/$$/fd
0
1
2
255
```
