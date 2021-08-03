// Generate all Subsequence for a given String
#include <bits/stdc++.h>
using namespace std;

// bc  ->  [ -- , -c , b- , bc ]
// abc ->  [--- , --c , -b-, -bc , a-- , a-c , ab- , abc ]
vector<string> getSubSequence(string str)
{

  if (str.length() == 0)
  {
    vector<string> baseRes;
    baseRes.push_back(""); //empty string is also a Subsequence
    return baseRes;
  }

  // a
  char ch = str.at(0);

  // bc
  string Remaining = str.substr(1);

  //[ -- , -c , b- , bc ]
  vector<string> rest = getSubSequence(Remaining);

  // vector to store answer  
  vector<string> ans;

  //Generating the SubSequences
  for (string each : rest)
  {
    // - *  [ -- , -c , b- , bc ]
    ans.push_back(each);

    // a *  [ -- , -c , b- , bc ]
    ans.push_back(ch + each);
  }

  return ans;
}


int main()
{
  string str;
  cin >> str;

  vector<string> ans = getSubSequence(str);
  cout << "All SubSequences" << endl;
  for (string s : ans)
    cout << s << " , ";

  return 0;

}