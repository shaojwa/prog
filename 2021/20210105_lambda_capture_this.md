#### WHY lambda capture this
```
rcache_tick_timer = get_co_sched()->GetTimer().StartTimer(
    std::chrono::seconds(get_tick_interval_in_sec()),
    [this] { rcache_queue_tick(); },
    ::co::TaskOpt(UINT16_MAX, UINT16_MAX, get_tick_processor_id(),
    true, 0, 0, __func__, __FILE__, __LINE__));
````
这里的this不可省略。
