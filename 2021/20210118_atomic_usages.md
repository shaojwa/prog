#### increment and decrement
```
waiting_count++;
waiting_count--;
```

#### what is throttle_cost_per_io.load()
load atomically loads and returns the current value of the atomic variable. the "get" of atomic variable.

#### what is operator=
Atomically assigns the desired value to the atomic variable. the "put" of atomic variable.

#### operator += is ok ?
it is ok 
```
if (buffer_track_crc) {
  if (cache_adjusts)
    buffer_cached_crc_adjusted += cache_adjusts;
  if (cache_hits)
    buffer_cached_crc += cache_hits;
  if (cache_misses)
    buffer_missed_crc += cache_misses;
}
```
