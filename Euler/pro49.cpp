/* La progresión aritmética, 1487, 4817, 8147, en la que cada uno de los términos aumenta en 3330, es inusual por dos motivos: (i) cada uno de los tres términos es primo, y, (ii) cada uno de estos números de cuatro dígitos es una permutación de uno de los otros.

No existen progresiones aritméticas compuestas primos de 1, 2, o 3 dígitos que cuenten con esta propiedad, pero existe otra sucesion creciente de primos de 4 dígitos.

¿Qué número de 12 dígitos se forma concatenando los tres términos de esta progresión? */

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include "extras/primo.h"
#include "extras/nDigitos.h"
#include "extras/permutacion.h"
#include <ctime>
using std::clock;

const int N_DIGITOS = 4;
const int NUMERO_INICIAL = 1487+1;
const int ADICION = 3330;

int main()
{
	for( int i = NUMERO_INICIAL; nDigitos( i ) <= N_DIGITOS; i++ )
	{
		if( primo( i ) )
		if( permutacion( i, i +ADICION ) && permutacion( i, i +ADICION*2 ) )
		if( primo(i + ADICION) && primo(i + ADICION*2 ) )
			cout << "\r" << i << i+ADICION << i+ADICION*2 << endl;
	}
	
	cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
	
	return 0;
}
