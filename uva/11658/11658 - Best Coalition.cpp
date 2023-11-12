/* 11658 - Best Coalition */

#include <cstdio>
#include <bitset>
#include <numeric> // accumulate(*inicio, *final, init) [inicio, final)
//#include <utility> // swap
#include <algorithm> // sort
#include <iostream>
using namespace std;

typedef double lf;

lf sum(const int c, const int n, const lf lista[])
{
	lf suma = 0;
	bitset<100> l(c);
	cout << l << endl;
	for(int i = 0; i < n ; i++)
		if( l.test(i) ) suma += lista[i];
	return suma;
}

lf best_coalition(const int n, const int x, lf lista[])
{
	lf actual = lista[x];
	if(actual >= 50.0)
		return 100.0;
	
	swap(lista[x], lista[n-1]);
	
	sort(lista, lista+n-1);
	
	lf mejor = 0.0;
	lf suma, p;
	
	lf lim = 1 << n;
	for(lf i = 1; i < lim ; i++ )
	{
		if((suma = sum(i, n, lista) ) > 50.0)
				if((p = (actual * 100.0)/suma) > mejor)
					mejor = p;
	}
	
	return mejor;
}
/*lf best_coalition(const int n, const int x, lf lista[])
{
	lf actual = lista[x];
	if(actual >= 50.0)
		return 100.0;
	
	swap(lista[x], lista[n-1]);
	
	sort(lista, lista+n-1);
	
	lf mejor = 0.0;
	lf suma, p;
	
	for(int inicio = 0; inicio < n-1 ; inicio++)
		for(int final = inicio+1; final < n ; final++ )
			if((suma = accumulate(lista+inicio, lista+final, actual) ) > 50.0)
				if((p = (actual * 100.0)/suma) > mejor)
					mejor = p;
	return mejor;
}*/

int main()
{
	int n, x;
	while(scanf("%d %d", &n, &x), (n || x))
	{
		lf lista[n];
		for(int i = 0; i < n; i++)
			scanf("%lf", lista+i );
		
		lf b = best_coalition(n, x-1, lista);
		printf("%.2f\n", ( (((int)(b*1000.0)) % 10) >=5)? b + 0.005 : b );
	}
	
	return 0;
}