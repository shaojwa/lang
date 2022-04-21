https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers

#### 不是所有的两个&都是右值引用
比如：
```
Widget&& var1 = someWidget;      // 这里两个 && 表示右值引用
auto&& var2 = var1;              // 这里两个 && 不是右值引用

template<typename T> void f(std::vector<T>&& param);  // 这里两个 && 表示右值引用
template<typename T> void f(T&& param);               // 这里两个 && 不是右值引用
```

#### 怎么区分
涉及到需要类型推导的类型T，针对T的T&&申明一般是通用引用（universal reference）。
```
Remember that “&&” indicates a universal reference only where type deduction takes place. 
```

#### 常常用到通用引用的地方
1. 模板函数
2. auto变量

#### 另外几个注意点
1. 有const的类型推断也是右值引用。
```
template<typename T>
void f(const T&& param);
```
2.模板类中的函数，可能是右值引用，也可能是通用引用。
```
template <class T, class Allocator = allocator<T> >
class vector {
public:
    ...
    void push_back(T&& x);       // fully specified parameter type ⇒ no type deduction;
    ...
};
```
以及:
```
template <class T, class Allocator = allocator<T> >
class vector {
public:
    ...
    template <class... Args>
    void emplace_back(Args&&... args); // deduced parameter types ⇒ type deduction;
    ...
};
```
