#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define SZ 30
#define INF 1000000000

using namespace std;

char f[SZ];
char s[SZ];

inline int norm(int val) {
    int temp;
    while(val > 9) {
	temp = 0;
	while(val) {
	    temp += val % 10;
	    val /= 10;
	}
	val = temp;
    }

    return val;
}

inline float val() {
    int fv, sv;
    fv = sv = 0;
    char * f = ::f;
    char * s = ::s;
    while(*f != '\0'){
	fv += INRANGE(*f | (1 << 5), 'a', 'z') ?  (*f | (1 << 5)) - 'a' + 1 : 0;
	f++;
    }

    while(*s != '\0'){
	sv += INRANGE(*s | (1 << 5), 'a', 'z') ?  (*s | (1 << 5)) - 'a' + 1 : 0;
	s++;
    }

    fv = norm(fv);
    sv = norm(sv);
    
    return MIN(fv, sv) * 100.0f / MAX(fv, sv);
}

int main() {
    while(fgets(f, SZ, stdin) != NULL) {
	fgets(s, SZ, stdin);
	printf("%.2f %%\n", val());
    }

    return 0;
}
	
