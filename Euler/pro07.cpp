/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <cmath>
using std::sqrt;
#include <ctime>
using std::clock;

bool primo( int numero )
{
    int i = sqrt(numero);
    
    if ( numero == 1 ) return false;
    
    while( i > 1 )
    {
        if ( numero % i == 0) return false;
        i--;
    }
    
    return true;
}

int main()
{
   const int o = 10001; //Objetivo...
   for( int i = 1, n = 0; n <= o; i++ )
   {
      if ( primo( i ) ) n++;
      if ( n == o ) {cout << i << endl; break;}
   }
   
   cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
   return 0;
}
