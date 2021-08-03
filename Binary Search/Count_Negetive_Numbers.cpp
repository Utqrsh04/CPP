#include<bits/stdc++.h>
using namespace std;

// Array is Soretd in Ascending Order

// function to count negetive and positive elements in Increasing Sorted Array
void countNegetive(vector<int>& nums)
{
    int left = 0 , right = nums.size()-1 , mid;

    while(left<=right)
    {
        mid = (left + right)/2;

        // if mid element is greater than 0 then it is positive and we will shift to left aprt to find last index of Negetive Element 
        if(nums[mid] >= 0)
            right = mid -1;

        // Otherwise shift to right part to find last index of Negetive Element
        else
            left = mid +1;    
    }

    cout<<"Positive "<<nums.size()-left<<"\n";
    cout<<"Negetive "<<left<<"\n";

}

int main(){

    vector<int> nums {-20,-14,-10,-9,-5,-3,-1,2,3,5,10,14};

    countNegetive(nums);

    return 0;
}