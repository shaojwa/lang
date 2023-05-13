#include <iostream>
using namespace std;

//string  pchar_add_pchar(char *chptr1, char *chptr2) {
//  return chptr1 + chptr2;
//}
//

string pchar_add_str(const char *chptr1, string str) {
  return chptr1 + str;
}

int main() {
  string out;
  //out = pchar_add_pchar("hello", "ok");
  cout << out << endl;
  out = pchar_add_str("hello", "yes");
  cout << out << endl;
  return 0;
}

