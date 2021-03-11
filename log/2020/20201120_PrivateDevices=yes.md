#### Homepage
systemd Homepage is：http://www.freedesktop.org/wiki/Software/systemd/
#### systemd.exec - Execution environment configuration
```
man systemd.exec
```
Takes a boolean argument. If true, sets up a new /dev namespace for the executed processes and only adds API pseudo devices such as /dev/null, /dev/zero or
/dev/random (as well as the pseudo TTY subsystem) to it, but no physical devices such as /dev/sda.

#### more details
https://www.freedesktop.org/software/systemd/man/systemd.exec.html
