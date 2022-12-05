在分布式系统中，或者说日志系统中，submit和commit是很常见的两个说法，都有提交的意思，但是有什么区别呢？

submit一般只是表示发送了一个请求，这个请求是否得到确认，还不一定。
而如果说commit了一个请求，表示这个请求不仅发送了，而且还确认了。
也就是说，submit只是`to send something in`，而commit表示`to promise to something`。
