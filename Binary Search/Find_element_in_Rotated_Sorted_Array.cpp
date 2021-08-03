#include<bits/stdc++.h>
using namespace std ;

int findMinElement (vector<int>& nums)
{
    int N = nums.size();

    int start =0 , end = N-1 , mid , next , prev ;

    while(start <= end){

        if(nums[start] <= nums[end])
            return start;

        mid = (start+end)/2;    
        prev = (mid +N -1) %N;
        next = (mid +1) % N;

        if( nums[mid] <= nums[next] && nums[mid] <+ nums[prev] )
            return mid;

        if( nums[mid] <= nums[end])
            end = mid -1 ;

        else if ( nums[start] <= nums[mid])
            start = mid +1 ;        
    }
    return -1;
}

int BinAscending(vector<int>& nums , int start , int end , int x)
{   
    int l = start , r = end;

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
int main(){

    vector<int> nums {8,10,12,14,2,4,6};

    int search = 1;
    int N = nums.size();

    int minIndex = findMinElement(nums);

    int found = -1;
    
    found = BinAscending(nums, 0, minIndex-1, search);
    if(found == -1)    
        found = BinAscending(nums ,minIndex ,N, search);

    if(found == -1)  
        cout<<"Not Found"<<endl;
    else 
        cout<<"Found"<<endl;   
    return 0;
}