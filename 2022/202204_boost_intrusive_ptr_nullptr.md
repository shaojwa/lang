boost中的intrusive ptr可以直接赋值为nullptr，因为intrusive_ptr支持一个参数的构造函数。
```
intrusive_ptr(T * p, bool add_ref = true);
```
https://www.boost.org/doc/libs/1_78_0/libs/smart_ptr/doc/html/smart_ptr.html
