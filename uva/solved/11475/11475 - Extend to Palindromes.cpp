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
#define SZ 2*101000
#define INF 1000000000
#define MP make_pair
#define F first
#define S second
#define MOD(n, M) ((((n) % (M)) + (M)) % (M))

using namespace std;

char T[SZ];
char P[SZ];
int b[SZ];

int k;

int n, m;
int c;

char at(int i) {
    //printf("i: %d (%c)\n", ABS(k-i-1), T[ABS(k-i-1)]);
    return T[ (i < k ? i : MOD(k-i-1, n)) ];
}

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
    static int cc = 0;
    static int i = 0, j = 0;
    if (cc != c) {
	cc = c;
	i = 0;
	j = 0;
    }
    //if (i > 0) i--;
    while(i < n) {
	while(j >= 0 && at(i) != P[j]) {
	    //i--;
	    return false;
	    j = b[j];
	}

	i++, j++;
	if (j == m) {
	    //i--;
	    return true;
	    j = b[j];
	}
    }

    return false;
}

int calc() {
    k = 0;
    strcpy(P, T);
    bool r;
    m = n;
    kmpPreprocess();

    r = kmpSearch();
    while(!r && k < n) {
	//printf("k: %d\n", k);
	k++;
	r = kmpSearch();
    }

    return k;
}

int main() {
    /*strcpy(T, "amanaplanacanal");
    n = strlen(T);
    k = 6;*/
    int i;
    /*loop(i, 0, n) {
	printf("%c", at(i));
    }
    puts("");*/

    c = 0;
    while(fgets(T, SZ, stdin) != NULL) {
	n = strlen(T);
	if (T[n-1] == '\n') {
	    T[--n] = '\0';
	}
	printf("%s", T);
	int k = calc();
	i = n;
	while(k--) {
	    T[i++] = T[k];
	}
	T[i] = '\0';

	printf("%s\n", T+n);
	c++;
    }
    
    return 0;
}
