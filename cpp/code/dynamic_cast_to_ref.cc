#include<iostream>
#include<string>
using namespace std;

class Dog {
  public:
    Dog() = default;
    Dog(string name, int age): _name(name), _age(age) {}
    string say() {
      return "hello, I am " + _name;
    }
    void rename(string name) {
      _name = name;
    }
  private:
    string _name;
    int _age;
};

void test_expr_lvalue() {
 Dog d0("danny", 3);
 // error: invalid 'static_cast' from type 'Dog' to type 'Dog&'
 dynamic_cast<Dog&>(Dog());

 Dog &d2 = dynamic_cast<Dog&>(d0); // ok
 cout << "d2 say:" << d2.say() << endl;
 d2.rename("suzy");
 cout << "d2 rename to suzy, and say:" << endl;
 cout << d2.say() << endl;
 cout << "d0 say:" << endl;
 cout << d0.say() << endl;

 Dog d3 = dynamic_cast<Dog&>(d0); // ok
 cout << "d3 say:" << endl;
 cout << d3.say() << endl;
 cout << "d3 rename to pedro, and say:" << endl;
 d3.rename("pedro");
 cout << d3.say() << endl;
 cout << "d0 say:" << endl;
 cout << d0.say() << endl;
}


int main() {
  //
  // if new-type is reference
  // expre should be the lvalue(until c++11) or glvalue(since c++11)
  // 
  test_expr_lvalue();
  return 0;
}
