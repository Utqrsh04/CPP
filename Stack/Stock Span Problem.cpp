/* 🚀🚀
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day.

For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
*/

#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int> nums {100, 80, 60, 70, 60, 75, 85};

    stack<pair<int,int>> st;

    vector<int> ans ;

    for(int i=0; i<nums.size(); i++) 
        {
            if(st.size()==0) 
            {
                st.push({nums[i] , i});
                ans.push_back(-1);
            }

            else 
            {
                int top = st.top().first;
                
                if(top > nums[i])
                {
                    ans.push_back(st.top().second) ;
                    st.push({nums[i] , i});
                }
                else 
                {
                    while(st.size() && st.top().first <= nums[i])
                        st.pop();
                    
                    if(st.size()==0)
                        ans.push_back(-1);
                    else    
                        ans.push_back(st.top().second);
                    
                    st.push({nums[i] , i});
                }
            }
        }
    for (size_t i = 0; i < ans.size(); i++)
    {
        ans[i] = i - ans[i];
    }
    

    for(int i : ans)
        ::cout<<i<<" ";

    ::cout<<endl;    

    return 0;
}