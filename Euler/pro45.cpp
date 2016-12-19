/* Los números triangulares, pentagonales y hexagonales son generados por las siguientes fórmulas:

N. Triangulares	 	T n=n(n+1)/2	 	1, 3, 6, 10, 15, ...
N. Pentagonales	 	P n=n(3n-1)/2	 	1, 5, 12, 22, 35, ...
N. Hexagonales	 	H n=n(2n-1)	 	1, 6, 15, 28, 45, ...
Se puede comprobar que T285= P165= H143= 40755.

Halla el siguiente número triangular que es también pentagonal y hexagonal. */

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <cmath>
using std::sqrt;
#include <ctime>
using std::clock;

bool esPenta( long int );
bool esHexa( long int );

const int num_inicial = 285+1;

int main()
{
	for( unsigned long int n = num_inicial; true ; n++ )
		if( esPenta( (n*( n+1 ))/2 ) )
			if( esHexa( (n*( n+1 ))/2 ) )
			{
				cout << (n*( n+1 ))/2 << endl;
				
				cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
				
				return 0;
			}
}

bool esPenta( long int x )
{
	double n = ( sqrt( 24*x +1 ) +1 ) /6;
	
	return ( static_cast <int>(n) == n );
}

bool esHexa( long int x )
{
	double n = ( sqrt( 8*x +1 ) +1 ) /4;
	
	return ( static_cast <int>(n) == n );
}
