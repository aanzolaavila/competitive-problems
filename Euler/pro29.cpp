/*Considerando todas las combinaciones de enteros de ab para 2 ≤ a ≤ 5 y 2 ≤ b ≤ 5, obtenemos:

2^2=4, 2^3=8, 2^4=16, 2^5=32 
32=9, 33=27, 34=81, 35=243 
42=16, 43=64, 44=256, 45=1024 
52=25, 53=125, 54=625, 55=3125 
Si a continuación se colocan en orden numérico, eliminando cualquier elemento repetido, tenemos la siguiente secuencia de 15 términos diferentes:

4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

¿Cuántos términos distintos hay en la secuencia generada por abpara 2 ≤ a ≤ 100 y 2 ≤ b ≤ 100?*/

#include <bits/stdc++.h>
using namespace std;

int a, b;
int INF = 2, SUP = 100;

set<double> mem;

int main() {
    for(a = INF; a <= SUP; ++a) {
	for (b = INF; b <= SUP; ++b) {
	    mem.insert(pow(a, b));
	}
    }

    printf("%d\n", mem.size());

    return 0;
}
