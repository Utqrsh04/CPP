#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int> nums {1,3,2,4};

    stack<int> st;
    vector<int> ans ;

    for(int i=nums.size()-1; i>-1; i--) 
        {
            if(st.size()==0) 
            {
                st.push(nums[i]);
                ans.push_back(-1);
            }

            else 
            {
                int top = st.top();
                
                if(top > nums[i])
                {
                    ans.push_back(st.top()) ;
                    st.push(nums[i]);
                }
                else 
                {
                    while(st.size() && st.top() <= nums[i])
                        st.pop();
                    
                    if(st.size()==0)
                        ans.push_back(-1);
                    else    
                        ans.push_back(st.top());
                    
                    st.push(nums[i]);
                }
            }
        }

    reverse(ans.begin() , ans.end());

    for(int i : ans)
        ::cout<<i<<" ";

    ::cout<<endl;
    return 0;
}