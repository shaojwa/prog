## logs of system
there are some critical logs in system for system troubleshooting.
one is the output of command dmesg and another is the messages file user /var/log.

## dmesg
in older man pages, dmesg means system diagnostic messages.
the default action of demsg is to read all the message of the kernal ring buffer.
there are some facility in dmesg we can specify to read, such as kernel, daemon and so on.

## kernel ring buffer

https://www.howtogeek.com/449335/how-to-use-the-dmesg-command-on-linux/

In linux, the booting and startup are two distict phase.

The boot processes (BIOS or UEFI, MBR, and GRUB) take the initialization of the system
to the point where the kernel is loaded into memory and connected to the initial ramdisk.

The startup processes then pick up the baton and complete the initialization of the operating system.
In the very early stages of initialization, logging daemons such as syslogd or rsyslogd are not yet up and running.
To avoid losing notable error messages and warnings from this phase of initialization,
the kernel contains a ring buffer that it uses as a message store.

The kernel ring buffer stores information such as the initialization messages of device drivers,
messages from hardware, and messages from kernel modules.
Because it contains these low-level startup messages,
the ring buffer is a good place to start an investigation into hardware errors or other startup issues.


## remove the need for sudo
```
sudo sysctl -w kernel.dmesg_restrict=0
```

## /var/log/dmesg
from wikipedia
> Since this buffer can be overwritten by a flood of messages in subsequent operation,
  many Unix-like distributions store a post-boot copy of the message buffer
  at /var/log/dmesg or similar secure system location.

attention, post-boot, is not after-boot, but the phase post and boot i think.
so the very beginning messages of booting is stored in /var/log/dmesg. 

## /var/log/messages

