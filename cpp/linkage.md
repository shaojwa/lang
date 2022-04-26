####  linkage是什么
便于多个相同的命名是否对应同一个实体。

#### linkage解决什么问题

#### linkage的分类
no linkage，internal linkage（static的变量函数），external linkage（全局变量，函数，默认如此）

#### 一些注意点
C++中，匿名namespace中的name是internal-linage的，有名namespace中的name是external-linkage，而C中文件范围内的name是external-linkage的。
