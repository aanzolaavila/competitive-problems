/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.*/

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
   long long sum = 0;
   for( int i = 1; i <= 2000000; i++ ) 
   if( primo(i) ) sum += i;
   
   cout << sum << endl;
   
   cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
   
   return 0;
}
