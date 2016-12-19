/*Sea d(n) la suma de los divisores de n (números menores que n que dividen exactamente a n).
Si d(a) = b y d(b) = a, donde a ≠ b, entonces a y b son una pareja de números amigos.

Por ejemplo, los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110, por lo tanto d(220) = 284. Los divisores de 284 son 1, 2, 4, 71 y 142; de modo que d(284) = 220.

Calcula la suma de todos los números amigos inferiores a 10000.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

unsigned int d( int n );

int main()
{
   int sum = 0;
   for( int a = 1; a <= 10000; a++ )
   {
      int b = d(a);
      if( a != b && d(b) == a ) sum += a;
   }
   
   cout << sum << endl;
   
   cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
   
   return 0;
}

unsigned int d( int n )
{
   unsigned int sum = 0;
   
   const int limit = n/2;
   for( int i = 1; i <= limit; i++ ) if( n % i == 0 ) sum += i;
   
   return sum;
}
