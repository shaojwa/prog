#20160602 by shaojwa

src=/f/work/nascan/doc/$1
dformat=/e/dformat/src/dformat.awk
groff=/d/groff/bin/groff.exe

file="${1%%.*}"

if [[ $# != 1 ]]; then 
    echo "error: invalid argument."
    echo "usage: dormat-groff infile outfile "
    echo "exit."
    exit
fi

cat $src | $dformat  > $file.pic
cat $src | $dformat | $groff -p > $file.ps

