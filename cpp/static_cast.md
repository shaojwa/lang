
#### 为什么需要 static_cast.md

#### static_cast < new_type > ( expression ) 如果返回指针，指针的值和参数的值会变么？
会

#### static_cast < new_type > ( expression ) 提示 is an ambiguous base of 的原因是什么
因为new_type在expression的类型中，不是唯一的（unique），也就是说expression类型的对象中，有两个new_type类型的子对象。
这种情况的原因常常和多重继承有关系。


## description
> Converts between types using a combination of implicit and user-defined conversions

what is implicit and user-defined?
## syntax
```
static_cast< new_type> (expression)
```
returns a value of type **new_type**

## Explanation
attention, **static_cast** can not cast away **constness** and **volatility**

1. if there is an implicit-conversion-sequence from **expression** to **new_type**, the `static_cast<new_type>(expression)` retyrn the **imaginary** variable Temp initialized as if by `new_type Temp(expression);`. in this way, the call to the constructor of new_type is called **implicit conversions**.


1. if overload resolution for a direct initialization of an object or reference of type new_type form expression would find at least one viable function, the `static_cast<new_type>(expression);` will return the imagenary variable Temp initialized as if by `new_type Temp(expression)`
