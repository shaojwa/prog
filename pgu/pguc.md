20210306 p196

However, it has some problems. First of all, it takes a lot more circuitry to add and subtract signed
numbers represented this way. Even more problematic, this representation has a problem with the number 0.
In this system, you could have both a negative and a positive 0.

These problems were overcome by using a representation of negative numbers called two’s complement representation.

With this representation, you can add numbers just as if they were positive, and come out with the right answers.
Also, the first digit still carries the sign bit, making it simple to determine whether or not the number is positive or negative.
Negative numbers will always have a 1 in the leftmost bit. 

the x86 processor has both a sign-preserving shift-right, sarl, and a shift-right which does not preserve the sign bit, shrl.

Permissions in Linux are done using octal. This is because Linux permissions are based on the ability to read, write and execute.

be careful not to put any leading zeroes in front of decimal numbers, or they will be interepreted as octal numbers!
