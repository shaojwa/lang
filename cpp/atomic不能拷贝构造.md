这样不行：
```
atomic_uint n = 10
```
显示：
```
error: use of deleted function ‘std::__atomic_base<_IntTp>::__atomic_base(
  const std::__atomic_base<_IntTp>&) [with _ITp = unsigned int]’
  atomic_uint n = 10

/usr/include/c++/4.8.2/bits/atomic_base.h:359:7: error: declared here
       __atomic_base(const __atomic_base&) = delete;
```
因为n的构造是条用拷贝构造函数，而atomic的拷贝构造函数是delete的。
```
atomic( const atomic& ) = delete;
```
所以下面的方式中，前面三种是可以的，后面四种是不行的：
```
atomic_uint a(1);
atomic_uint b{2};
atomic_uint c = {3};
atomic_uint d = 0;    // error
atomic_uint e(a);     // error
atomic_uint f{a};     // error
atomic_uint g = {a};  // error
``` 
正确的写法是：
```
atomic_uint n(10);
```
这样调用的是：
```
constexpr atomic( T desired ) noexcept;
```
