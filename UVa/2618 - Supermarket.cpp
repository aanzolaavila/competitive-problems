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

	loop(i, 0, m+1) {
	    loop(j, 0, n+1) {
		mem[i][j] = -INF;
	    }
	}

	/*loop(i, 0, m) {
	  printf("%d ", jones[i]);
	}
	puts("");

	loop(i, 0, n) {
	  printf("(%d %lf) ", nums[i], prices[i]);
	  }*/
	
	double mi = rec(0,0);
	/*loop(i, 0, m+1) {
	    loop(j, 0, n+1) {
	      printf("%.2lf ", mem[i][j]);
	    }
	    puts("");
	    }*/
	
	//double mi = calc();
	if (mi < INF) {
	    printf("%.2lf\n", mi);
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
  double &mi = mem[i][j];
  if (/*mem[i][j] != 0.0 &&*/ mi != -INF) return mi;
  
  if (i == m) return mi = 0.0;
  if (j >= n) return mi = INF;

  return mi = nums[j] == jones[i] ? min(prices[j] + rec(i+1, j+1), rec(i, j+1)) : rec(i, j+1);
}

double calc() {
    double *prev = row1;
    double *actual = row2;

    memset(row1, 0, sizeof(row1));
    memset(row2, 0, sizeof(row2));

    //for(int )

    return prev[n-1];
}
