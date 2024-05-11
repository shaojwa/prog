pthread_create本身不返回指针，而是需要调用者提供一个日志，用来存储新的thread信息，参数就是 `* thread`。
所以，也并不直接返回线程id，而是返回状态码。
