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

typedef long long ll;

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

inline bool isLeap() {
    return divi(400) || ( divi(4) && !divi(100) );
}

int main() {
    bool f = true;
    bool leap;
    bool s;
    while(fgets(in, SZ, stdin) != NULL) {
	s = leap = isLeap();
	if (!f)
	    printf("\n");
	f = false;
	
	if (leap)
	    printf("This is leap year.\n");
	if ( divi(15) ) {
	    printf("This is huluculu festival year.\n");
	    s = true;
	}
	if (leap && divi(55))
	    printf("This is bulukulu festival year.\n");
	if (!s)
	    printf("This is an ordinary year.\n");
    }

    return 0;
}
