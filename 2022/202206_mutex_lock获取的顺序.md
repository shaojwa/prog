#### 阻塞在同一个mutex上的多个thread，在mutex被释放时，按照什么顺序获取？
在linux下，似乎是先lock的thread，会在mutex释放时，优先获取到。
