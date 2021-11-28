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
#define SZ 85
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

void kmpPreprocess(char *ptr, int m) {
    int i = 0, j = -1; b[0] = -1;
    while(i < m) {
	while(j >= 0 && ptr[i] != ptr[j]) {
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

unsigned int mem[SZ][SZ];
unsigned int gmem[SZ][SZ];
bool vis[SZ];

int g(int i, int j) {
    unsigned int &me = gmem[i][j];
    if (me <= INF) return me;
    
    char * ptr = P+i;
    int n = j-i+1;
    //printf("G(i: %d, j: %d) -> n: %d\n", i, j, n);
    kmpPreprocess(ptr, n);

    memset(vis, 0, sizeof(bool)*(n+1));

    int step = n;
    bool f = false;

    for(int i = 0; i < n/2+1 && !f; i++) {
	if (!vis[i]) {
	    vis[i] = 1;
	    int k = i+1;
	    for(int j = i+k; j < n && ptr[i] == ptr[j] && b[j] == j-k && !f; j += k) {
		if (j == n-1) {
		    //printf("G: %d\n", k);
		    step = min(step, k);
		    f = true;
		}
	    }
	}
    }

    return me = step;
}

int f(int i, int j) {
    unsigned int &me = mem[i][j];
    if (me <= INF) return me;
    
    if (i > j) return me = INF;
    if (i == j) return me = 1;
    int l = g(i, j);
    if (l < j-i+1) {
	//printf("l: %d, min: %d\n", l, f(i, l-1));
	l = min(l, f(i, i+l-1));
	return l;
    }

    int k;
    loop(k, i, j) {
	//printf("f(%d, %d) + f(%d, %d)| l = %d\n", i, k, k+1, j, l);
	l = min(l, f(i, k) +f(k+1, j));
    }

    return me = l;
}

int calc() {
    memset(mem, 0xff, sizeof mem);
    memset(gmem, 0xff, sizeof gmem);
    return f(0, m-1);
}

int main() {
    int i;
    
    /*strcpy(P, "PRATTATTATTIC");
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

    /*strcpy(P, "BABBABABBABBA");
    n = m = strlen(P);
    memset(gmem, 0xff, sizeof gmem);
    printf("%d (%d, %d), %d\n",g(0, m-1),  f(0, 9),  f(10, 12), f(0, m-1));*/
    
    //return 0;
    
    while(fgets(P, SZ, stdin), P[0] != '*') {
	m = n = strlen(P);
	if (P[n-1] == '\n') {
	    P[--n] = '\0';
	    --m;
	}

	printf("%d\n", calc());
	
    }

    return 0;
}
