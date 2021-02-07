20210207 p31-p48
1. p24 Operands can be numbers, memory location references, or registers.
1. why cmp using $ for immediate? because cmp has IRM,RM modes, like mov.
1. .int limit the number between 0 and 65535.
1. .ascii "Hello there\0"
1. The data item number is the index of data_items.
1. movl BEGINNINGADDRESS(,%INDEXREGISTER,WORDSIZE)
1. Jump if the second value was greater than the first value.
1. feel free to call it anything you want that is adequately descriptive

## Addressing Modes
in Memory Address, ADDRESS_OR_OFFSET(%BASE_OR_OFFSET,%INDEX,MULTIPLIER) All of the fields are optional.

ADDRESS_OR_OFFSET and MULTIPLIER must both be constants, while the other
two must be registers. If any of the pieces is left out, it is just substituted with zero
in the equation.

All of the addressing modes mentioned in the Section called Data Accessing
Methods in Chapter 2 except immediate-mode can be represented in this fashion.

#### indexed addressing mode
You can use any general-purpose register as the index register.

#### Immediate mode 
Immediate mode is very simple. It does not follow the general form we have
been using. Immediate mode is used to load direct values into registers or
memory locations.

#### register addressing mode
Register mode simply moves data in or out of a register. In all of our
examples, register addressing mode was used for the other operand.

----

Every mode except immediate mode can be used as either the source or
destination operand. Immediate mode can only be a source operand.
