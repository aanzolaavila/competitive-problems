// permutacion.h

#include "repetido.h"

bool permutacion( int origen, int permutacion )
{
	const int n_digitos = nDigitos( origen );
	
	if( nDigitos( permutacion ) != n_digitos ) return false;
	
	// descomponiendo ambos numeros
	int dig_origen[ n_digitos ];
	int dig_permut[ n_digitos ];
	
	for( int i = n_digitos-1; i >= 0 ; i-- )
	{
		// origen
		dig_origen[ i ] = origen % 10;
		origen /= 10;
		
		// permutacion
		dig_permut[ i ] = permutacion % 10;
		permutacion /= 10;
	}
	
	// comprobando si cada digitos del origen esta en el otro valor
	for( int i = 0; i < n_digitos ; i++ )
		if( ! repetido( dig_origen[ i ], dig_permut , n_digitos ) ) return false;
		
	return true;
}
