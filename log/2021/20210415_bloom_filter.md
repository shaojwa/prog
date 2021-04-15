https://zhuanlan.zhihu.com/p/43263751

## what's bloom filter
probabilistic data structure

## benefit
fast insert and query

## specificity
return is not exact

## delete support
NO

## select
```
n (numbers of inserted element)
p (fault positives)
m (bloom filter len)
k (hash function nnumber)
```

![](<http://latex.codecogs.com/gif.latex?m=-\frac{n\ln p}{(\ln2)^2}>)

![](<http://latex.codecogs.com/gif.latex?k=\frac{m}{n} \ln2>)

## MurmurHash and Fnv 
