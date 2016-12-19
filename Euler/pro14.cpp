/*La siguiente secuencia iterativa es definida para el conjunto de enteros positivos:

n → n/2 (si n es par) 
n → 3n + 1 (si n es impar)

Usando la regla anterior y comenzando con 13, generamos la siguiente secuencia:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
Se puede observar que esta secuencia (comenzando en 13 y terminando en 1) contiene 10 términos. Aunque aún no ha sido probado (Conjetura de Collatz), se cree que cualquier número inicial acaba en 1.

¿Qué número inicial, inferior a un millón, produce la cadena más larga?

NOTA: Una vez que la cadena comienza, los siguientes términos pueden superar el millón.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

int chainLong( long long );

int main()
{
   int longestChain = 0;
   int bigestStartingNum = 13;
   
   for( int i = 13; i <= 1000000; i++)
   {
       if( chainLong(i) > longestChain ) 
       {
          longestChain = chainLong(i);
          bigestStartingNum = i;
       }
   }
   
   cout << bigestStartingNum << endl;
   
   cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
   
   return 0;
}

int chainLong( long long n )
{
   int c = 1;
   
   do {
        c++;
        if( !( n % 2) ) n /= 2; else n = 3*n + 1;
      } while(n > 1);
      
   return c;
}
