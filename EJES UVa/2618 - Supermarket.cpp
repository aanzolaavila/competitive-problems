#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = (ii); i < (ff); i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 100010
#define N 1010
#define INF 1000000000.0

using namespace std;

int jones[N];
int nums[SZ];
double prices[SZ];
int m, n;

double mem[N][SZ];

double calc();
void print_wors();
double rec(int, int);

int main() {
    int i, j;
    while(scanf("%d%d", &m, &n), m|n) {
	loop(i, 0, m) {
	    scanf("%d", jones+i);
	}

	loop(i, 0, n) {
	    scanf("%d%lf", nums+i, prices+i);
	}

	loop(i, 0, m) {
	    loop(j, 0, n) {
		mem[i][j] = -INF;
	    }
	}
	
	double mi = rec(m-1, n-1);
	if (mi < INF) {
	    printf("%.2lf\n", m);
	} else {
	    puts("Impossible");
	}
    }

    return 0;
}

double row1[SZ], row2[SZ];

void print_rows() {
    int i;
    loop(i, 0, n) {
	printf("%.2lf ", row1[i]);
    }
    puts("");

    loop(i, 0, n) {
	printf("%.2lf ", row2[i]);
    }
    puts("");
}



double rec(int i, int j) {
    printf("(%d %d)\n", i, j);
    //if (mem[i][j] >= 0.0) return mem[i][j];
    double &mi = mem[i][j];
    if (i == 0 && j == 0) return nums[j] == jones[i] ?  prices[j] : INF;
    if (j == 0) return INF;
    if (j < 0 || i < 0) return INF;

    if (nums[j] == jones[i]) {
	printf("Si %lf\n", prices[j]);
	return mi = min(prices[j] + rec(i-1, j-1), rec(i, j-1));
    } else {
	mi = rec(i, j-1);
	printf("No (%lf)\n", mi);
	return mi;
    }
}

double calc() {
    double *prev = row1;
    double *actual = row2;

    memset(row1, 0, sizeof(row1));
    memset(row2, 0, sizeof(row2));

    int i, j;
    loop(i, 1, m) {
	actual[0] = INF;
	//prev[0] = 0;
	loop(j, 1, n) {
	    if (jones[i] == nums[j]) {
		actual[j] = min(prices[j] + prev[j-1], actual[j-1]);
	    } else {
		actual[j] = actual[j-1];
	    }
	}
	print_rows();
	printf("%p %p\n", actual, prev);
	swap(actual, prev);
    }
    
    return prev[n-1];
}
