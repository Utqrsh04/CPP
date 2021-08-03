#include<bits/stdc++.h>
using namespace std ;

void getNthRoot(int n , int m )
{
    double low =1 , high = m;
    double eps = 1e-6;

    while( high - low > eps)
    {
        double mid = (low + high )/2.0;

        if( pow(mid , n) < m )
            low = mid ;

        else 
            high = mid ;
    }

    cout << low <<" "<< high << endl;

    cout <<pow(m , (double)( 1.0 / (double) n )) << endl;

    return ;
}

int main()
{
    int n , m ;
    n = 3 , m =27; 
    getNthRoot(n , m );
    return 0;
}