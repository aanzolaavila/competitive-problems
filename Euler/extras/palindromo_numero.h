#include "nDigitos.h"

bool palindromo( int n )
{
   const int cC = cCifras( n );
   int pal[ cC ];
   
   // Separando digitos del numero individualmente
   for( int i = cC; i >= 1; i-- )
   {
       pal[i-1] = n % 10;
       n = (n - (n % 10) ) / 10;
   }
   
   // Comprobando si es palindromo
   for( int i = 1; i <= (( cC - (cC%2) ) /2); i++ )
   {
      if( pal[i-1] == pal[ cC-i ] ) continue; else return false;
   }
      
   return true;
}
