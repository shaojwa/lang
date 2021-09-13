如果执行lock_guard构造函数的线程，不能获取到mutex.lock()，那么将在构造函数里挂起。
```
void routine() {
  lock_guard<mutex> locker(mtx);
}
```
