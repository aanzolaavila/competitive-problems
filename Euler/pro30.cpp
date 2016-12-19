/*Sorprendentemente, sólo hay tres números que se pueden escribir como la suma de sus dígitos elevados a cuatro:

1634 = 14 + 64 + 34 + 44 
8208 = 84 + 24 + 04 + 84 
9474 = 94 + 44 + 74 + 44
Como 1 = 14 no es una suma, queda descartado.

La suma de estos números es 1.634 + 8.208 + 9.474 = 19.316.

Halla la suma de todos los números que pueden ser escritos como la suma de sus dígitos elevados a cinco.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <cmath>
using std::pow;
#include <ctime>
using std::clock;

int cCifras( unsigned int );
bool confirmar( unsigned int );

int main()
{
	unsigned int suma = 0;
	
	for( unsigned int i = 2; i <= 500000 ; i++ )
		if( confirmar(i) ) suma += i;
		
	cout << suma << endl;
	
	cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
	
	return 0;
}

int cCifras( unsigned int n )
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

bool confirmar( unsigned int numero )
{
	unsigned int cpNumero = numero;
	
	const int nDigitos = cCifras( numero );
	int digitos[ nDigitos ];
	
	for( int i = 0; i < nDigitos ; i++ )
	{
		digitos[i] = cpNumero % 10;
		cpNumero = (cpNumero-(cpNumero%10))/10;
	}
	
	unsigned int numeroPOW5 = 0;
	for( int i = 0; i < nDigitos; i++ )
		numeroPOW5 += pow( digitos[i], 5 );
		
	return (numero == numeroPOW5);
}
