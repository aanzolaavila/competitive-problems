#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void ordenar( int lista[], const int TAM)
{
	for( int i = 1; i < TAM; i++)
		for( int j = 0 ; j < TAM - 1; j++)
			if (lista[j] > lista[j+1])
			{	
				int temp = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = temp;
			}
}

int main()
{
	int t;
	cin >> t;
	if ( t >= 20 )
		return 1;
	int data[t];

	for( int i = 0; i < t ; i++)
	{
		int x[3];
		cin >> x[0] >> x[1] >> x[2];
		ordenar(x, 3);
		data[i] = x[1];
	}

	for( int i = 0; i < t ; i++)
		cout << "Case " << i+1 << ": " << data[i] << endl;

	return 0;
}