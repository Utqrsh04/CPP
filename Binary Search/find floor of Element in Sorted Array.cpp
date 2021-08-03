#include<bits/stdc++.h>
using namespace std ;

int findFloorInArray(vector<int>& nums , int floor){
    int res = 0 ;
    int start =0 , end = nums.size() , mid ;

    while( start <= end)
    {
        mid = (start + end )/2;

        if(nums[mid] == floor )
            return floor;

        else if ( nums[mid] < floor)
        {
            res = max(res , nums[mid]);
            start = mid + 1;
        }   

        else 
            end = mid -1 ;

    }
    return res;
}

int main()
{
    vector<int> nums {2,4,5,7,8,11,15};

    int floor = 1;

    cout<< findFloorInArray(nums , floor)<<endl;

    return 0;
}