`c_str()`是返回C标准的字符数组，是一个`const char*`， 而`data()`从`C++17`开始，可以返回一个非`const`的`char *`。
所以直接将 `c_str()`返回用`const_cast<char *>(s.c_str())`是危险的。从`C++17`开始，应该用`data()`，来获取`char *`，这个要注意。
