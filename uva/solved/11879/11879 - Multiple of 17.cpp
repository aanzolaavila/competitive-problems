#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 2000000
#define INF 1000000000

typedef long long int ll;

using namespace std;

char in[SZ];

inline bool divi(const int &n) {
    ll r = 0;
    char * i = in;
    while(INRANGE(*i, '0', '9')) {
	r = (r*10 + *(i++) - '0') % n;
    }
    
    return r == 0;
}

int main() {
    while(fgets(in, SZ, stdin), strcmp("0\n", in) != 0) {
	printf("%d\n", divi(17));
    }

    return 0;
}
