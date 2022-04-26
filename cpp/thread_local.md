#### 什么是thread_local
这是C++11 引入的，这是申明语法中decl-specifier-seq的一部分。

#### 为什么需要 thread_local
他控制一个name的存储周期，和auto，register，static一样。这种变量的存储周期是线程开始到线程结束。
thread_local是为了解决线程是申明周期内的资源管理。

以前，一个name原先的存储周期种类不不多，局部的automatic，或者全局的static/external，要么在一个函数或者代码块执行期间，要么就整个程序的执行期间。
没有更细粒度存储时间相关的管理。

用thread_local的还有一个原因是安全和性能。比如随机数生成流程中，如果用局部的，那么每次的序列都是一样，因为seed一样。如果用全局，又容易被别的thread影响。

#### 怎么使用
申明一次，然后每个线程都会有独立的同名变量。

#### 怎么实现
编译器进行标记。放在`.tdata`段中。然后每次创建一个线程，都会从.tdata中初始化出这这些names。


#### threal_local和__thread的区别
threal_local采用lazy-initialization,在线程访问时再初始化，而__thread变量，根本不初始化。需要程序员自己去手动初始化。
