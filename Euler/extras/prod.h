/* Producto de una lista de elementos enteros o decimales */

int prod( int lista[], int n)
{
	int res = lista[0];
	for(int i = 1; i < n; i++)
		res *= lista[i];
	return res;
}

unsigned int prod( unsigned int lista[], int n)
{
	unsigned int res = lista[0];
	for(int i = 1; i < n; i++)
		res *= lista[i];
	return res;
}

double prod( double lista[], int n)
{
	double res = lista[0];
	for(int i = 1; i < n; i++)
		res *= lista[i];
	return res;
}

long double prod( long double lista[], int n)
{
	long double res = lista[0];
	for(int i = 1; i < n; i++)
		res *= lista[i];
	return res;
}