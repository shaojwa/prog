20210220 p117-128

Robust programs are able to handle error conditions gracefully. They are programs that do not crash no matter what the user does.
Building robust programs is essential to the practice of programming. Writing robust programs takes discipline and work - it usually
entails finding every possible problem that can occur, and coming up with an action plan for your program to take.

Programmers get so focused on simply solving the problem at hand that they fail to look at the possible side issues.

#### Some Tips for Developing Robust Programs

1. Testing is one of the most essential things a programmer does. If you haven’t tested something, you should assume it doesn’t work. However, testing isn’t just
about making sure your program works, it’s about making sure your program doesn’t break.

Depending on your program, this may include ending the program, prompting the user to re-enter values, notifying a central error log, rolling back an operation, or ignoring it and continuing.

If the user doesn’t know how to use your program correctly, that should be treated as a bug that needs to be fixed.

Most important is testing corner cases or edge cases. Corner cases are the inputs that are most likely to cause problems or behave unexpectedly.

Truly robust software has a unique error code for every possible contingency.
