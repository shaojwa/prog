#### 判断目录是否存在
```
if [[ ! -d ${outdir}/${program} ]]; then
    mkdir -p ${outdir}/${program}
fi
```
