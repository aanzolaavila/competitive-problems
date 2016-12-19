/* El número, 1406357289, es un número pandigital de 0 a 9, ya que está formado por cada uno de los dígitos del 0 al 9 en un cierto orden, pero también tiene una propiedad de divisibilidad de sub-cadenas interesante.

Sea d1 el 1erdígito, d2 el 2º dígito, etc. De esta manera, observamos lo siguiente:

d2d3d4=406 es divisible entre 2
d3d4d5=063 es divisible entre 3
d4d5d6=635 es divisible entre 5
d5d6d7=357 es divisible entre 7
d6d7d8=572 es divisible entre 11
d7d8d9=728 es divisible entre 13
d8d9d10=289 es divisible entre 17
Halla la suma de todos los números pandigitales de 0 a 9 con esta propiedad. */

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::sqrt;
using std::fabs;

bool pandigital( int, int, long int );
bool propiedad( long int );
int nDigitos( long int );
bool primo( int );

int main()
{
	double suma = 0.0; // Suma de los numeros
	
	for( long int num = 1234567890; num < 9876543210 ; num++ )	
	{	cout << "\r" << num;	
		if( pandigital( 0, 9, num ) ) // si es pandigital
			if( propiedad( num ) ) // si tiene la propiedad
				suma += num; // se agrega el numero a la suma
	}
					
	
	cout << fixed << setprecision(0) << suma << endl;
	
	return 0;
}

int nDigitos( long int n )
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

bool pandigital( const int lInf, const int lSup, long int n )
{
	const int ndigitos = nDigitos( n );
	
	if( lSup > 9 || lSup < 0 ) return false; // si el limite sup es mayor a 9 hay un error
						 // o el lim inf es inferior a 0 (negativo)
	
	// Separando digitos
	short int numeros[ ndigitos ];
	for( int i = 0; i < ndigitos ; i++ )
	{
		numeros[i] = n % 10;
		n = (n-(n%10))/10;
	}
	
	// Comprobando pandigital
	for(int i = lInf; i <= lSup; i++ )
		for( int j = 0; j < ndigitos ; j++ )
		{
			if( numeros[j] == i ) break;
			if( j == ndigitos-1 ) return false;
		}
		
	return true;
}

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

bool propiedad( long int n )
{
	const int ndigitos = 10;
	
	// Separando digitos
	short int nums[ ndigitos ];
	for( int i = ndigitos-1 ; i >= 0 ; i-- )
	{
		nums[i] = n % 10;
		n = (n-(n%10))/10;
	}
	
	// VERIFICANDO PROPIEDAD
	int np = 2; // numero primo
	
	for( int i = 1; i < 8 ; i++ )
	{
		while( ! primo( np ) ) np++;
		
		if( (nums[i]*100 + nums[i+1]*10 + nums[i+2]) % np == 0 )
		{
			np++;
			continue;
		} else
			return false;
	}
	
	return true;
}
