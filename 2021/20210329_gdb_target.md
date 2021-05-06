## What is the target

if you execute `gdb a.out`, then the executable file a.out is the only active target.

If you designate a core file as well, then GDB has two active targets and uses them in tandem

## Why need 2 targets
since core files contain only a program's read-write memory, variables and so on,plus machine status,
while executable files contain only the program text and initialized data.

## types of targets
There are three classes of targets: processes, core files, and executable files.
