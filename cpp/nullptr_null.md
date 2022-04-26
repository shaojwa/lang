http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2431.pdf

#### nullptr 是什么
nullptr是C++11引入的关键字，也是一个字面量，有值，有类型。值就是空，类型就是nullptr_t类型。


#### 为什么需要nullptr
**为了更加明确的类型**

因为我们需要为空也指定一种类型，你单纯指定NULL是不行的，因为这个NULL只有值（NULL就是0），没有类型。
在需要类型的场合是不行的。比如：，你如法把只为0的int，转为int*：
```
template<class T>
constexpr T clone(const T& t) {
  return t;
} 
void g(int*) {
  std::cout << "Function g called\n";
}
 
int main()
{
  g(NULL); // Fine
  // g(clone(NULL)); 
  
  g(nullptr); // Fine
  g(clone(nullptr)); // Fine
}
```
`cline(NULL) `返回的是一个类型为`int`值为`0`的变量，这个变量是不能强转为`int*`的。而g(NULL)是可以的，因为NULL就是0，是个字面量。
从字面量转为`int*`是可以的，但是把`int`类型的constexpr直接转为`int*`是不行的。这里就需要用到nullptr。

**有了明确的类型之后就可以更好支持泛型编程避免歧义**

#### 注意nullptr的类型不是指针类型
指针类型这个说法是错的，类型都是具体的，是某一种类型的指针，没有单独存在的指针。所以nullptr的 类型是nullptr_t。它有类型。
是nullptr_t，这种类型是可以隐式转换为`int *`的。

#### 为什么nullptr可以付给其他类型的指针
因为其他类型的指针，可以通过nullptr_t来转换。cppreference说过：
```
There exist implicit conversions from nullptr to null pointer value of any pointer type and any pointer to member type. 
```
