/*Diremos que un número de n dígitos es pandigital si se hace uso de todos los dígitos de 1 a n exactamente una vez; por ejemplo, el número de 5 dígitos, 15234, es pandigital de 1 a 5.

El producto 7254 es inusual, ya que la identidad, 39 x 186 = 7254, que contiene multiplicando, multiplicador y producto es pandigital de 1 a 9.

Halla la suma de todos los productos cuya identidad (con multiplicando/multiplicador/producto) pueda ser escrita como un pandigital de 1 a 9.

NOTA: Algunos productos pueden obtenerse de más de una manera así que asegúrate de incluirlos sólo una vez en tu suma.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <cmath>
using std::pow;
#include <ctime>
using std::clock;

int nDigitos( int );
bool pandigital( int, int, int );
bool repetido( int, const int [], int );

int main()
{
	long long suma = 0; // Suma de todos los productos con pandigital 1 a 9
	
	int listaProductos[100] = {};
	
	const int limite = 2000;
	for( int i = 1, sub = 0; i <= limite ; i++ )
		for( int j = 1; j <= limite ; j++ )
		{
			if( nDigitos(i) + nDigitos(j) + nDigitos(i*j) == 9 )
			if( (! repetido( i*j, listaProductos, 100 )) && (pandigital( i, j, i*j )) )
			{
				suma += i*j;
				listaProductos[sub] = i*j;
				sub++;
			}
		}
	
	cout << suma << endl;
	
	cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
	
	return 0;
}

int nDigitos( int n )
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

bool pandigital( int a, int b, int prod )
{
	const int digA = nDigitos(a);
	const int digB = nDigitos(b);
	const int digProd = nDigitos(prod);
	
	const int totalDigitos = digA + digB + digProd;
	
	if( totalDigitos != 9 ) return false; // Si la cantidad de digitos no es 9, entonces no seria un pandigital de 1 a 9
	
	unsigned int n = a;
	n *= pow( 10, digB);
	n += b;
	n *= pow( 10, digProd );
	n += prod;
	
	// Separando digitos
	short int numeros[ totalDigitos ];
	for( int i = 0; i < totalDigitos ; i++ )
	{
		numeros[i] = n % 10;
		n = (n-(n%10))/10;
	}
	
	// Comprobando pandigital
	for(int i = 1; i <= 9; i++ )
		for( int j = 0; j < totalDigitos ; j++ )
		{
			if( numeros[j] == i ) break;
			if( j == totalDigitos-1 ) return false;
		}
		
	return true;
}

bool repetido( int numero, const int arreglo[], int tamanioArreglo )
{
	for( int i = 0; i < tamanioArreglo ; i++ )
		if( arreglo[i] == numero ) return true;
	
	return false;
}
