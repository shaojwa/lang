
#include <iostream>
using namespace std;

class Dog {
  public:
    Dog():_name("danny") {}
    Dog(const string &name):_name(name) {}
    const string &get_name() {return _name;}
  private:
    const string _name;
};


int main()
{
  auto mfunc = Dog::get_name;
  cout << mfunc << endl;
  return 0;
}
