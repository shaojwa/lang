// https://github.com/google/styleguide/issues/561

#include <iostream>
using namespace std;

class StringHolder {
  public:
    StringHolder(): num(0) {
     cout << "default construct" << endl;
    }
    StringHolder(const int n):num(n) {
     cout << "construct with param" << endl;
    }
  private:
    const int num;
};

int main()
{
  int n = 0;
  cin >> n;
  //if (n % 2 ) {
  //  goto _end;
  //}
  StringHolder h;
  bool b;
  cout << "step 2" << endl;
_end:
  cout << b << endl;
  return 0;
}
