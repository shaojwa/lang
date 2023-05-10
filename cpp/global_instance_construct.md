```
[wsh@node80 code]$ fg
gdb out
bt
#0  Dog::Dog (this=0x6021b8 <dog>) at global_instance_construct.cc:7
#1  0x0000000000400b01 in __static_initialization_and_destruction_0 (__initialize_p=1, __priority=65535)
    at global_instance_construct.cc:15
#2  0x0000000000400b2a in _GLOBAL__sub_I_dog () at global_instance_construct.cc:20
#3  0x0000000000400c0d in __libc_csu_init ()
#4  0x00007ffff6ff45b5 in __libc_start_main () from /lib64/libc.so.6
#5  0x00000000004009c9 in _start ()
```
source:
```
#include <iostream>
using namespace std;

class Dog {
  public:
    Dog():_name("danny") {}
    Dog(const string &name):_name(name) {}
    const string &get_name() {return _name;}
  private:
    const string _name;
};


Dog dog;
int main()
{
  cout << dog.get_name() << endl;
  return 0;
}
```
