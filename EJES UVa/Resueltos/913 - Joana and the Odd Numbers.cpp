#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 20000000
#define N 101
#define INF 1000000000

using namespace std;

typedef unsigned long long int ll;

ll n;

inline ll f() {
    ll k = (n-1)/2*(n-1) + 2*(n-1) + 1;
    return 3*k -6;
}

int main() {
    while(scanf("%lu", &n) != EOF) {
	printf("%lu\n", f());
    }

    return 0;
}
