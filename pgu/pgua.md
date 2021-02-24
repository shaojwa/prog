20210224 p149-
#### The Memory Layout of a Linux Program

The actual instructions (the .text section) are loaded at the address 0x08048000
(numbers starting with 0x are in hexadecimal, which will be discussed in Chapter
10). The .data section is loaded immediately after that, followed by the .bss
section.
