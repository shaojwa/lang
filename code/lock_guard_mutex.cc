#include <unistd.h>
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;


std::mutex mtx;
void routine1() {
  cout << __func__ << " start" << endl;
  lock_guard<mutex> locker(mtx);
  cout << __func__ << " locker inited" << endl;
  cout << __func__ << " returns" << endl;
}

void routine2() {
  cout << __func__ << " start" << endl;
  if (!mtx.try_lock()) {
    cout << __func__ << " unlock mutex" << endl;
    mtx.unlock();
  }
  cout << __func__ << " return" << endl;
}

int main() {
  mtx.lock();
  std::thread t1(routine1);
  std::thread t2(routine2);
  t1.join();
  t2.join();
  cout << __func__ << " returns" << endl;
  return 0;
}
