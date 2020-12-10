#### big 4
When you invoke GCC, it normally does preprocessing, compilation, assembly and linking. 
so there are 4 worker: preprocessor, compiler, assembler, linking.

#### big 2
compile and linking



#### option order
For the most part, the order you use doesn't matter.  Order does matter when you use several options of the
same kind; for example, if you specify -L more than once, the directories are searched in the order specified. 


#### overall options
The "overall options" allow you to stop this process at an intermediate stage.
the -c option says not to run the linker. Then the output consists of object files output by the assembler.

#### linker option
-static -shared

#### Compiling C++ Programs
gcc will recognizes c++ source files but not add the c++ library,
but g++ is a program that calls GCC and automatically specifies linking against the C++ library
