## why special
in certain cases, the compiler automatically generates for you.

## big six
1. default constructor
2. destructor
3. copy constructor
4. copy assignment operator
5. the move constructor
6. move assignment operator.

## default constructor typically have no parameters
so constructor with parameters  are NOT default constructor.

## no default constructor
If any non-default constructors are declared, the compiler does not provide a default constructor.

## force declare the default constructor
using keyword default

## declare and define
using **default** keyword to **declare** the default dsestructor, the compiler will **define** the function only if needed.
