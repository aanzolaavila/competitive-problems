/*Un número perfecto es un número para el que la suma de sus divisores es exactamente igual a sí mismo. Por ejemplo, la suma de los divisores de 28 sería 1 + 2 + 4 + 7 + 14 = 28, lo que significa que el 28 es un número perfecto.

Un número n se llama deficiente si la suma de sus divisores es menor que n y se llama abundante si esta cantidad excede n.

Como 12 es el número abundante más pequeño, 1 + 2 + 3 + 4 + 6 = 16, el número más pequeño que puede ser escrito como la suma de dos números abundantes es 24. Mediante un análisis matemático, se puede demostrar que todos los enteros mayores que 28123 pueden ser escritos como la suma de dos números abundantes. Sin embargo, este límite superior no se puede reducir más mediante análisis, aunque se sabe que el mayor número que no se puede expresar como la suma de dos números abundantes es inferior a este límite.

Halla la suma de todos los enteros positivos que no se pueden escribir como la suma de dos números abundantes.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include ".\extras\repetido.h"
using std::sqrt;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
#include <ctime>
using std::clock;

typedef unsigned long int UINT;
const int LIMITE = 28123;
bool listaNumerosAbundantes[LIMITE];

bool esAbundante( UINT n)
{
  if( n < 12 )
    return false;

  UINT sum = 1;
  UINT sqrt_n = (int) sqrt(n);

  for( int i = 2 ; i <= sqrt_n ; i++ )
    if( n % i == 0 )
      sum += i + n/i;

  if( sqrt_n * sqrt_n == n )
    sum -= sqrt_n;

  return sum > n;
}

bool esSumaDeDosAbundantes( UINT n)
{
  if( n < 24 )
    return false;

  for( int i = 12 ; i <= (int) n-12 ; i++ )
    if( n-i > 0)
      if( listaNumerosAbundantes[i-1] && listaNumerosAbundantes[n-i-1] )
        return true;

  return false;
}

int main(int argc, char const *argv[])
{
  UINT sumaTotal = 0;

  for( int i = 1 ; i <= LIMITE ; i++)
    listaNumerosAbundantes[i-1] = esAbundante(i);

  for( int i = 1; i <= LIMITE ; i++)
    if( ! esSumaDeDosAbundantes(i) )
      sumaTotal += i;

  cout << fixed << sumaTotal << endl;

  cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;

  return 0;
}