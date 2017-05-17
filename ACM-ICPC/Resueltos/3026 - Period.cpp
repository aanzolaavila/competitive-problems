//#define NDEBUG
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
#define SZ 2000000
#define N 1000000
#define INF 1000000000
#define MP make_pair
#define F first
#define S second

using namespace std;

char T[SZ], P[SZ];
int b[SZ];

int n, m;

void kmpPreprocess() {
    int i = 0, j = -1; b[0] = -1;
    while(i < m) {
	while(j >= 0 && P[i] != P[j]) {
	    j = b[j];
	}
	
	i++, j++;
	b[i] = j;
    }
}

bool kmpSearch() {
    int i = 0, j = 0;
    while(i < n) {
	while(j >= 0 && T[i] != P[j]) {
	    return false;
	    j = b[j];
	}

	i++, j++;
	if (j == m) {
	    return true;
	    j = b[j];
	}
    }

    return false;
}

bool vis[N+100];

void calc() {
    memset(vis, 0, sizeof vis);

    for(int i = 0; i < n; i++) {
	//printf("i: %d\n", i);
	if (!vis[i]) {
	    vis[i] = 1;
	    int k = i+1;
	    //printf("k: %d\n", k);
	    for(int j = i+k; j < n && P[i] == P[j]; j += k) {
		//printf("j: %d, j-k: %d\n", j, j-k);
		if (b[j] == j-k) {
		    vis[j] = 1;
		    printf("%d %d\n", j+1, (j-i)/k+1);
		}
	    }
	}
    }
}

int main() {
    int t = 1;
    int i;

    /*strcpy(P, "aa");
    m = n = strlen(P);
    kmpPreprocess();
    loop(i, 0, n+1) {
	printf("%2d", b[i]);
    }
    puts("");

    loop(i, 0, n) {
	printf("%2c", P[i]);
    }
    puts("");

    loop(i, 0, n) {
	printf("%2d", i);
    }
    puts("");*/
    
    while(scanf("%d\n", &n), n) {
	printf("Test case #%d\n", t++);
	fgets(P, SZ, stdin);
	m = n;
	P[n] = '\0';
	//printf("%s\n", P);
	kmpPreprocess();
	calc();
	puts("");
    }

    return 0;
}
