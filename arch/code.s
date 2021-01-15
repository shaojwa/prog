c++ code:
```
#include <iostream>
using namespace std;

struct dog_t {
  string name;
  int age;
};

dog_t adopt_dog() {
  dog_t dog;
  dog.name = "danny";
  dog.age = 3;
  return dog;
}

int main() {
  dog_t d;
  d = adopt_dog();
  return 0;
}
```
assemble:
```
0x0000000000400740:    pushq  0x2008c2(%rip)        # 0x601008
0x0000000000400746:    jmpq   *0x2008c4(%rip)       # 0x601010      
0x0000000000400760 <+0>:     jmpq   *0x2008ba(%rip)             //  value of 0x601020 is 400766
0x0000000000400766 <+6>:     pushq  $0x1                        //
0x000000000040076b <+11>:    jmpq   0x400740                    //
--------            
Dump of assembler code for function main():
  0x0000000000400959 <+0>:     push   %rbp                      // enter function, saving
  0x000000000040095a <+1>:     mov    %rsp,%rbp                 // rbp = rsp, the new frame
  0x000000000040095d <+4>:     push   %rbx                      // rbx ???
  0x000000000040095e <+5>:     sub    $0x28,%rsp                // rsp = rsp-0x28, stack size is 0x28
  0x0000000000400962 <+9>:     lea    -0x30(%rbp),%rax          // rax = rbp-0x30, addr(dog) = 0xe410, now rax = rsp
  0x0000000000400966 <+13>:    mov    %rax,%rdi                 // rdi = rax = 0xe410, rbp = 0xe440, rsp = 0xe410 
  0x0000000000400969 <+16>:    callq  0x400a32 <dog_t::dog_t()>
      0x0000000000400a32 <+0>:     push   %rbp                  // save last frame base, rbp = 0xe440, rsp = 0xe400
      0x0000000000400a33 <+1>:     mov    %rsp,%rbp             // rbp = rsp = 0xe400
      0x0000000000400a36 <+4>:     sub    $0x10,%rsp            // rsp = 0xe3f0, 0x10 = sizeof(dog)
      0x0000000000400a3a <+8>:     mov    %rdi,-0x8(%rbp)       // rdi = 0xe410 store at 0xe3f8
      0x0000000000400a3e <+12>:    mov    -0x8(%rbp),%rax       // rax = 0xe410 
      0x0000000000400a42 <+16>:    mov    %rax,%rdi             // rdi = rax, do nothing
      0x0000000000400a45 <+19>:    callq  0x400760 <_ZNSsC1Ev@plt>      
      0x0000000000400a4a <+24>:    leaveq                       // rbp = 0xe440, rsp = 0xe408
      0x0000000000400a4b <+25>:    retq                         // rbp = 0xe440, rsp = 0xe410
   0x000000000040096e <+21>:    lea    -0x20(%rbp),%rax         // rax = 0xe420 
   0x0000000000400972 <+25>:    mov    %rax,%rdi                // rdi = 0xe420
   0x0000000000400975 <+28>:    callq  0x4008fd <adopt_dog()>
   0x000000000040097a <+33>:    lea    -0x20(%rbp),%rdx         // rdx = 0xe420
   0x000000000040097e <+37>:    lea    -0x30(%rbp),%rax         // rax = 0xe410(d)
   0x0000000000400982 <+41>:    mov    %rdx,%rsi                // rsi = 0xe420
   0x0000000000400985 <+44>:    mov    %rax,%rdi                // rdi = 0xe410(d)
   0x0000000000400988 <+47>:    callq  0x400a66 <dog_t::operator=(dog_t&&)>  
   0x000000000040098d <+52>:    lea    -0x20(%rbp),%rax     // rax = rbp-0x20
   0x0000000000400991 <+56>:    mov    %rax,%rdi            // 
   0x0000000000400994 <+59>:    callq  0x400a4c <dog_t::~dog_t()>
   0x0000000000400999 <+64>:    mov    $0x0,%ebx
   0x000000000040099e <+69>:    lea    -0x30(%rbp),%rax
   0x00000000004009a2 <+73>:    mov    %rax,%rdi
   0x00000000004009a5 <+76>:    callq  0x400a4c <dog_t::~dog_t()>
   0x00000000004009aa <+81>:    mov    %ebx,%eax
   0x00000000004009ac <+83>:    jmp    0x4009d9 <main()+128>
   0x00000000004009ae <+85>:    mov    %rax,%rbx
   0x00000000004009b1 <+88>:    lea    -0x20(%rbp),%rax
   0x00000000004009b5 <+92>:    mov    %rax,%rdi
   0x00000000004009b8 <+95>:    callq  0x400a4c <dog_t::~dog_t()>
   0x00000000004009bd <+100>:   jmp    0x4009c2 <main()+105>
   0x00000000004009bf <+102>:   mov    %rax,%rbx
   0x00000000004009c2 <+105>:   lea    -0x30(%rbp),%rax
   0x00000000004009c6 <+109>:   mov    %rax,%rdi
   0x00000000004009c9 <+112>:   callq  0x400a4c <dog_t::~dog_t()>
   0x00000000004009ce <+117>:   mov    %rbx,%rax
   0x00000000004009d1 <+120>:   mov    %rax,%rdi
   0x00000000004009d4 <+123>:   callq  0x4007f0 <_Unwind_Resume@plt>
   0x00000000004009d9 <+128>:   add    $0x28,%rsp
   0x00000000004009dd <+132>:   pop    %rbx
   0x00000000004009de <+133>:   pop    %rbp
   0x00000000004009df <+134>:   retq
End of assembler dump.
--------
(gdb) disass dog_t::operator=
     Dump of assembler code for function dog_t::operator=(dog_t&&):
     0x0000000000400a66 <+0>:     push   %rbp
     0x0000000000400a67 <+1>:     mov    %rsp,%rbp
     0x0000000000400a6a <+4>:     sub    $0x10,%rsp       //
     0x0000000000400a6e <+8>:     mov    %rdi,-0x8(%rbp)  // put addr in stack
     0x0000000000400a72 <+12>:    mov    %rsi,-0x10(%rbp) // put addr in stack
     0x0000000000400a76 <+16>:    mov    -0x10(%rbp),%rdx // put value of address to rdx
     0x0000000000400a7a <+20>:    mov    -0x8(%rbp),%rax  // put value of address to rax
     0x0000000000400a7e <+24>:    mov    %rdx,%rsi        // 
     0x0000000000400a81 <+27>:    mov    %rax,%rdi        //
     0x0000000000400a84 <+30>:    callq  0x4007c0 <_ZNSsaSEOSs@plt>
     0x0000000000400a89 <+35>:    mov    -0x10(%rbp),%rax
     0x0000000000400a8d <+39>:    mov    0x8(%rax),%edx
     0x0000000000400a90 <+42>:    mov    -0x8(%rbp),%rax
     0x0000000000400a94 <+46>:    mov    %edx,0x8(%rax)
     0x0000000000400a97 <+49>:    mov    -0x8(%rbp),%rax
     0x0000000000400a9b <+53>:    leaveq
     0x0000000000400a9c <+54>:    retq
```
