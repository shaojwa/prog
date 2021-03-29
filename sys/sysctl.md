https://www.kernel.org/doc/Documentation/sysctl/kernel.txt

`sysctl -p` got the settings form the file or `/etc/sysctyl.conf` by default.
`sysctl -a` is used in common to grep the specified config.
## process
```
// PIDs of value pid_max or larger are not allocated (4M).
kernel.pid_max = 4194304

```

## files
the maximum number of file-handles that the Linux kernel will allocate.
```
fs.file-max = 13116103
```
```
fs.inotify.max_user_watches = 8192
```

## IO

## MM
#### max_map_count
```
vm.max_map_count = 65530
```
