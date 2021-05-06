https://stackoverflow.com/questions/5469274/what-does-plt-mean-here
#####  callq  8a8940 <__assert_fail@plt> what is plt
It's a way to get code fixups (adjusting addresses based on where code sits in virtual memory, which may be different across different processes) without having to maintain a separate copy of the code for each process. The PLT is the procedure linkage table, one of the structures which makes dynamic loading and linking easier to use.
