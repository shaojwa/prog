#### 判断目录是否存在
```
if [[ ! -d ${outdir}/${program} ]]; then
    mkdir -p ${outdir}/${program}
fi
```

#### 判断字串是否为空
```
if [[ -n "$pid" ]] then
  kill -9 $pid
fi
```

#### 正则匹配
正则表达式用变量来存储，不要直接用字串
```
pattern="\b${prog}\b"
# if [[ ! "${programs[@]}" =~ \b${prog}\b ]]; then ## NOT work
if [[ ! "${programs[@]}" =~ $pattern ]]; then
   usage && exit -1;
fi
```
