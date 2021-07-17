#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;

class Base {
  public:
    Base() {
      cout << "base::Base()" << endl;
    }
    
    ~Base() {
      cout << "base::~Base()" << endl;
    }

    Base(const Base &b) {
      cout << "base::Base(const Base &b)" << endl;
    }

    Base(Base && b) {
      cout << "base::Base(Base && b)" << endl;
    }

};

class D {
  public:
    D(Base &b_): b(b_) {}
  private:
  Base &b;
};


int main(int argc, char * argv[])
{
  Base b;
  D *d = new D(b);
  delete d;
  cout << "deleted d" << endl;
  return 0;
}
