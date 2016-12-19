/*The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ? */

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
   long long numero = 600851475143;
   int factPrimoM = 1; // El factor primo mas grande del numero
   int factPrimo = 2; // Primer factor primo
   
   while ( numero > 1 )
   {
      if( !(numero % factPrimo) && primo(factPrimo) ) 
          {
            numero /= factPrimo; 
            if ( factPrimo > factPrimoM) factPrimoM = factPrimo;
            factPrimo = 2;
          }
          else
          factPrimo++;
   }
   
   cout << factPrimoM << endl;
   
   cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
   return 0;
}
