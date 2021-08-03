#include<bits/stdc++.h>
using namespace std;

// If Array is Sorted in Increasing Order
int BinAscending(vector<int>& nums , int x)
{   
    int l = 0 , r = nums.size()-1 ;

    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (nums[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (nums[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // element was not present
    return -1;
}

// If Array is Sorted in Decreasing Order
int BinDescending(vector<int>& nums , int x)
{   
    int l = 0 , r = nums.size()-1 ;

    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (nums[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (nums[m] < x)
            r = m - 1;
 
        // If x is smaller, ignore right half
        else
            l = m + 1;
    }
 
    // element was not present
    return -1;
}




int main(){

    vector<int> nums  {2,3,6,8,10,15,17};
    vector<int> arr {33,30,21,16,14,10,5,3,1};
    int search = 10;
    cout <<"INDEX "<<BinAscending(nums , search)<<"\n";
    cout <<"INDEX "<<BinDescending(arr , search)<<"\n";
    return 0;    
}