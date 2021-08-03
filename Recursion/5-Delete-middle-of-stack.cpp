#include<bits/stdc++.h>
using namespace std;

void solve( stack<int> &s , int k)
{
  if(k == 1){
    s.pop();
    return ;
  }

  int topmost = s.top();
  s.pop();

  solve(s , k-1);

  s.push(topmost);

  return ;

}

stack<int> deleteMidOfStack( stack<int> s , int size )  
{
  if(s.size() == 0)
    return s;

  int k = (size / 2 ) + 1;
  solve(s , k);
  return s;  
}


int main()
{
  stack<int> st ; 
  st.push(5);
  st.push(4);
  st.push(3);
  st.push(2);
  st.push(1);

  stack<int> ans = deleteMidOfStack(st , st.size());

  while (!ans.empty())
  {
    cout<<ans.top()<<" ";
    ans.pop();
  }
  
  return 0;

}