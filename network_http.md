#### 多个 http请求可以在一个tcp连接里并发发送么？

  看hetp的版本，1.1 支持pipeling，但是默认关闭。http2 中支持multiplexing。
