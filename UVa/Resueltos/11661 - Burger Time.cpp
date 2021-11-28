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
    int l;
    int dist;
    int d, r;

    int i, j;
    char a;
    while(scanf("%d\n", &l), l) {
	d = r = dist = INF;
	loop(i, 0, l) {
	    a = getchar();
	    if (a == 'Z')
		dist = 0;
	    
	    if (a == 'R') {
		r = i;
		dist = MIN(dist, ABS(r-d));
	    }
	    
	    if (a == 'D') {
		d = i;
		dist = MIN(dist, ABS(r-d));
	    }
	}

	printf("%d\n", dist);
    }

    return 0;
}
