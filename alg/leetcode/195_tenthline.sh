
lines=0

<file.txt
while read -r line
do
    let lines=lines+1
    if(($lines == 10));then
        echo "$line"
    fi 
done 

