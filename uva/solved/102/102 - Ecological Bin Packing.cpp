/*102 - Ecological Bin Packing*/
#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;

void asignar_permutacion(char []);
void generar_permutaciones(char [], int, int);
int movimientos(const int);
bool precedencia_alfabetica(char [], char []);

enum tipos {B, G, C};
int valores[3][3];
char permutaciones[6][4];

int main()
{
	char a[] = "BCG";
	generar_permutaciones(a, 0, 2);

	/*for(int i = 0; i < 6 ; i++)
		printf("%s\n", permutaciones[i] );*/
	
	while( scanf("%d", &valores[0][B]) != EOF )
	{
		scanf("%d %d", &valores[0][G], &valores[0][C]);
		for (int i = 1; i < 3; ++i)
			scanf("%d %d %d", &valores[i][B], &valores[i][G], &valores[i][C]);
		
		int optimo = 0, moves = movimientos(0), m;
		for(int i = 1; i < 6; i++)
			if((m = movimientos(i)) < moves)
			{
				moves = m;
				optimo = i;
			} else 
			if(m == moves)
				if(precedencia_alfabetica(permutaciones[i], permutaciones[optimo]))
					optimo = i;

		printf("%s %d\n", permutaciones[optimo], moves);
	}

	return 0;
}

void asignar_permutacion(char p[])
{
	static int pos = 0;
	strcpy(permutaciones[pos++], p);
}

void generar_permutaciones(char a[], int i, int n)
{
	int j;
	if (i == n)
		asignar_permutacion(a);
	else
	{
       for (j = i; j <= n; j++)
       {
          swap(a[i], a[j]);          
          generar_permutaciones(a, i+1, n);
          swap(a[i], a[j]);
       }
   }
}

int movimientos(const int n)
{
	const char * const p = permutaciones[n];
	int m = 0;
	for(int i = 0; i < 3; i++)
	{
		int caso = ((p[i] == 'B')? B : ((p[i] == 'G')? G : C));
		switch(caso)
		{
			case B:
				m += valores[i][G] + valores[i][C];
				break;
			case G:
				m += valores[i][B] + valores[i][C];
				break;
			case C:
				m += valores[i][B] + valores[i][G];
				break;
		}
	}
	return m;
}

bool precedencia_alfabetica(char a[], char b[])
{
	for(int i = 0; i < 3; i++)
	{
		if(a[i] == b[i])
			continue;
		return (a[i] < b[i]);
	}
	return false;
}