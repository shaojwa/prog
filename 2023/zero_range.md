对于分段zero操作，参数offset和len，为了方便阅读代码，可以先判断offset和len是不是在一个slab中。
如果在，那么用offset和len，如果不在，那么分两段进行set。
