/*145 es un número curioso, dado que 1! + 4! + 5! = 1 + 24 + 120 = 145.

Halla la suma de todos los números que son iguales a la suma de los factoriales de sus dígitos.

Nota: como 1! = 1 y 2! = 2 no son sumas, quedan excluidos.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

int fact( int );
bool confirmar( int );

int main()
{
	unsigned int suma = 0;	
	
	for( int i = 3; i <= 100000 ; i++ )
		if( confirmar( i ) ) suma += i;
		
	cout << suma << endl;
	
	cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
	
	return 0;
}

int fact( int n )
{
	int r = 1;
	
	int i = n;
	while(i > 1)
	{
		r *= i;
		i--;
	}
	
	return r;
}

bool confirmar( int n )
{
	int suma = 0;
	int cp = n;
	
	while(cp)
	{
		suma += fact( cp % 10 );
		cp = (cp-(cp%10))/10;
	}
	
	return ( suma == n );
}
