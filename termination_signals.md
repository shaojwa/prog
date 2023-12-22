@20231221
```
https://www.gnu.org/software/libc/manual/html_node/Termination-Signals.html
https://stackoverflow.com/questions/4042201/how-does-sigint-relate-to-the-other-termination-signals-such-as-sigterm-sigquit
```
These signals are all used to tell a process to terminate, in one way or another. 
They have different names because they’re used for slightly different purposes, and programs might want to handle them differently.
The reason for handling these signals is usually so your program can tidy up as appropriate before actually terminating. 
For example, you might want to save state information, delete temporary files, or restore the previous terminal modes.

## SIGTERM
The SIGTERM signal is a generic signal used to cause program termination.
Unlike SIGKILL, this signal can be blocked, handled, and ignored. It is the normal way to politely ask a program to terminate.

## SIGINT
The SIGINT (“program interrupt”) signal is sent when the user types the INTR character.

## SIGQUIT
SIGQUIT produces a core dump when it terminates the process, just like a program error signal. pay attention to 'program error'.
Certain kinds of cleanups are best omitted in handling SIGQUIT. For example, if the program creates temporary files, 
it should handle the other termination requests by deleting the temporary files.
But it is better for SIGQUIT not to delete them, so that the user can examine them in conjunction with the core dump.

#### SIGKILL
The SIGKILL signal is used to cause immediate program termination. It cannot be handled or ignored, and is therefore always fatal. It is also not possible to block this signal.

This signal is usually generated only by explicit request. Since it cannot be handled, you should generate it only as a last resort, after first trying a less drastic method such as C-c or SIGTERM. If a process does not respond to any other termination signals, sending it a SIGKILL signal will almost always cause it to go away.

In fact, if SIGKILL fails to terminate a process, that by itself constitutes an operating system bug which you should report.
The system will generate SIGKILL for a process itself under some unusual conditions where the program cannot possibly continue to run (even to run a signal handler).

## SIGHUP
