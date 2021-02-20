
class Dog {
  public:
    Dog(string &name): _name(name), _age(0) {}
    Dog(char *name): _name(name), _age(0) {}
    void play(Toy &t) {
  400d9a:       55                      push   %rbp
  400d9b:       48 89 e5                mov    %rsp,%rbp
  400d9e:       41 54                   push   %r12
  400da0:       53                      push   %rbx
  400da1:       48 83 ec 20             sub    $0x20,%rsp
  400da5:       48 89 7d d8             mov    %rdi,-0x28(%rbp)
  400da9:       48 89 75 d0             mov    %rsi,-0x30(%rbp)
/dog.cc:22
      cout << "Im " << _name << ", " << _age << " years old"
        << ", I like play " << t.get_type() << endl;
  400dad:       48 8d 45 e0             lea    -0x20(%rbp),%rax
  400db1:       48 8b 55 d0             mov    -0x30(%rbp),%rdx
  400db5:       48 89 d6                mov    %rdx,%rsi
  400db8:       48 89 c7                mov    %rax,%rdi
  400dbb:       e8 34 ff ff ff          callq  400cf4 <Toy::get_type()>
/dog.cc:21
      cout << "Im " << _name << ", " << _age << " years old"
  400dc0:       48 8b 45 d8             mov    -0x28(%rbp),%rax
  400dc4:       8b 18                   mov    (%rax),%ebx
  400dc6:       48 8b 45 d8             mov    -0x28(%rbp),%rax
  400dca:       4c 8d 60 08             lea    0x8(%rax),%r12
  400dce:       be 41 0f 40 00          mov    $0x400f41,%esi
  400dd3:       bf c0 20 60 00          mov    $0x6020c0,%edi
  400dd8:       e8 23 fc ff ff          callq  400a00 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostr
eam<char, std::char_traits<char> >&, char const*)@plt>
  400ddd:       4c 89 e6                mov    %r12,%rsi
  400de0:       48 89 c7                mov    %rax,%rdi
  400de3:       e8 48 fc ff ff          callq  400a30 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <char, std::char_traits<char>, std::alloc
ator<char> >(std::basic_ostream<char, std::char_traits<char> >&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)@plt>
/dog.cc:21 (discriminator 1)
  400de8:       be 45 0f 40 00          mov    $0x400f45,%esi
  400ded:       48 89 c7                mov    %rax,%rdi
  400df0:       e8 0b fc ff ff          callq  400a00 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostr
eam<char, std::char_traits<char> >&, char const*)@plt>
  400df5:       89 de                   mov    %ebx,%esi
  400df7:       48 89 c7                mov    %rax,%rdi
  400dfa:       e8 a1 fb ff ff          callq  4009a0 <std::basic_ostream<char, std::char_traits<char> >::operator<<(int)@plt>
  400dff:       be 48 0f 40 00          mov    $0x400f48,%esi
  400e04:       48 89 c7                mov    %rax,%rdi
  400e07:       e8 f4 fb ff ff          callq  400a00 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
/dog.cc:22 (discriminator 1)
        << ", I like play " << t.get_type() << endl;
  400e0c:       be 53 0f 40 00          mov    $0x400f53,%esi
  400e11:       48 89 c7                mov    %rax,%rdi
  400e14:       e8 e7 fb ff ff          callq  400a00 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
  400e19:       48 8d 55 e0             lea    -0x20(%rbp),%rdx
  400e1d:       48 89 d6                mov    %rdx,%rsi
  400e20:       48 89 c7                mov    %rax,%rdi
  400e23:       e8 08 fc ff ff          callq  400a30 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <char, std::char_traits<char>, std::allocator<char> >(std::basic_ostream<char, std::char_traits<char> >&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)@plt>
  400e28:       be 60 0a 40 00          mov    $0x400a60,%esi
  400e2d:       48 89 c7                mov    %rax,%rdi
  400e30:       e8 1b fc ff ff          callq  400a50 <std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))@plt>
  400e35:       48 8d 45 e0             lea    -0x20(%rbp),%rax
  400e39:       48 89 c7                mov    %rax,%rdi
  400e3c:       e8 cf fb ff ff          callq  400a10 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string()@plt>
/dog.cc:23 (discriminator 1)
      t.work();
  400e41:       48 8b 45 d0             mov    -0x30(%rbp),%rax
  400e45:       48 89 c7                mov    %rax,%rdi
  400e48:       e8 d1 fe ff ff          callq  400d1e <Toy::work()>
  400e4d:       eb 1a                   jmp    400e69 <Dog::play(Toy&)+0xcf>
  400e4f:       48 89 c3                mov    %rax,%rbx
/dog.cc:22
        << ", I like play " << t.get_type() << endl;
  400e52:       48 8d 45 e0             lea    -0x20(%rbp),%rax
  400e56:       48 89 c7                mov    %rax,%rdi
  400e59:       e8 b2 fb ff ff          callq  400a10 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string()@plt>
  400e5e:       48 89 d8                mov    %rbx,%rax
  400e61:       48 89 c7                mov    %rax,%rdi
  400e64:       e8 37 fc ff ff          callq  400aa0 <_Unwind_Resume@plt>
/dog.cc:24
    }
  400e69:       48 83 c4 20             add    $0x20,%rsp
  400e6d:       5b                      pop    %rbx
  400e6e:       41 5c                   pop    %r12
  400e70:       5d                      pop    %rbp
  400e71:       c3                      retq
