/* 10534 - Wavio Sequence */
#include <cstdio>
#include <algorithm>
using namespace std;

int maximum_wavio_sequence(const int [], const int);

int secuencia[10000];

int main()
{
	int n;
	while( scanf("%d", &n) != EOF )
	{
		for(int i = 0; i < n; i++)
			scanf("%d", secuencia+i);
		printf("%d\n", maximum_wavio_sequence(secuencia, n));
	}

	return 0;
}

int maximum_wavio_sequence(const int original[], const int n)
{
	int result;

	int lim = 0, lim2 = 0, encontrados[n], repetidos[n];
	for (int i = 0; i < n; ++i)
		if( *find(encontrados, encontrados+lim+1, original[i]) != original[i] )
			encontrados[lim++] = original[i];
		else
			if( *find(repetidos, repetidos+lim2+1, original[i]) != original[i] )
				repetidos[lim2++] = original[i];

	sort(repetidos, repetidos+lim2+1);
	sort(encontrados, encontrados+lim+1);

	/*for(int i = 0; i < lim; i++)
		printf("%d\nREP: %d\n", encontrados[i], repetidos[i]);*/

	if(lim2 == 0) return 1;
	result = lim2*2;

	if( encontrados[lim-1] > repetidos[lim2-1] )
		result++;

	if( (encontrados[0] < repetidos[0]) && (encontrados[1] < repetidos[0]) )
		result += 2;

	return result;
}