bool repetido( int numero, const int arreglo[], int tamanioArreglo )
{
	for( int i = 0; i < tamanioArreglo ; i++ )
		if( arreglo[i] == numero ) return true;
	
	return false;
}

bool repetido( char numero, const char arreglo[], int tamanioArreglo )
{
	for( int i = 0; i < tamanioArreglo ; i++ )
		if( arreglo[i] == numero ) return true;
	
	return false;
}

bool repetido( float numero, const float arreglo[], int tamanioArreglo )
{
	for( int i = 0; i < tamanioArreglo ; i++ )
		if( arreglo[i] == numero ) return true;
	
	return false;
}

bool repetido( double numero, const double arreglo[], int tamanioArreglo )
{
	for( int i = 0; i < tamanioArreglo ; i++ )
		if( arreglo[i] == numero ) return true;
	
	return false;
}

bool repetido( bool numero, const bool arreglo[], int tamanioArreglo )
{
	for( int i = 0; i < tamanioArreglo ; i++ )
		if( arreglo[i] == numero ) return true;
	
	return false;
}

bool repetido( unsigned long int numero, const unsigned long int arreglo[], int tamanioArreglo )
{
	for( int i = 0; i < tamanioArreglo ; i++ )
		if( arreglo[i] == numero ) return true;
	
	return false;
}