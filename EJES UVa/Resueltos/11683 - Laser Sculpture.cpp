#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define SZ 2500000
#define INF 1000000000

using namespace std;

int main() {
    int h, l;
    int x, cont, d, sum;
    int i;
    while(scanf("%d%d", &h, &l), h|l) {
	sum = 0;
	scanf("%d", &x);
	cont = h-x;
	loop(i, 0, l-1) {
	    scanf("%d", &x);
	    d = h-x; 
	    if (d < cont) {
		sum += cont -d;
	    }
	    cont -= cont - d;
	    cont = RANGE(cont, 0, h);
	}
	sum += cont;

	printf("%d\n", sum);
    }

    return 0;
}
	
