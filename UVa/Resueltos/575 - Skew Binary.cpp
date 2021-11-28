#include <bits/stdc++.h>
#define SZ 1000000

using namespace std;

typedef unsigned int lli;

inline lli skew2d(char * n) {
    int k = 1, i = strlen(n) -1;
    lli d = 0;
    for(; i >= 0; --i) {
	d += ((1 << k++) - 1) * (n[i] - '0');
    }
    return d;
}

int main() {
    char n[SZ];
    while(scanf("%s", n), strcmp(n, "0") != 0) {
	printf("%u\n", skew2d(n));
    }

    return 0;
}
