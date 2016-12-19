/*Una fracción unitaria tiene 1 como numerador. La representación decimal de las fracciones unitarias con denominadores del 2 a 10 es:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
0.1(6) significa 0,166666..., y tiene un periodo de 1 dígito. Se puede observar que 1/7 tiene un periodo de 6 dígitos.

Encontrar el valor de d < 1000 para el cual 1/d contiene el periodo más largo en su representación decimal de la fracción.*/

#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
using std::fmod;

int periodo( double );
int cCifras( int );

int main()
{
       	int periodoMLargo = 0;
        
        const int limite = 10;
        for ( int i = 2; i <= limite; i++ )
        {
        	cout << i << " ";
        	int p = periodo( 1.0 / i ) ; cout << p << endl;
                if( periodoMLargo < p ) periodoMLargo = p;
        }
        
        cout << periodoMLargo << endl;
        
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

int periodo( double num )
{
	unsigned int a = static_cast <int>(num);
	
	int i = 1, k = 1;
	
	while ( num - a > 0.0 && i < 100 )
	{
		num *= 10;
		a = static_cast <int>(num);
		i++;
		k++;
	}
	
	int k10 = pow( 10, k );
	if( i == 100 ) return cCifras( a % k10 );
}
