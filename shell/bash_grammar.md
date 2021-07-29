#### bash 的基本概念
bash是我最喜欢用的脚本，bash中有一些基本的概念，对于理解较为复杂的代码非常有用，这里做一个简单的介绍。

#### control operators
bash中的 control operators有10个，具体可以看文档：
`||`, `&`, `&&`, `;`, `;;`, `|`, `|&`, `(`, `)`, `<newline>`

#### bash 中的保留字（reserved words）



#### bash 中的command
command是bash语法中的基本单元，每一条command都有一个返回值（return value），这个返回值通常就是这个程序执行之后的退出码（exit status）。
当然如果是因为某个信号而终止的话，那这个返回值就是128+信号值，此时这个程序没有正常执行完，也许就没有退出码。

command 一般就是一系列空格隔开的单词和重定向符号，并且由控制操作符结尾（control operator，一般就是`;`, `&`,  `&&`, `||`)

#### bash 中的pipeline
bash中的pipeline是一种语法结构，pipeline由多个command构成。


