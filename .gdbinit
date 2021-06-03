set history save on
set history size 1048576
set history filename ~/.gdb_hist
set logging on

define xxd
  dump binary memory /tmp/dump.bin $arg0 ((char *)$arg0)+$arg1
  shell xxd /tmp/dump.bin
end
document xxd
  Runs xxd on a memory ADDR and LENGTH
  xxd ADDR LENTH
end

# Print backtrace of all threads
define btall
thread apply all backtrace
end

macro define offsetof(t, f) &((t *) 0)->f
