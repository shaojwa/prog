#### big 4
When you invoke GCC, it normally does preprocessing, compilation, assembly and linking. 
so there are 4 worker: preprocessor, compiler, assembler, linking.


#### big 2
compile and linking

#### overall options
The "overall options" allow you to stop this process at an intermediate stage.  

#### up to assembly only
the -c option says not to run the linker. Then the output consists of object files output by the assembler.

#### option order does NOT mattar
For the most part, the order you use doesn't matter.  Order does matter when you use several options of the
same kind; for example, if you specify -L more than once, the directories are searched in the order specified. 
 
