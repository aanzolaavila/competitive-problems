#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 1500
#define N 1010
#define INF 1000000000

using namespace std;

char a[SZ];
char b[SZ];

int mem[N][N];

int calc(int i, int j) {
    if (mem[i][j] != -1) return mem[i][j];

    if (a[i] == '\n' || a[i] == '\0' || b[j] == '\n' || b[j] == '\0')
	return mem[i][j] = 0;

    if (a[i] == b[j])
	return mem[i][j] = 1 + calc(i+1, j+1);

    return mem[i][j] = max( calc(i+1, j), calc(i, j+1) );
}

int main() {
    int i, j;
    while(fgets(a, SZ, stdin) != NULL) {
	fgets(b, SZ, stdin);

	loop(i, 0, N) {
	    loop(j, 0, N) {
		mem[i][j] = -1;
	    }
	}

	printf("%d\n", calc(0, 0));
    }

    return 0;
}
