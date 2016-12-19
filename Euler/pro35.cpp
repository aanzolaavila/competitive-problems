/* El número 197 es considerado un primo circular porque todas las rotaciones de sus dígitos: 197, 971 y 719, son también primos.

Hay trece primos como éste inferiores a 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79 y 97.

¿Cuántos primos circulares hay por debajo de un millón? */

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include "extras/primo.h"
#include "extras/rotar_numero.h"
#include <ctime>
using std::clock;
/*#include "extras/nDigitos.h"*/

bool primo_circular( unsigned int );

const int LIMITE = 1000000;

int main()
{
	unsigned int N_PRIMOS_CIRCULARES = 0; // cantidad de numero primos circulares debajo del LIMITE
	
	for( int i = 1; i < LIMITE ; i++ )
	{
		if( ! primo( i ) ) continue;
		if( primo_circular( i ) ) N_PRIMOS_CIRCULARES++;
	}
	
	cout << N_PRIMOS_CIRCULARES << endl;
	
	cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
	
	return 0;
}

bool primo_circular( unsigned int numero )
{
	int n_digitos = nDigitos( numero );
	
	for( int rot = 1; rot <= n_digitos; rot++ )
		if( ! primo( rotar_numero( numero ) ) ) return false;
		
	return true;
}
