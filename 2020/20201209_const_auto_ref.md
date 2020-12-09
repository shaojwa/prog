http://aristeia.com/Papers/appearing%20and%20disappearing%20consts.pdf

the following code report error：
```
error: invalid initialization of reference of type ‘snapid_t&’ from expression of type ‘const snapid_t’
   for (snapid_t &it : snapset_dm)
```
code
```
for (snapid_t &it : snapset_dm)
```

the reason is the reference to element of set must be const.
> A set is like a map with no values, only keys. Since those keys are used for a tree that accelerates operations on the set, they cannot change. Thus all elements must be const to keep the constraints of the underlying tree from being broken.
