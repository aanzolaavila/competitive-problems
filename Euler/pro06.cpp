/*The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

int main()
{
   int sumC = 0; // Suma de cuadrados
   int Csum = 0; // Cuadrado de sumas
   int l = 100; // limite de las operaciones
   
   // Operacion de Suma de cuadrados
   for( int i = 1; i <= l; i++ )
   {
      sumC += i*i;
   }
   
   // Operacion de cuadrado de sumas
   for( int i = 1; i <= l; i++ )
   {
      Csum += i;
   }
   
   Csum *= Csum;
   
   //Imprimir diferencia de ambos
   cout << Csum - sumC << endl;
   
   cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
   
   return 0;
}
