https://learningtech.hashnode.dev/static-initialization-order-cpp-nifty-counters

在CPP中，一个编译单元，活着叫translation unit就是一个文件。同一个编译单元中，static变量的初始化顺序按照变量定于的顺序来。
我们可以看到static被初始化的位置：
```
(gdb) bt
#0  0x0000000000401250 in Dog::Dog() ()
#1  0x00000000004011d2 in __static_initialization_and_destruction_0(int, int) ()
#2  0x000000000040121a in _GLOBAL__sub_I_dog ()
#3  0x00007ffff7b0c05d in __libc_start_main_impl () from /usr/lib64/libc.so.6
#4  0x00000000004010c5 in _start ()
(gdb)
```
注意看到，这里没有main，因为还没进入main。入口函数是_start。
