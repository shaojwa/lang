#include <iostream>
using namespace std;

//string  pchar_plus_pchar(char *chptr1, char *chptr2) {
//  return chptr1 + chptr2;
//}
//

string pchar_plus_str(const char *chptr1, string str) {
  return chptr1 + str;
}

int main() {
  string out;
  //out = pchar_plus_pchar("hello", "ok");
  cout << out << endl;
  out = pchar_plus_str("hello", "yes");
  cout << out << endl;
  return 0;
}

