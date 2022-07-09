https://gcc.gnu.org/onlinedocs/cpp/Search-Path.html
```
// and report the final form of the include path.
cpp -v  /dev/null -o /dev/null
```
the directory list printed by the -v option reflects the actual search path used by the preprocessor.
