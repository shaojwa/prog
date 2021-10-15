set $j=159
set $alloc=0
set $free=0
set $size=0
set $max=0
set $id=0
while($j < 1024)
  set $sum=0
  set $max=0
  set $i=0
  while($i < 360)
   set $s=g_stPartModOptCount[$i][$j].uiAllocSize
   if ($s > 0)
     set $sum=$sum+$s
   end
   if ($s > $max)
     set $a=g_stPartModOptCount[$i][$j].uiAllocCnt
     set $f=g_stPartModOptCount[$i][$j].uiFreeCnt
     set $max=$s
     set $id=$i
   end
   #set $alloc=$alloc+$a
   #set $free=$free+$f
   #set $size=$size+$s
   set $i++
  end
  #p $id
  #p $a
  #p $f
  #p $max
  if ($sum != 0)
    p $j
    p $sum
  end
set $j++
#set $j=1024
end
