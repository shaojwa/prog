#### 如果不再需要 no longer required
 When no longer required, the file descriptor returned by epoll_create() should be closed by using close(2)
 
#### 作为提示 as a hint
 The kernel used this information as a hint for the amount of space to initially allocate in internal data structures describing events.
 
#### 如今 Nowadays
 Nowadays, this hint is no longer required (the  kernel  dynamically sizes the required data structures without needing the hint)

#### 为了 in order to 
but size must still be greater than zero, in order to ensure backward compatibility when new epoll applications are run on older kernels.

#### 处于什么原因 for sth reasons
When  used as an edge-triggered interface, for performance reasons，it is possible to add the file descriptor inside the epoll interface.
