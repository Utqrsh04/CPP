// Find all index of elements in an unsorted Array

#include <bits/stdc++.h>
using namespace std;

void allIndices(vector<int> nums, int x, int idx , vector<int>& res)
{

  if (nums.size() == idx)
  {
    return ;
  }

  if (nums[idx] == x)
  {
    res.push_back(idx);
    allIndices(nums, x, idx + 1 , res);
  }

  else
  {
    allIndices(nums, x, idx + 1 , res);
  }
}

int main()
{
  vector<int> nums{12, 1, 5, 10, 99, 5, 88, 5, 20, 10};
  int x;
  cin >> x;

  vector<int> ans; 
  allIndices(nums, x, 0, ans );

  for (int n : ans)
    cout << n << " ";

  return 0;
}