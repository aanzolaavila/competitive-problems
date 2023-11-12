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
#define SZ 110
#define INF 1000000000
#define F first
#define S second
#define MP make_pair
#define N 30001

using namespace std;

int coins[SZ];
int l, n, c, t;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int memo[N];

pair<int, int> calc(int n, int m) {
    memo[0] = 0;
    int i, j;
    loop(i, 1, N) {
	memo[i] = INF;
    }

    loop(i, 0, m) {
	loopd(j, N-coins[i]-1, 0) {
	    if(memo[j] < INF) {
		memo[j+coins[i]] = min(memo[j+coins[i]], memo[j]+1);
	    }
	}
    }

    int mn = INF;
    int v = 0;
    for(i = 0; i < N && mn == INF; i++) {
	if (i >= n) {
	    if (mn > memo[i]) {
		mn = memo[i];
		v = i;
	    }
	}
    }

    return MP(v, mn);
}

int main() {
    scanf("%d", &t);

    int i;
    while(t--) {
	scanf("%d%d", &l, &n);
	loop(i, 0, n) {
	    scanf("%d", coins+i);
	}
	
	//sort(coins, coins+n);

	//mem.clear();
	
	ii r = calc(l, n);
	printf("%d %d\n", r.F, r.S);
    }
    
    return 0;
}

