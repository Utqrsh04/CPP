#include<bits/stdc++.h>
using namespace std;

// Function to find First Ocuurance of element
int firstOccurance(vector<int>& nums , int x){

    int start = 0 , end = nums.size()-1;
    int res = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(x == nums[mid])
        {
            res = mid ;
            end = mid-1;
        }

        else if( x < nums[mid])
            end = mid -1;

        else 
            start = mid+1;        
    }

    return res ;
}

// Function to find last Ocuurance of element
int lastOccurance(vector<int>& nums , int x){

    int start = 0 , end = nums.size()-1;
    int res = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(x == nums[mid])
        {
            res = mid ;
            start = mid+1;
        }

        else if( x < nums[mid])
            end = mid -1;

        else 
            start = mid+1;        
    }

    return res ;
}

int main(){

    vector<int> nums  {2,3,10,10,10,15,17};
    int search = 10;
    
    int first = firstOccurance(nums , search);
    int last = lastOccurance(nums , search);

    cout<<"First Index "<<first<<" Last Index "<<last<<"\n";
    cout<<"Count of Element "<<last-first+1<<"\n";

    return 0;    
}