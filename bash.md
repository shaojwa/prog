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
