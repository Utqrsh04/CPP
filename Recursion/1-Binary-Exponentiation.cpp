// Calculate power(x,n) in  Log(n) time .

#include<bits/stdc++.h>
using namespace std;

int binaryExpo(int x , int n)  {

  if( n == 0 )
    return 1;

  // when n is even  x^n  =  x^(n/2) * x^(n/2) ;
  int xpnb2 = binaryExpo(x,n/2);
  int xn = xpnb2 * xpnb2 ;

  // when n is odd x^n = x *  x^(n/2) * x^(n/2) ; 
  if( n % 2 == 1) {
    xn = xn * x ;
  } 

  return xn;

}

int main()  {

  int x , n ;
  cin >> x >> n ;

  cout<< binaryExpo(x,n) << endl;  

  return 0;
}