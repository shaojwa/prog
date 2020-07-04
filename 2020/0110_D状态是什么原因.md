D 状态就是TASK_UNINTERRUPTIBLE，此时的task有几个特点：不响应信号。

```
#include <unistd.h>
int main(int argc, char* argv[]) {
  if (!vfork()) {  sleep(100);  }
  return 0;
}
```

以上代码让父进程处于D状态，此时进程的CPU用时不会增加， CPU switch 切换也不会增加：

```
cat /proc/11785/sched | grep  -e runtime -e switch
```

为什么要有这种状态呢？
