#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 2000000
#define N 1e6
#define INF 1000000000

typedef unsigned long long int ll;

using namespace std;

vector<ll> fac;
int n;

void fact() {
    int i = 0;
    ll n = 1;

    while(n < N) {
	fac.push_back(n);
	++i;
	n *= i;
    }
}

int up() {
    int i = 0;
    while(i < fac.size() && fac[i] <= n)
	i++;
    return fac[i-1];
}

int f() {
    int i = 0;
    while(n) {
	/*int l = up();
	  printf("num: %d\n", l); */
	n -= up();
	++i;
    }

    return i;
}

int main() {
    fact();
    /*int i;
    loop(i, 0, fac.size()) {
	printf("%ld ", fac[i]);
    }
    */
    
    while(scanf("%d", &n) != EOF) {
	printf("%d\n", f());
    }

    return 0;
}
