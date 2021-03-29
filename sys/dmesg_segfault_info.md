dmesg command is used in common when debugging segfault.
so How to get the accurate info when we got the output of dmesg?

## sample output
```
[Thu Mar 11 19:23:28 2021] Processer_5[4106073]:
    segfault at 7f6d787ff000 ip 0000562086b5f393 sp 00007f6d78105860 error 6 in dse[562085f96000+1128000]
```

## the fields
```
<timestamp> <task_name[<task_pid>] segfault at <addr> ip <addr> sp <addr> error <code> in <elf>[addr+offset]
```

## error code meanings
```
/*
 * Page fault error code bits:
 *
 *   bit 0 ==    0: no page found       1: protection fault
 *   bit 1 ==    0: read access         1: write access
 *   bit 2 ==    0: kernel-mode access  1: user-mode access
 *   bit 3 ==                           1: use of reserved bit detected
 *   bit 4 ==                           1: fault was an instruction fetch
 */
enum x86_pf_error_code {
    PF_PROT         =               1 << 0,
    PF_WRITE        =               1 << 1,
    PF_USER         =               1 << 2,
    PF_RSVD         =               1 << 3,
    PF_INSTR        =               1 << 4,
};
```
## the error code
so error 3 means user-mode access(4) + write access(2)
