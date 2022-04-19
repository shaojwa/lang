shared_ptr是一个模板类，针对某种类型的对象，可以通过一个指针共享所有权。

#### 目标对象的释放
如果，最后一个指向目标对象的shared_ptr对象销毁并释放。

#### 引用计数怎么实现？
有两个概念，一个是The stored pointer，一个是The managed pointer。
The managed pointer就是共享指针指向的最终对象。

所有的shared_ptr里有两个指针，应该是stored piointer。shard_ptr里还有一个指针，是指向控制块。
而控制块里，包含一个指针，指向The managed pointer对象本身，还有维护shared_ptrs的数量和weaker_ptrs的数量。

#### 注意点
shared_ptr通过拷贝构造或者赋值运算是允许的，直接通过shared_ptr中的裸指针来构造的的行为是否正确是不确定的。
