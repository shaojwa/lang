如果执行lock_guard构造函数的线程，不能获取到mutex.lock，那么，构造函数将挂起。
```
void routine() {
  lock_guard<mutex> locker(mtx);
}
```
