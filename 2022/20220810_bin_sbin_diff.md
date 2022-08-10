[wikipedia ref](https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard)
[redhat ref](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/4/html/reference_guide/s1-filesystem-fhs)
[linuxfoundation](https://refspecs.linuxfoundation.org/FHS_3.0/fhs/ch03s04.html)


#### /bin
/bin contains commands that may be used by both the system administrator and by users,
but which are required when no other filesystems are mounted (e.g. in single user mode).
It may also contain commands which are used indirectly by scripts.

#### /sbin
The /sbin/ directory stores executables used by the root user. 
/sbin contains binaries essential for booting, restoring, recovering, and/or repairing the system in addition to the binaries in /bin.


#### /usr
/usr is the second major section of the filesystem. /usr is shareable, read-only data.
That means that /usr should be shareable between various FHS-compliant hosts and must not be written to.
Any information that is host-specific or varies with time is stored elsewhere.

#### /usr/bin
