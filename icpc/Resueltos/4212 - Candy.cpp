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
#define SZ 10000000
#define N 100010
#define M 100010
#define INF 1000000000

using namespace std;

int vec[N];

int len;

int mem[N];

int f(int *vec, int i) {
    int &m = mem[i];
    if (m != -1) return m;
    
    if (i == len-1) {
	return m = vec[i];
    } else if (i >= len) {
	return m = 0;
    }

    return m = max(vec[i] + f(vec, i+2), f(vec, i+1));
}

int r[M];

inline void reset() {
    memset(mem, -1, sizeof(int)*(len+1));
}

int f2(const int *v, int n) {
    if (n == 1) return v[0];
    mem[n] = 0;
    mem[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--) {
	mem[i] = max(v[i] + mem[i+2], mem[i+1]);
    }

    /*int i;
    loop(i, 0, n){
	printf("(%d)%d ",v[i], mem[i]);
    }
    puts("");*/

    return mem[0];
}

int main() {
    int m, n;

    int i, j;
    while(scanf("%d%d", &m, &n), m | n) {
	len = n;
	loop(j, 0, m) {
	    //reset();
	    loop(i, 0, n) {
		scanf("%d", vec+i);
	    }
	    r[j] = f2(vec, n);
	}

	len = m;
	//reset();
	printf("%d\n", f2(r, m));
    }

    return 0;
}
