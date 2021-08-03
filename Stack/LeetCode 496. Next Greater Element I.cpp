#include<bits/stdc++.h>
using namespace std ;


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> st;
        map<int,int> m;
        
        for(int i=nums2.size()-1; i>-1; i--) 
        {
            if(st.empty()) 
            {
                st.push(nums2[i]);
                m[nums2[i]]= -1;
            }

            else 
            {
                int top = st.top();
                
                if(top > nums2[i])
                {
                    m[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
                else 
                {
                    while(st.size() && st.top() <= nums2[i])
                        st.pop();
                    
                    m[nums2[i]] = st.size() ? st.top() : -1;
                    
                    st.push(nums2[i]);
                }
            }
        }

        for(int &i:nums1)
            i=m[i];
        
        return nums1;
    }

int main()
    {
        vector<int> nums1 {4,1,2};
        vector<int> nums2 {1,3,4,2};

        vector<int> ans;

        ans = nextGreaterElement(nums1 , nums2);

        for(int i : ans)
            cout << i << " ";

        cout<<"\n";    

        return 0;
    }
