#include<bits/stdc++.h>
using namespace std;

/*
The intution is to assume that our recursive call will do the task of moving our n-1 disk and we will simply move the nth disk.

For 3 disks

toh( 3 , t1 , t2 , t3)

move 2 disks(n-1) from t1 to t3 using t2
toh( 2 , t1 , t3 , t2)

move  disk 3 from t1 to t3 

now move back those 2 disk from t3 to t2 using t1
toh(2, t3 , t2 , t1)

*/

/*
  n = number of disks
  T1 = From tower 
  T2 = Destination Tower
  T3 = Helper tower
*/

void toh (int n , string T1 , string T2 , string T3 )  {

  if( n == 0 )
    return;

  toh(n-1 , T1 , T3 , T2);
  
  cout << "moving disk "<< n <<" [ "<< T1 <<" -> "<<T2<<" ] "<<endl;

  toh(n-1 , T3 , T2 , T1);
   

}

int main()
{
  int disks ;
  cin >> disks ;

  toh(3, "A" , "B" , "C");

  return 0;
}
