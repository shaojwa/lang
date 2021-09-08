#### 为什么需要 dynamic_cast
如果只是单继承，那么，各种指针之间的转型并不会改变指针的值。

向下转换，特别是菱形继承等继承关闭比较复杂的场景下的的转型，能进行运行时检查。
一个 指向MostDerived实例的pRight指针，要转换为pLeft类型的指针。

还有一个原因是，dynamic_cast能进行一些检查，如果cast失败，会有异常抛出或者返回null。

#### dynamic_cast 从语言的角度来说是修饰符还是运算符？
虽然cppreference只是说，这是一个conversion，但准确说，我认为这是运算符（operator），和sizeof()一样。

#### new_type的类型
这是一个类型定义，可以是一个指针类型，也可以是一个引用类型。注意，这里没说是 class 类型，说明一个class类型的变量，是不能通过dynamic_cast转为另外一个class_type的。
同时也要注意，这你说的是type，就是class/struct， 或者是class/struct的引用，或者是class/struct的引用。

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
这个value的type有可能是pointer to class type，也可能是 reference to a class type，但是不会是class type。

#### dynamic_cast 的独特之处
dynamic_cast 可以增加const属性，这当然不是它的独特之处，static_cast可以做。
dynamic_cast 可以向下转型，这也不是它的独特之处，static_cast一样可以做。

dynamic_cast有的强悍之处体现在多态场景，其中如果new_type是 void-pointer，那么返回值会是expression所指向的对象的对应的继承最多的类的对象。
这个说法比较绕，看看cppreference理解下就好。

dynamic_cast的第二个强悍之处在于向下转型，即base转到derived，这个在类似的分发函数中很常见。这个时候，运行时检查就会执行。
（1）对expr指向或者标记的，进行了最多继承的对象对象，进行检测。如何检测？expression指向一个基类对象。
有一种对象，这对象的类型必须是从这个基类派生出来的派生类中，而且这种对象只有一个，那么返回值就会是那个唯一的对象的值，这就是向下转型。
