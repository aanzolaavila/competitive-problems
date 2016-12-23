#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define SZ 110
#define INF 1000000000

using namespace std;

int cs[SZ];

int main() {
    int k, m, c, r;
    int i, j, req, t;
    bool yes;
    while(scanf("%d", &k), k) {
	yes = true;
	scanf("%d", &m);
	loop(i, 0, k) {
	    scanf("%d", cs+i);
	}

	loop(i, 0, m) {
	    req = 0;
	    scanf("%d%d", &c, &r);
	    loop(j, 0, c) {
		scanf("%d", &t);
 		req += *find(cs, cs+k, t) == t ? 1 : 0;
	    }
	    yes &= (req >= r);
	}

	printf("%s\n", yes ? "yes" : "no");

    }

    return 0;
}
