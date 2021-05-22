## can we get the value of the optimized out args?
NO, GDB has no way of displaying such arguments in stack frames other than the innermost one.

The values of arguments that were not saved in their stack frames are shown as ‘<optimized out>’.
If you need to display the values of such optimized-out arguments,
either deduce that from other variables whose values depend on the one you are interested in,or recompile without optimizations.
