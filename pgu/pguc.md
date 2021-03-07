20210306 p196-215

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

when bytes are written from registers to memory, their bytes are written out least-significant-portion-first.
The bytes are written in reverse order from what they would appear conceptually, but the bits within the bytes are ordered normally.

Not all processors behave this way. The x86 processor is a little-endian processor, which means that it stores the "little end",
or least-significant byte of its words first.

Modify the integer2string code so that the conversion base is a parameter rather than hardcoded.

I encourage you to explore as many languages as you are interested in. I personally try to learn a new language every few months.

In assembly language what you write is what you get.

Each language is different, and the more languages you know the better programmer you will be. 
Knowing the concepts of different languages will help you in all programming.
