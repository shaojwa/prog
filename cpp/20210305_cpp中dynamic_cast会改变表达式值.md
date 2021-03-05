```
#include <iostream>                         
using namespace std;                        
                                            
class Base1 {                               
  public:                                   
  virtual void foo() { puts("Base foo"); }; 
};                                          
                                            
class Base2 {                               
  public:                                   
  virtual void bar() { puts("Base bar"); }; 
};                                          
                                            
class Derive : public Base1, public Base2 { 
  void foo() { puts("Derive foo"); };       
  void bar() { puts("Derive bar"); };       
};                                          
                                            
Base1 *test_prvalue() {                     
  Derive *dp = new Derive();                
  Base1* b1p = dynamic_cast<Base1*>(dp);    
  Base2* b2p = dynamic_cast<Base2*>(dp);    
  cout << "dp\t" << dp << endl              
    << "b1p\t" << b1p << endl               
    << "b2p\t" << b2p << endl;              
  return dp;                                
}                                           
                                            
int main() {                                
 test_prvalue()->foo();                     
 return 0;                                  
}                                           
```
output:
```
[wsh@localhost code]$ ./a.out 
dp      0x10baeb0             
b1p     0x10baeb0             
b2p     0x10baeb8             
Derive foo                    
```
