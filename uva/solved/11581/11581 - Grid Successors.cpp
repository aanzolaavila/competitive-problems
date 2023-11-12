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
#define SZ 1000
#define N 60
#define M 10010
#define INF 1000000000
#define MP make_pair
#define F first
#define S second
#define C(x) (1 << (x))
#define X(n, x) ((n) & C(x) ? 1 : 0)

using namespace std;

inline int next(int i) {
    //printf("i = %d\n", i);
    
    int r = 0;
    r |= C(8) * (X(i, 7) ^ X(i, 5));
    r |= C(7) * (X(i, 8) ^ X(i, 4) ^ X(i, 6));
    r |= C(6) * (X(i, 7) ^ X(i, 3));
    r |= C(5) * (X(i, 8) ^ X(i, 4) ^ X(i, 2));
    r |= C(4) * (X(i, 7) ^ X(i, 5) ^ X(i, 3) ^ X(i, 1));
    r |= C(3) * (X(i, 6) ^ X(i, 4) ^ X(i, 0));
    r |= C(2) * (X(i, 5) ^ X(i, 1));
    r |= C(1) * (X(i, 2) ^ X(i, 4) ^ X(i, 0));
    r |= C(0) * (X(i, 1) ^ X(i, 3));

    //printf("r = %d\n", r);
    
    return r;
}

char in[SZ];
char * ptr;

char nextc() {
    while(!INRANGE(*ptr, '0', '9')) {
	ptr++;
	if (*ptr == '\n' || *ptr == '\0') {
	    fgets(in, SZ, stdin);
	    ptr = in;
	}
    }
    
    return *ptr++;
}

int calc(int n) {
    if (n == 0) return -1;
    int i = 0;
    while((n = next(n)) != 0) {
	i++;
    }

    return i;
}

int main() {
    int t;
    scanf("%d\n", &t);

    int i, n;
    fgets(in, SZ, stdin);
    ptr = in;
    while(t--){
	n = 0;
	loop(i, 0, 9) {
	    if (nextc() == '1') {
		n |= C(8-i);
	    }
	}
	//printf("n = %d\n", n);
	
	printf("%d\n", calc(n));
    }

    return 0;
}
