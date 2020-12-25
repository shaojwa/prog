#### 原则
先clear，后destory。

#### destory (destructor) 
1. 析构函数要保证不会出异常。
1. 析构函数中不能做业务，比如不能做配额释放等工作。

#### clear
1. clear 做清理，但是不是销毁，clear中可以做业务，比如释放配额。
