/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

bool palindromo( int );
int cCifras( int );

int main()
{
   int mpal = 0; // Palindromo mas largo hecho de dos numeros de 3 digitos
   for( int i = 100; i <= 999; i++ )
   {
      for( int j = 100; j <= 999; j++ )
      {
         if( palindromo( i*j ) && (mpal < i*j) ) 
         {
            mpal = i*j;
         }
      }
   }
   
   cout << mpal << endl;
   
   cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
   
   return 0;
}

int cCifras( int n )
{
    int c=0;
    if(n == 0) return 1;
    while(n)
    {
       n = (n-(n%10))/10;
       c++;
    }
    return c;
}

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
