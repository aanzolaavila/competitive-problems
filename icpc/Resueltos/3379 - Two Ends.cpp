#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 10000000
#define N 1000
#define INF 100000000

using namespace std;

char in[SZ];
int nums[N];
char * p;
int mem[N][N];

inline void read(int &n) {
    while(! INRANGE(*p, '0', '9')) p++;

    n = 0;
    while(INRANGE(*p, '0', '9')) {
	n = 10*n + *p++ - '0';
    }
}

void readnums(int n) {
    int i = 0;
    p = in;
    while(n--) {
	read(nums[i++]);
    }
}

void print(int i, int j) {
    int ii;
    loop(ii, i, j+1) {
	printf(" %d", nums[ii]);
    }
    //puts("");
}

int solve(int i, int j);

//int c;

int main() {
    int n, m = 1, p;
    int i, j;
    while(scanf("%d", &n), n) {
	fgets(in, SZ, stdin);
	readnums(n);

	loop(i, 0, n) {
	    loop(j, 0, n) {
		mem[i][j] = -INF;
	    }
	}

	/*i = 0;
	while( (p = solve(i, n-1)) == 0 ) {
	    i++;
	    }*/
	p = solve(0, n-1);
	printf("In game %d, the greedy strategy might lose by as many as %d points.\n", m++, p);
    }

    return 0;
}

int solve(int i, int j) {
    if (mem[i][j] != -INF) return mem[i][j];

    if (j - i == 1) {
	return mem[i][j] = abs(nums[i] - nums[j]);
    }

    /*if (i - j == 0) {
	return mem[i][j] = nums[i];
	}*/
    
    if (j - i <= 0 ) {
	//printf("error");
	return -INF;
    }

    int a = nums[i];
    {
	if (nums[i+1] >= nums[j]) {
	    a += solve(i+2, j) - nums[i+1];
	} else {
	    a += solve(i+1, j-1) - nums[j];
	}
    }

    int b = nums[j];
    {
	if (nums[i] >= nums[j-1]) {
	    b += solve(i+1, j-1) - nums[i];
	} else {
	    b += solve(i, j-2) - nums[j-1];
	}
    }

    return mem[i][j] = max(a, b);
}

