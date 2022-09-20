https://stackoverflow.com/questions/12740378/why-use-int-as-an-argument-for-post-increment-operator-overload
#### 为什么有一种重载需要一个int类型
```
buffers_iterator& operator++() {
  cur = cur->next;
  return *this;
}
buffers_iterator operator++(int) {
  const auto temp(*this);
  ++*this;
  return temp;
}
```
一员运算符的重载中，这个奇怪的带int参数的重载，代表奇怪的post形式。因为一般说来，一元运算符都是在前面的。比如下面的运算：
```
unary minus(-)
NOT(!)
Addressof operator(&)
dereference operator(*)
sizeof()
```
所以，比较正常的，没有参数的用来表示++i，而有参数的代表i++。
