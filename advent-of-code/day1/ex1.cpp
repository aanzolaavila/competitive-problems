#include <bits/stdc++.h>
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define PB push_back
#define SZ 100000
#define INF 1000000000

using namespace std;


int main() {
	int a = -1, b, c = 0;
	while(scanf("%d", &b) != EOF) {
		if(a != -1) {
			c += b > a ? 1 : 0;
		}
		a = b;
	}

	printf("%d\n", c);

	return 0;
}
