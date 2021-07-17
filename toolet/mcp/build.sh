#!/bin/bash

subcmd=$1
ROWS=20
COLS=5
in=in.tex
out=table.tex
if [[ $subcmd == "gen" ]]; then
>$out
r=0
while [[ $r -lt $ROWS ]]; do
  c=0
  line=
  while [[ $c -lt $COLS ]]; do
	if [[ $c -ne 0 ]]; then line=$line" & "; fi
        one=$(shuf -n 1 in.tex)
	line=$line$one
	((c++))
  done
  line=$line"\\\\"
  echo $line >>$out
  ((r++))
done 
fi

if [[ $subcmd == "tex" ]]; then latex mcp.tex; fi
if [[ $subcmd == "pdf" ]]; then dvipdf mcp.dvi; fi
