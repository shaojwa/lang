```
atomic_uint n;
```
这样的n是随机值，因为参考手册上写的：
```
The default constructor is trivial: no initialization takes place.
```
所以要显式初始化：
```
atomic_uint n(0);
atomic_uint n {0};
atomic_uint n = {0};
```
我看ceph源代码都是用大括号的比较多。
上面三种中的前两种叫直接初始化（Direct initialization），参数都是其他类型的的值，而不是当前对象的类型。
第三种叫列表初始化（List-initialization），也要注意，大括号中的值，不能是atomic_uint，而必须是其他类型。
```
atomic_uint d = 0; // 会隐式构造一个临时的对象
atomic_uint e(a);
```
这种用当前类型的对象来初始化另外一个对象，那就是拷贝初始化，不一样。

