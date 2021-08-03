#include<bits/stdc++.h>
using namespace std;

int rec_bin_search( vector<int> nums , int low , int high , int key ){

    if(low > high)
        return -1;

    int mid = (low+high)>>1;
    if( nums[mid] == key )
        return mid;    

    if(key > nums[mid])
        return rec_bin_search(nums, mid+1 , high , key);

    return rec_bin_search(nums , low , mid-1 , key);
}

int main(){
    vector<int> nums {2,4,5,9,10,11,15,28,35};

    int search = 10;

    cout<<rec_bin_search(nums , 0 , nums.size()-1 , search)<<endl;

    return 0;
}