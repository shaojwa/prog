这是给特定的线程发信号，与给进程发是不一样的。信号的处理只能是那个线程。
pthread_kill(3THR) is the thread analog of kill(2)--it sends a signal to a specific thread.This, of course, is different from sending a signal to a process. When a signal is sent to a process, the signal can be handled by any thread in the process. A signal sent by pthread_kill() can be handled only by the specified thread.
