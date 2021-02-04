exact duplicate of the parent, except some points
#### inherits

#### not inherits
specifed in POSIX.1-2001
```
pid
ppid
memory locks
processor utilizations
pending signals
semaphore ajustments
record locks
timer
asynchronous io
```
linux-specific differs
```
directory-change notifications.
the child does not receive a signal when the parent terminates.
timer slack
MADV_DNOTFORK marked memory pages
the termination signal of the child is always SIGCHLD
```
Let's see how a process reaches a Running state. When you fire off a command such as ls, a shell (bash)
searches the directories in the search path stored in the PATH environment variable to find where the ls
command is located. Once the ls file is found, the shell clones itself using the forking method mentioned
earlier, and then the new child process replaces the binary image it was executing (the shell) with the ls
command's executable binary image.
