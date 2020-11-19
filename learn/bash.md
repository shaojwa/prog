#### checking directory existance
```
if [[ ! -d ${outdir}/${program} ]]; then
    mkdir -p ${outdir}/${program}
fi
```

#### checking string empty or not
```
if [[ -n "$pid" ]] then
  kill -9 $pid
fi
```

#### regular expression using
using var to keep the regex without using it directly
```
pattern="\b${prog}\b"
# if [[ ! "${programs[@]}" =~ \b${prog}\b ]]; then ## NOT work
if [[ ! "${programs[@]}" =~ $pattern ]]; then
   usage && exit -1;
fi
```
