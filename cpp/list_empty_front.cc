#include<iostream>
#include<string>
#include<list>
using namespace std;

class Dog
{
  public:
    Dog() = default;
    string out()
    {
      return "I am base [" + _name + "], i am " + to_string(_age) + " years old";
    }
  private:
    string _name;
    int _age;
};

void test() {
  list<Dog> dog_list;
  cout << dog_list.front().out() << endl;
  list<Dog*> dogs;
  Dog *pd = new Dog();
  dogs.push_back(pd);
  cout << dogs.front() << endl;
  dogs.pop_front();
  cout << dogs.front() << endl;
  list<int> ints;
  cout << ints.front() << endl;
  list<double> dous;
  cout << dous.front() << endl;
  list<bool> bools;
  cout << bools.front() << endl;


}
int main() {
  test();
  return 0;
}
