#!/usr/bin/python
import sys
import datetime
import os
import subprocess
import shlex
import re

goutfile="nmap.out"
gstatefile="state.dat"
glogfile="state.log"
gipfile="list.txt"
gminrate=128
gmaxhostgroup=2


def usage():
     print "usage: " + sys.argv[0] + " [ run | kill | resume ]"


def ntime():
     return str(datetime.datetime.now())

def getstate(key):
    file = open(gstatefile, "r")
    firstline=file.readline()
    if key == "nmap":
        return firstline;

    secondline=file.readline()
    thirdline=file.readline()
    if key == "pid":
        return secondline
    elif key == "ip":
        return thirdline


def setstate(key, value):
    file = open(gstatefile, "r+")
    title=file.readline()
    pospid=file.tell()
    pid=file.readline()
    posip=file.tell()
    ip=file.readline()

    if key == "nmap":
        file.seek(0)
        file.write(value)
        file.write(pid)
        file.write(ip)

    elif key == "pid":
        print "set pid to " + str(value)
        file.seek(pospid)
        file.write(str(value) + "\n")
        file.write(ip)

    elif key == "ip":
        print "set ip to " + str(value)
        file.seek(pospip)
        file.write(str(value) + "\n")

    file.close()
    return


def parse():
    for line in sys.stdin:
        print "good"


def scan(option, minrate, hostgroup, ipfile):
    nmapstr = "nmap -v %s --min-rate %d --max-hostgroup %d -iL %s" % (
            option, minrate, hostgroup, ipfile)
    nmapargs = shlex.split(nmapstr);

    nmap = subprocess.Popen(nmapargs, stdout=subprocess.PIPE,
            stderr=open("/dev/null", "r+"))
    line= "#Nmap scan initiated as: %s -oN %s\n" % (nmapstr, goutfile)
    setstate("nmap", line)
    setstate("pid", nmap.pid)
    parse(nmap.pid, nmap.stdout)
    return nmap.pid


def parse(nmap_pid, data):

    grepnmap = "grep '^Nmap scan report for'"
    grepargs = shlex.split(grepnmap)

    grepip = "egrep -o '[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}'"
    ipargs = shlex.split(grepip)

    line="%s | %s " % (grepnmap, grepip)
    #print line
    grep = subprocess.Popen(line, stdin=data,
            stdout=subprocess.PIPE, shell=True)

    sedscript = "while kill -s 0 %d; do line=$(tail -1);\
            if [[ \"line\" != \"\" ]]; then \
            sed -u 3s/.*/$line/ %s >tmp; cat tmp >%s; fi;\
            sleep 1; done;" % (nmap_pid, gstatefile, gstatefile)

    sed = subprocess.Popen(sedscript, stdin=grep.stdout,
            stdout=open("/dev/null", "r+"),
            stderr=open("/dev/null", "r+"), shell=True)


def resume():
    state = open(gstatefile, "r")
    firstline=state.readline()
    sline=state.readline()
    thirdline=state.readline()
    state.close()
    line = "Nmap scan report for %s" % thirdline
    out = open(goutfile, "r+")
    out.write(firstline)
    out.write("\n")
    out.write(line)
    out.write("\n")
    out.close()

    cmd = "nmap --resume %s" % goutfile
    nmap = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
    print "nmap resumed with pid: %d" % nmap.pid
    setstate("pid", nmap.pid)
    parse(nmap.pid, nmap.stdout)
    return


def killnmap():
    file = open(gstatefile, "r")
    firstline=file.readline()
    secondline=file.readline()
    print "nmap_pid=" + secondline
    cmd="kill -9 %s" % (secondline)
    code = subprocess.call(cmd, shell=True)
    print "kill nmap returns %d" % code
    return code


#print "arguments count = " + str(len(sys.argv))

if len(sys.argv) != 2:
    usage()
    sys.exit();

if sys.argv[1] == "run":
    print "start scan at: " + ntime()
    if not os.path.isfile(gstatefile):
        print "info: create state file"
        f = open(gstatefile, "w+")
        f.write("null\nnull\nnull\n");
        f.close()

    pid = getstate("pid")

    if not os.path.isfile(gipfile):
        print "ERROR: no ip list file"
        sys.exit()

    nmap_pid = scan("-F", gminrate, gmaxhostgroup, gipfile)
    print "run nmap instance. nmap_pid=" + str(nmap_pid)

elif sys.argv[1] == "kill":
    print "kill nmap at: " + ntime()
    killnmap()
elif sys.argv[1] == "resume":
    print "resume nmap at: " + ntime()
    resume()

else: usage()
