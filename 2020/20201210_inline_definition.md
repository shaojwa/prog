#### Why are C++ inline functions in the header?

The definition of an inline function doesn't have to be in a header file but, 
because of the one definition rule (ODR) for inline functions, 
an identical definition for the function must exist in every translation unit that uses it.

The easiest way to achieve this is by putting the definition in a header file.

If you want to put the definition of a function in a single source file then you shouldn't declare it inline. 
A function not declared inline does not mean that the compiler cannot inline the function.

####  One Definition Rule
Only one definition of any variable, function, class type, enumeration type,
concept (since C++20) or template is allowed in any one translation unit 
(some of these may have multiple declarations, but only one definition is allowed).
