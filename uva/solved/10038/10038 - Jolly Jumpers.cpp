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
#define SZ 3500
#define N 4
#define INF 1000000000
#define EPS 1e-9

using namespace std;

int n;
int ns[SZ];
bool v[SZ];

bool calc() {
    if (n < 1) return false;
    if (n == 1) return true;
    
    int i;
    memset(v, 0, sizeof(bool)*n);
    bool r = true;
    int a;
    for(i = 0; i < n-1 && r; i++) {
	a = abs(ns[i] - ns[i+1]);
	if (!INRANGE(a, 0, n-1)) {
	    r = false;
	} else {
	    v[a-1] = true;
	}
    }

    for(i = 0; i < n-1 && r; i++) {
	r &= v[i];
    }

    return r;
}

int main() {
    int i;
    while(scanf("%d", &n) != EOF) {
	loop(i, 0, n) {
	    scanf("%d", ns+i);
	}

	printf("%s\n", calc() ? "Jolly" : "Not jolly");
    }

    return 0;
}
