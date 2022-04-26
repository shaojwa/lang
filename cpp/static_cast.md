
#### 为什么需要 static_cast
因为类型之间的转换，意味着可以拿到一个对象的subobject，或者从一个subobject，拿到外层的object。
类型不同，数据不同，意味着可以用不同的函数操作不同的数据，而这些数据都是一个整体的一部分，这样的编程模式显然的需要支持的的。

而这种编程模式的一部分工作，可以在在编译期搞定，比如基类指针变成派生类指针或者相反，都可以在编译期搞定。
这部分能在编译器搞定的指针的适当的偏移转换，就是static_cast。

#### static_cast 会调整偏移么？
会的，static_cast会根据继承关系来确定偏移，这个是在编译器校验的。
```
class Pet {
    int age;
    string name;
};

class Sport {
    string type;
};

class Dog: public Pet, public Sport {
    string home;
};

Dog* pdog = new Dog();
cout << "dog " << pdog << endl;
cout << "pet " << static_cast<Pet*>(pdog) << endl;
cout << "sport " <<  static_cast<Sport *>(pdog) << endl;
```
输出：
```
dog 0x17db010
pet 0x17db010
sport 0x17db020
```

#### static_cast 会cast没有继承关系类指针么？
不会，编译器会检查expression的类型和new_type的类型是否存在继承关系，如果不存在，会报错。
```
class Pet {
    int age;
    string name;
};

class Sport {
    string type;
};

class Dog: public Pet, public Sport {
    string home;
};

static_cast<Dog*>(psport) // error: invalid static_cast from type ‘Sport*’ to type ‘Pet*’
```

#### static_cast < new_type > ( expression ) 如果返回指针，指针的值和参数的值会变么？
会，static_cast存在指针发生偏移的情况，这多半发生在多重继承中，因为如果总是单继承，那么无论嵌套多少层，对象的地址都是相同的。

#### static_cast < new_type > ( expression ) 提示 is an ambiguous base of 的原因是什么
因为new_type在expression的类型中，不是唯一的（unique），也就是说expression类型的对象中，有两个new_type类型的子对象。
这种情况的原因常常和多重继承有关系。
