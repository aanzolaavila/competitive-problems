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
#define SZ 1000
#define N 200
#define INF 1000000000
#define EPS 1e-9

using namespace std;

int mor[N];
int af[N];

int n, d, r;

int calc() {
    int ex = 0;
    int tmp;

    int i;
    loop(i, 0, n) {
	tmp = mor[i] + af[n-i-1] - d;
	ex += RANGE(tmp, 0, INF);
    }

    return ex * r;
}

int main() {
    char in[SZ];

    int i;
    while(scanf("%d%d%d", &n, &d, &r), n|d|r) {
	loop(i, 0, n) {
	    scanf("%d", mor+i);
	}

	loop(i, 0, n) {
	    scanf("%d", af+i);
	}

	sort(mor, mor+n);
	sort(af, af+n);

	printf("%d\n", calc());
    }

    return 0;
}
