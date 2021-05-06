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
Dump of assembler code for function main():
   0x0000000000400959 <+0>:     push   %rbp
   0x000000000040095a <+1>:     mov    %rsp,%rbp
   0x000000000040095d <+4>:     push   %rbx
   0x000000000040095e <+5>:     sub    $0x28,%rsp
   0x0000000000400962 <+9>:     lea    -0x30(%rbp),%rax
   0x0000000000400966 <+13>:    mov    %rax,%rdi
   0x0000000000400969 <+16>:    callq  0x400a32 <dog_t::dog_t()>
   0x000000000040096e <+21>:    lea    -0x20(%rbp),%rax
   0x0000000000400972 <+25>:    mov    %rax,%rdi
   0x0000000000400975 <+28>:    callq  0x4008fd <adopt_dog()>
   0x000000000040097a <+33>:    lea    -0x20(%rbp),%rdx
   0x000000000040097e <+37>:    lea    -0x30(%rbp),%rax
   0x0000000000400982 <+41>:    mov    %rdx,%rsi
   0x0000000000400985 <+44>:    mov    %rax,%rdi
   0x0000000000400988 <+47>:    callq  0x400a66 <dog_t::operator=(dog_t&&)>
   0x000000000040098d <+52>:    lea    -0x20(%rbp),%rax
   0x0000000000400991 <+56>:    mov    %rax,%rdi
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
```
