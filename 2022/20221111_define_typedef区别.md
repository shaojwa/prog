#### define只是宏定义，是预编译指令，所以以井号开头，无类型检查功能
`#define`之后，紧跟的是新标识符（从替换列表可选就知道）
```
#define identifier replacement-list
```
后续所有的INTEGER 用int代替。
```
#define INTEGER int
```

#### typedef 类型定义关键字，是语句，编译期间处理，有类型检查功能
typedef说明符在申明语句中使用。表示这是一个类型声明，而不是函数或者变量申明。
```
typedef int INTEGER
```
