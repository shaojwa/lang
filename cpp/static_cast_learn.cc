#include<iostream>
#include<string>
using namespace std;


class Base {
  public:
    string out() {
      return "I am base " + _name;
    }
  private:
    string _name;
    int _age;
};

class Left: public Base {
  public:
    string out() {
      return "I am left";
    }
};

class Right: public Base {
  public:
  string  out() {
    return "I am right";
  }
};

class Most: public Left, public Right {
  public:
    string out() {
      return "I am most";
    }
};

void test_diamond_cast() {
  Most m;
  Most *pm =  &m;
  Base *pb;
  Left *pl;
  Right *pr;
  cout << "pm: " << pm << ", pm out: " << pm->out() << endl;

  // static_cast will NOT change the value ? NO

  //cout << "static_cast Most* to Base*:" << endl;
  // can NOT convert Most* to Base*, because Base in not unique in Most
  //pb = static_cast<Base*>(pm);
  //cout << "pb: " << pb << ", pb out: " << pb->out() << endl;

  // convert Most* to Left*
  pl = static_cast<Left*>(pm);
  cout << "static_cast Most* to Left*, pl " << pl << ", pl out: " << pl->out() << endl;

  // convert Most* to  Right*
  pr = static_cast<Right*>(pm);
  cout << "static_cast Most* to Right*, pr " << pr << ", pr out: " << pr->out() << endl;

  // convert Left* to  Base*
  pb = static_cast<Base*>(pl);
  cout << "static_cast Left* to Base*, pb " << pb << ", pb out: " << pb->out() << endl;
  // convert Right* to  Base*
  pb = static_cast<Base*>(pr);
  cout << "static_cast Right* to Base*, pb " << pb << ", pb out: " << pb->out() << endl;

  // unitl here, dynamic_cast is same as static_cast
  // downcast can ALSO  be done by static_cast
  pm = static_cast<Most*>(pl);
  cout << "static_cast Left* to Most*, pm " << pm << ", pm out: " << pm->out() << endl;

  pm = static_cast<Most*>(pr);
  cout << "static_cast Right* to Most*, pm: " << pm << ", pm out: " << pm->out() << endl;
}


int main() {
  test_diamond_cast();
  return 0;
}
