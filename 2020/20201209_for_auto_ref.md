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
