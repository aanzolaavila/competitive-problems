/*Los dos primeros números consecutivos en contar con dos factores primos distintos son los siguientes:

14 = 2 x 7 
15 = 3 x 5

Los tres primeros números consecutivos en tener tres factores primos distintos son los siguientes:

644 = 2² x 7 x 23 
645 = 3 x 5 x 43 
646 = 2 x 17 x 19.

Encuentra los cuatro primeros enteros consecutivos en tener cuatro factores primos distintos. ¿Cuál es el primero de estos números? */

#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
using std::sqrt;
using std::fabs;

bool primo( int numero )
{
    int i = sqrt( fabs(numero) ); // Raiz Cuadrada del valor absoluto del numero = ( |n| )^1/2
    
    if ( fabs(numero) == 1 || numero == 0 ) return false;
    
    while( i > 1 )
    {
        if ( numero % i == 0) return false;
        i--;
    }
    
    return true;
}

int nFactores( unsigned int ); // prototipo de funcion

const int nfacts = 4;

int main()
{
	for( int i = 1; true ; i++ )
	{
		
		if( nFactores( i ) == nfacts )
		if( nFactores( i+1 ) == nfacts )
		if( nFactores( i+2 ) == nfacts )
		if( nFactores( i+3 ) == nfacts )
		{
			cout << i << endl;
			
			return 0;
		}
	}
	
	/*cout << nFactores(644) << endl;
	return 0;*/
}

int nFactores( unsigned int n )
{
	int facts = 0; // numero de factores primos
	
	int f = 2; // primer factor primo
	while( f <= n )
	{
		if( ( n % f == 0 ) && primo( f ) )
		{
			facts++;
			n /= f++;
		}else
			f++;
	}
	
	return facts;
}
