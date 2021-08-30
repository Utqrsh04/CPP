#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str, string ans)
{

  if (ans.length() == 0)
  {
    cout << ans << " AND " << str << endl;
  }

  // a
  char ch = str.at(0);

  // bc
  string Remaining = str.substr(1);

  //[ -- , -c , b- , bc ]
  printSubsequences(str, Remaining + ch);
  printSubsequences(str, Remaining + " ");
}

int main()
{

  string str;
  cin >> str;
  printSubsequences(str, "");

  return 0;
}