/* Los números pentagonales son generados mediante la fórmula, Pn = n(3n-1)/2. Los diez primeros números pentagonales son:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

Se puede observar que P4 + P7 = 22 + 70 = 92 = P8. Sin embargo, su diferencia, 70 - 22 = 48, no es pentagonal.

Halla el par de números pentagonales, Pj y Pk, para los que su suma y su diferencia es pentagonal y D = |Pk-Pj| se reduce al mínimo; ¿Cuál es el valor de D? */

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::sqrt;
using std::fabs;
#include <ctime>
using std::clock;

bool esPenta( int );
int penta( int );

const int limite = 10000; // limite (por no decir infinito)
 
int main()
{
	short int j, k;
	
	for( j = 1 ; j < limite ; j++ )
		for( k = 1; k < limite ; k++ )
			if( esPenta( penta(j) + penta(k) ) )
				if( esPenta( penta(j) - penta(k) ) )
				{
					cout << fixed << setprecision(0) << fabs( penta(j) - penta(k) ) << endl;
					cout << fixed << setprecision(5) << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
					return 0;
				}
	
	cout << "No se encontro\n";
	
	return 0;
}

int penta( int n )
{
	return n*(3*n-1)/2;
}

bool esPenta( int x )
{
	double n = (sqrt( 24*x + 1 ) + 1) / 6;
	
	return ( static_cast <int>(n) == n );
}
