#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) < (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 1000000
#define N 4
#define INF 1000000000
#define EPS 1e-9

using namespace std;

char in[SZ];
char out[SZ];


inline char c(char &s) {
    return s - 7;
}

void convert() {
    char * s = in;
    char * d = out;
    while(*s != '\0' && *s != '\n') {
	*d++ = c(*s++);
    }

    *d = '\0';
}

int main() {
    //printf("%d %d\n", 'J', 'C');
    
    while(fgets(in, SZ, stdin) != NULL) {
	convert();
	printf("%s\n", out);
    }

    return 0;
}
    
