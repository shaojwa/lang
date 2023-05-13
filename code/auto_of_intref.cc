#include <iostream>
using namespace std;

void test() {
  int a = 10;
  int &b = a;
  auto c = b; // c  is int not int-ref
  c = 20;
  cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
  test();
  return 0;
}
