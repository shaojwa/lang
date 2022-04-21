https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers

#### 一个表达式的左值或者右值属性和这个表达式的类型无关
```
the lvalueness or rvalueness of an expression is independent of its type. 
```

#### 一个变量的类型是右值引用，但是这个变量有左值属性。
```
Widget makeWidget();                       // factory function for Widget 
Widget&& var1 = makeWidget()               // var1 is an lvalue, but its type is rvalue reference (to Widget)
```

1. 一个表达式，有一种属性叫引用属性，包括对右值的引用以及对左值的引用，这个左右都是针对的引用的对象，而非变量或者表达式本身。
2. 变量或者表达本身身也有另外一种属性，叫左右值属性，一个表达式的引用属性和左右值属性，是两个维度的属性。
