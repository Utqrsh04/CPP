#include<bits/stdc++.h>
using namespace std;

// The array was initially sorted in Ascending order and it is rotated in clockwise direction

// Function to find index of min element then we will easily figure out how many times the array is rotated 
// bcoz min element is first eleemnt in Sorted UnRoatated Array and finding its index in rotated array will give our Rotations   

int findArrayrotations(vector<int>& nums)
{
    int N = nums.size();
    int start = 0 , end = N-1 , mid , next , prev ;

    while (start <= end)
    {

        if(nums[start] <= nums[end])
            return N-start;

        mid = (start + end)/2;

        //taking modulo of N so that it dosen't goes out of bounds  
        // if index is N-1 then adding 1 to it will result in index out of bounds
        next = (mid + 1) % N;

        //Adding N and then taking modulo of N so that it dosen't goes out of bounds  
        // if index is 0 then subtracting 1 from it will result in -1 
        // but by doing this it would point to end of the array
        prev = (mid + N-1) % N;

        //Smallest element will be smaller than both of its neighbouring elements 
        // remember our minimun Element is smaller than both of its neighbour
        if( nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            return N-mid ;

        // if the start is smaller than mid then that part is sorted and our min element will be in other part
        // remember our minimun element is smaller than both of its neighbour
        if( nums[start] <= nums[mid] )
            start = mid +1 ;

        // if the mid eleemnt is smaller than end element then that part is sorted and our min eleemnt will be ahead of this
        else if( nums[mid] <= nums[end])
            end = mid -1 ;  
    }
}

int main()
{    
    vector<int> nums {10,12,14,2,4,6,8};

    cout<<"Roatations "<<findArrayrotations(nums)<<"\n";
    return 0;
}