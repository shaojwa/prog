#### 类命名
```
$ egrep "class.+\w+Base {" -rn mds | awk '{print $(NF-1)}' | sort | uniq
InodeStoreBase
MDSInternalContextBase
MDSIOContextBase
MDSLogContextBase
```

#### 数据成员命名
```
op_shardedwq
osd_op_tp
peering_wq
peering_tp
```

#### 函数命名
```
get_or_create               // 用or，去获取，如果获取不到就创建
maybe_create_new_object()   // 用maybe
```

#### 配置项命名
mds的配置项将近1800个，有不少命名非常准确：
```
// 开关类以enabled结尾
async_compressor_enabled 

// 超时类以timeout结尾
async_compressor_thread_timeout

// 时间间隔interval_second
async_repair_local_map_send_interval_second

// 数量类以num结尾
async_repair_max_num

// 次数类用count
bdev_nvme_retry_count

// 大小类size
bluestore_max_alloc_size

// 平均值用avg结尾
con_stats_mon_avg

// 频率类per_io值一般是整数
async_repair_sector_num_per_io

比率类ratio值一般是小数
bluefs_log_compact_min_ratio

// 限流类用throttle，控制数据的流量或者事件产生的频率，倾向于平均值的限制。
bluestore_throttle_bytes

//  限流类也用threshold，控制数据占用的最大值，倾向于峰值的控制。
filestore_queue_high_threshold
```
