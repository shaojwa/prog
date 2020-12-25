#### 初始化一个tcp链接大概需要多少时间？

#### 默认维持一个tcp链接多少多久？

#### HTTP/1.1 报文头中的connection字段作用

    HTTP请求处理完成是否要关闭TCP链接。
#### 多个 http请求可以在一个tcp连接里并发发送么？

  看hetp的版本，1.1 支持pipeling，但是默认关闭。http2 中支持multiplexing。
