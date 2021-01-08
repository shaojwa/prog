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
