// rotar numeros

#include "nDigitos.h"
#include <cmath>
using std::pow;

int rotar_numero( unsigned int numero )
{
	static unsigned int cuenta;
	static int numero_actual;
	static int rotacion;
	if( numero_actual != numero ) 
	{
		numero_actual = numero;
		rotacion = numero;
		cuenta = 1;
	}
	
	int n_digitos = nDigitos( numero );
	
	// rotando numero
	int d = rotacion % 10;
	rotacion /= 10;
	rotacion = d * pow(10, n_digitos -1) + rotacion;
	
	if( cuenta == n_digitos ) cuenta = 0; else cuenta++;
	
	return rotacion;
}
