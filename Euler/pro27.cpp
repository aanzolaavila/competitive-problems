/*Euler publicó esta destacable ecuación de segundo grado:

n² + n + 41

Resulta que la fórmula produce 40 primos para valores consecutivos de n = 0 hasta 39. Sin embargo, cuando n = 40, 402+ 40 + 41 = 40(40 + 1) + 41 es divisible entre 41, y claramente, cuando n = 41, 412 + 41 + 41 es divisible entre 41.

Usando ordenadores, la increíble fórmula n² - 79n + 1601 fue descubierta, la cual produce 80 primos para valores consecutivos de n = 0 hasta 79. El producto de los coeficientes, -79 y 1601, es -126479.

Considerando ecuaciones de segundo grado de la forma:

n² + an + b, donde |a| < 1000 y |b| < 1000 

donde |n| es el valor absoluto de n 
p.r. |11| = 11 y |-4| = 4
Halla el producto de los coeficientes, a y b, para la ecuación de segundo grado que produzca el mayor número de primos para valores consecutivos de n, comenzando con n = 0.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
/*#include <iomanip>
using std::setprecision;*/
#include <cmath>
using std::fabs;
using std::sqrt;
#include <ctime>
using std::clock;

bool primo( int );
int cuantosPrimos( int, int );

int main()
{
	int CANTIDAD_PRIMOS = 0;
	int a, b;
	int a2, b2; // Copias de las variables
	
	for( a = -999 ; fabs(a) < 1000; a++ )
		for ( b = -999 ; fabs(b) < 1000 ; b++ )
			if( CANTIDAD_PRIMOS < cuantosPrimos(a, b) ) 
			{
				CANTIDAD_PRIMOS = cuantosPrimos(a, b);
				a2 = a;
				b2 = b;
			}
	
	cout << a2*b2 << endl;
	
	cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
	
	return 0;
}

bool primo( int numero )
{
    int i = sqrt( fabs(numero) ); // Raiz Cuadrada del valor absoluto del numero = ( |n| )^1/2
    
    if ( fabs(numero) == 1 ) return false;
    
    while( i > 1 )
    {
        if ( (int)fabs(numero) % i == 0) return false;
        i--;
    }
    
    return true;
}

int cuantosPrimos( int a, int b)
{
	int r = 0;
	for( int n = 0; primo( n*n + a*n + b ) ; n++ ) r++;
	
	return r;
}
