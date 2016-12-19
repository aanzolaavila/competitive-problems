/* 11850 - Alaska */

#include <cstdio>
#include <algorithm>
using namespace std;

bool es_posible(const int n, int lista[])
{
	int posicion = 0;
	for(int i = 0; i < n-1; i++)
	{
		int dist = lista[i+1] - lista[i];
		if(dist <= 200)
			posicion = lista[i+1];
		else
			return false;
	}
	
	return ((1422 - posicion) <= (200 - 1422 + posicion));
}

int main()
{
	bool finalizado = false;
	while(! finalizado)
	{
		int n;
		scanf("%d", &n);
		if(n == 0)
		{
			finalizado = true;
			continue;
		}
		
		int lista[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &lista[i]);
			
		sort(lista, lista+n);
		
		if(es_posible(n, lista ))
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	
	return 0;
}