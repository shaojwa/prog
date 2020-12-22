## 4 stage
When you invoke GCC, it normally does:
1. preprocessing
1. compilation
1. assembly
1. linking

so there are 4 workers:
1. preprocessor
1. compiler
1. assembler
1. linker

## option types
1. overall options
1. language options
1. warning options
1. debuging options
1. optimization options
1. preprocessor options
1. asembler options
1. linker options
1. directory options
1. machine dependent options
1. code generation options

This manual documents only one of these two forms, whichever one is not the default.

## option order
1. does not matter for the most part
1. does matter for several options of the smae kind

## overall  options
1. one of the options -c, -S, or -E to say where gcc is to stop. 
1. --help=optimizers
## linker option
-static -shared, so building .so or .a is also linker-needed.

## Compiling C++ Programs
gcc will recognizes c++ source files but not add the c++ library,
but g++ is a program that calls GCC and automatically specifies linking against the C++ library
## Options Controlling C++ Dialect


## Options for Debugging Your Program or GCC
## Options That Control Optimization
## Machine Dependent Options
1. GNU/Linux Options, -mglibc
## Options for Code Generation Conventions
## ENVIRONMENT
