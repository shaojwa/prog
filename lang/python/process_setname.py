#!/usr/bin/python

from threading import Thread
import signal
import sys
import prctl

import time
from multiprocessing import current_process


def func_thread():
    i = 0
    while True:
        print("sleep 10 seconds")
        print("set thread name to thread-{}".format(i))
        prctl.set_name("thread-{}".format(i))
        time.sleep(10)
        i += 1

def start_thread():
    t=Thread(target=func_thread)
    t.setName("thread0")
    t.setDaemon(True)
    t.start()

def sig_handle(sig, frame):
    print("catch sig: {} to exit".format(sig))
    sys.exit(0)

if __name__ == '__main__':
# signal.signal(signal.SIGINT, signal.SIG_DFL)
    start_thread()
    i = 0
# time.sleep(5)
    while False:
        print("set process name to process-{}".format(i))
        prctl.set_name("process-{}".format(i))
        time.sleep(10)
        i += 1
        if i == 10:
            break
    print("done")
