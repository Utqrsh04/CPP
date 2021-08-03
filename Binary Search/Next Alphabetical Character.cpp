#include<bits/stdc++.h>
using namespace std;

char nextAplhabet( vector<char> alpha , int sea){
    char res = '@';
    int start = 0 , end = alpha.size() , mid ;

    while (start<=end)
    {
        mid = (start + end)/2;

        if( alpha[mid] == sea)
            start = mid + 1;

        else if (alpha[mid] > sea)
        {   res =alpha[mid];
            end = mid -1 ;
        }    

        else if ( alpha[mid] < sea )
            start = mid +1 ;
    }
    
    return res;
}

int main (){
    vector<char> alpha {'a','c','d','f','g','j','n'};
    char sea = 'z';

    cout<<nextAplhabet(alpha , sea)<<endl;
    
    return 0;
}