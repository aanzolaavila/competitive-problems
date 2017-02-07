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
#define N 70
#define INF 1000000000

using namespace std;

char in[SZ];
char * p;
int nums[N];

inline void read(int &n) {
    while(! INRANGE(*p, '0', '9')) p++;

    n = 0;
    while(INRANGE(*p, '0', '9')) {
	n = 10*n + *p++ - '0';
    }
}

void readnums(int n) {
    int i = 1;
    p = in;
    while(n--) {
	read(nums[i++]);
    }
}

int solve(int, int);

int l, n;
int mem[N][N];

int main() {
    int i, j;
    while(scanf("%d", &l), l) {
	scanf("%d", &n);
	nums[0] = 0;
	loop(i, 1, n+1) {
	    scanf("%d", &nums[i]);
	}
	nums[n+1] = l;

	loop(i, 0, N) {
	    loop(j, 0, N) {
		mem[i][j] = -1;
	    }
	}

	/*loop(i, 0, n+2) {
	    printf(" %d", nums[i]);
	}
	puts("");*/
	
	printf("The minimum cutting is %d.\n", n > 0 ? solve(0, n+1) : 0);
    }

    return 0;
}

int solve(int i, int j) {
    if (mem[i][j] != -1) return mem[i][j];

    if (j - i == 2) {
	return mem[i][j] = nums[j] - nums[i];
    }

    if (j - i == 1) {
	return mem[i][j] = 0;
    }

    if (i >= j) {
	return mem[i][j] = INF;
    }

    int r = nums[j] - nums[i];

    int ii, m = INF;
    loop(ii, i+1, j) {
	m = min( m, solve(i, ii) + solve(ii, j) );
    }

    return mem[i][j] = r + m;
}
