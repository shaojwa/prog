1. https://sourceware.org/gdb/current/onlinedocs/gdb/
1. https://www.gnu.org/software/gdb/

## breakpoints (Making program stop at certain points)
1. break filename:linenum
1. break filename:function
1. rbreak DMTest::WriteObj*
1. delete 4

## status (Status inquiries)
1. info addr obj_locate_snap 
1. info symbol 0x7f5b6879750c 
1. info thread

## data (Examining data)
1. p ((Inode*)0x7f183001cb70)->ll_ref
1. p ((Inode*)0x7f183001cb70)->_ref
1. p *(Dentry*)0x7f183001e400
1. disass

## running
1. set args



## issues and tips
1. using <tab> to break a template-function
  
## class of commands
```
aliases -- Aliases of other commands
breakpoints -- Making program stop at certain points
data -- Examining data
files -- Specifying and examining files
internals -- Maintenance commands
obscure -- Obscure features
running -- Running the program
stack -- Examining the stack
status -- Status inquiries
support -- Support facilities
tracepoints -- Tracing of program execution without stopping the program
user-defined -- User-defined commands
```
  
## get help
```
Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
```
