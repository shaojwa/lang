https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers

#### 什么是值类别
这是C++11引入的一个概念，包括左值，通用左值，右值，纯右值，这个概念非常复杂，分类很多。

#### 什么是左值
我们可以简单这么记忆，在C++11之前，可以放在等号左边的就是做左值，能放左边的也都能取地址。所以取地址是左值的一个特性之一。


#### 什么是是xvalue
C++11中定义了集中情况的expression是xvalue的:
1. 比如返回值为对象rvalue-reference的函数，比如std::move()
2. 右值数组a的某个元素`a[n]`
3. 右值元素的指针解引用`a.*mp`
4. 右值引用static_cast
5. 特定情况下的`?:`三元运算


#### 什么是通用左值
但是能放在赋值运算左边这个属性，在C++11中不够，我们需要明确，这个表达式能否确定对象或者函数的identity。
在有变量名的表达式，是左值，当然也能determine一个对象的identiry，所以左值也属于通用左值。

#### 什么是右值
有的表达式不能determine一个对象的identity。比如42，比如a++, 我们无法通过这个表达式确定这个对象的identity。
我们无法用这个表达式在再次访问到这个对象。我们能用42再次放到的一个对象么？不能，我们能用a++这个表达式再次访问到一个对象么？不能
因为a++返回的是一个临时的对象，返回的对象已经和a没有关系，所以a++和++a是有区别的。

所以，右值只能得到一个对象的值，但是我们却无法得到这个对象的identity。也许是根本就没这个object，也许是得不到这个object的identity。


#### 一个变量的类型是右值引用，但是这个变量有左值属性。
```
Widget makeWidget();                       // factory function for Widget 
Widget&& var1 = makeWidget()               // var1 is an lvalue, but its type is rvalue reference (to Widget)
```

1. 一个表达式，有一种属性叫引用属性，包括对右值的引用以及对左值的引用，这个左右都是针对的引用的对象，而非变量或者表达式本身。
2. 变量或者表达本身身也有另外一种属性，叫左右值属性，一个表达式的引用属性和左右值属性，是两个维度的属性。


#### 一个表达式的左值或者右值属性和这个表达式的类型无关
```
the lvalueness or rvalueness of an expression is independent of its type. 
```
