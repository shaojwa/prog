https://interrupt.memfault.com/blog/advanced-gdb


## Count number of GDB commands in the master help list
```
$ gdb --batch -ex 'help all' | grep '\-\-' | wc
    1052   10981   73873
```


## the most useful command within GDB
```
(gdb) apropos
```
apropos searches all the 'help' menus of each command.

## history
I’m a huge believer in developer productivity.

## specify the init file
I’m a huge believer in developer productivity
```
gdb dse -ix=./gdb/project.gdbinit
```

## Directory Search Paths

## list and set listzie 
```
set listsize 20
```

## void the assembly of a specific function.
```
disassemble /s nrf_cli_cmd_echo_on
```

## info registers

## Register Variables
```
(gdb) p $sp
$1 = (void *) 0x20002ad8 <ucHeap1.14288+7812>
(gdb) p $pc
$2 = (void (*)()) 0x802f03c <vPortEnterCritical+32>
```
lr, link register


## Listing Memory Regions
It’s possible to list the memory regions of the binary currently being debugged by running the info files command.
```
(gdb) info files
```

## Searching Memory using find 
I’ll search the entire writeable RAM space, which can be found by running the info files command mentioned previously.

## Hex Dump with xxd


## Searching for Variables
```
info variables coredump*
info variables -t k_spinlock
```
you can reference specific variables from specific files using the following syntax:
```
(gdb) p &'mempool.c'::lock
$4 = (struct k_spinlock *) 0x20002370 <lock>
(gdb) p &('mutex.c'::lock)
$8 = (struct k_spinlock *) 0x2000a0c4 <lock>
```

## convenience variable
```
set $i=0
p ((dm_chunk_t*)0x7fc0a40eb820)->slabs[$i++]
```

## The $ Variable
```
(gdb) p mgmt_thread_data.next_thread
$67 = (struct k_thread *) 0x2000188c <eswifi0+48>
(gdb) p $.next_thread
$68 = (struct k_thread *) 0x200022ac <eswifi_spi0+20>
(gdb) <enter>
$69 = (struct k_thread *) 0x2000a120 <k_sys_work_q+20>
```

## Artificial Arrays
```
(gdb) p (int[100])*elements
$10 = {0, 1, 2, 3, 4, 5, ...

(gdb) p *elements@100
$11 = {0, 1, 2, 3, 4, 5, ...
```

## Struct Operations
```
(gdb) macro define offsetof(t, f) &((t *) 0)->f
```
This macro can also be placed directly within a .gdbinit file.
With this in place, we can now print the offset of any struct members.
```
(gdb) p/d offsetof(struct k_thread, next_thread)
$3 = 100
```

## Running Shell Commands
```
(gdb) shell ls
```
