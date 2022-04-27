https://en.cppreference.com/w/cpp/language/dynamic_cast

https://stackoverflow.com/questions/35959921/what-is-side-cast-or-cross-cast-in-dynamic-cast-in-c

#### cast怎么读
cast是有这个单词的，其中的一个意思是铸模，可能用在这里解释比较合适。

#### 什么是dynamic_cast

#### 为什么需要 dynamic_cast
因为，需要做一些运行时的校验，去判断指针指向的实例确实是某种目标类型的实例。
以免在非目标类型的实例上，运行目标类型中的函数，出现非法访问。

#### 为什么把类型 t的指针转为void指针，需要t为多态类？
```
class B {
    public:
        // virtual void do_something();
    private:
        int age;
        string name;
};

class D:public B {
    string color;
};

void dynamic_cast4() {
   B *pb = new D();
   void *pv = dynamic_cast<void *>(pb);
}
```
```
cannot dynamic_cast ‘pb’ (of type ‘class B*’) to type ‘void*’ (source type is not polymorphic)
```
有虚函数进行校验，因为目标类型是

#### 为什么把基类Base的指针转为派生类的指针或引用时，需要Base为多态类？
因为如果没有虚函数和，转为派生类之后，无法校验实例内存满足派生类的数据结构，导致调用派生类的函数时，存在内存访问风险。
相反，如果是转为基类，则无需做校验，因为即使指向的实例不是派生类，而是基类，也不会有问题。

#### dynamic_cast一定需要有虚函数么？
不一定，向上转型不需要虚函数，但是向下转型，父类需要有虚函数。

#### dynamic_cast 从语言的角度来说是修饰符还是运算符？
虽然cppreference只是说，这是一个conversion，但准确说，我认为这是运算符（operator），和sizeof()一样。


#### new-type的类型
这是一个类型定义，可以是一个指针类型，也可以是一个引用类型。注意，这里没说是class类型，说明一个class类型的变量，是不能通过dynamic_cast转为另外一个class_type的。
同时也要注意，这里说的type，就是class/struct， 或者是class/struct的引用，或者是class/struct的引用。

#### express的类型
第二个需要注意的就是express的类型。这个和new_type有关系。
（1）如果new_type是引用，那么express就需要是class-type的左值（c++11之前）或者class-type的通用左值（c++11之后）。
就好像如果express是一个右值，那么你就不能用`dynamic_cast<T&>()`来处理。
比如下面代码编译不过：
```
Dog &dd = dynamic_cast<Dog&>(Dog()); 
```
Dog() 这个表达式返回的是一个右值，而Dog&决定dynamic_cast需要一个lvaue(c++11之前)或者glvalue(c++11之后)

#### 运算符的返回值类型
首先，明确一下，返回的是一个value，是一个值。
这个value的type有可能是pointer to class type，也可能是reference to a class type，但是不会是class type。

#### dynamic_cast 的独特之处
dynamic_cast 可以增加const属性，这当然不是它的独特之处，static_cast可以做。
dynamic_cast 可以做downcast转型，这也不是它的独特之处，static_cast一样可以做。

dynamic_cast有的强悍之处体现在多态场景，其中如果new_type是void-pointer，那么返回值会是expression所指向的对象的对应的继承最多的类的对象。
这个说法比较绕，看看cppreference理解下就好。dynamic_cast的第二个强悍之处在于向下转型时，即base转到derived，这个在类似的分发函数中很常见。
这个时候，运行时检查就会执行，但是这个影响性能，而且功能用static_cast也能做。
