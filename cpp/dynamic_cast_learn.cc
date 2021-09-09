#include<iostream>
#include<string>
using namespace std;


class Base {
  public:
    virtual string dump() { return _name + ":" + to_string(_age); };
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

void test() {
  Most m;
  Most *pm =  &m;
  Base *pb;
  Left *pl;
  Right *pr;
  cout << "pm: " << pm << ", pm out: " << pm->out() << endl;
  // dynamic_cast 
  //cout << "dynamic_tast Most* to Base*" << endl;
  // can NOT convert Most* to Base*, because Base in not unique in Most
  //pb = dynamic_cast<Base*>(pm);
  //cout << "pb: " << pb << ", pb out: " << pb->out() << endl;

  // dynamic_cast to left
  pl = dynamic_cast<Left*>(pm);
  cout << "dynamic_tast Most* to Left*, pm: " << pm << ", pl " << pl << endl;

  // dynamic_cast to Right
  pr = dynamic_cast<Right*>(pm);
  cout << "dynamic_cast Most* to Right*, pm: " << pm << ", pr " << pr << endl;

  //  Left* to Base*
  pb = dynamic_cast<Base*>(pl);
  cout << "dynamic_cast Left* to Base*, pl: " << pl << ", pb " << pb << endl;

  //  Right* to Base*
  pb = dynamic_cast<Base*>(pr);
  cout << "dynamic_cast Right* to Base*, pr: " << pr << ", pb " << pb << endl;

  cout << "\n--------voidcast--------" << endl;
  // test rule4: pl need polymorphic
  // here, dynamic_cast is different with static_cast
  void *pv = dynamic_cast<void*>(pl);
  cout << "dynamic_cast Left* to void*, pl " << pl << ", pv " << pv << endl;
  pv = dynamic_cast<void*>(pr);
  cout << "dynamic_cast Right* to void*, pr " << pr << ", pv " << pv << endl;
  
  pv = static_cast<void*>(pl);
  cout << "static_cast Left* to void*, pl " << pl << ", pv " << pv << endl;
  pv = static_cast<void*>(pr);
  cout << "static_cast Right* to void*, pr " << pr << ", pv " << pv << endl;
 
  cout << "\n--------downcast--------" << endl;
  //  Left* to Most*
  pm = dynamic_cast<Most*>(pl);
  cout << "dynamic_cast Left* to Most*, pl: " << pl << ", pm " << pm << endl;

  //  Right* to Most*
  pm = dynamic_cast<Most*>(pr);
  cout << "dynamic_cast Right* to Most*, pr: " << pr << ", pm " << pm << endl;
	
  
  //  Left* to Most*
  pm = static_cast<Most*>(pl);
  cout << "static_cast Left* to Most*, pl: " << pl<< ", pm " << pm << endl;

  //  Right* to Most*
  pm = static_cast<Most*>(pr);
  cout << "static_cast Right* to Most*, pr " << pr << ", pm " << pm << endl;

  cout << "\n--------sidecast--------" << endl;
  //  Left* to Right*
  pr = dynamic_cast<Right*>(pl);
  cout << "dynamic_cast Left* to Right*, pl: " << pl << ", pr " << pr << endl;
  //  Left* to Right*: NOT allowed in static_cast
  //pr = static_cast<Right*>(pl);
  //cout << "static_cast Left* to Right*, pl: " << pl << ", pr " << pr << endl;
  //cout << "\n-------- implicit convert--------" << endl;
  //  Left* to Right*
  pr = (Right*)pl;
  cout << "implicit convert Left* to Right*, pl: " << pl << ", pr " << pr << endl;
}

int main() {
  test();
  return 0;
}
