#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 60
#define INF 1000000000
#define EPS 1e-9

using namespace std;

int med;
int sum;

int vec[SZ];

int main() {
    int n;
    int i;
    int c = 1;
    while(scanf("%d", &n), n) {
	sum = med = 0;
	loop(i, 0, n) {
	    scanf("%d", vec+i);
	    med += vec[i];
	}

	med /= n;
	loop(i, 0, n) {
	    sum += abs(vec[i] - med);
	}

	printf("Set #%d\nThe minimum number of moves is %d.\n\n", c++, sum/2);
    }

    return 0;
}
