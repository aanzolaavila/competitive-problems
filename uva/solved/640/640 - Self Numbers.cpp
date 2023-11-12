#include <bits/stdc++.h>

#define SZ 1000001

using namespace std;

bool nots[SZ];

inline void next(int &n) {
    int s = n;
    while(n) {
	s += n % 10;
	n /= 10;
    }
    n = s;
}

void calc() {
    memset(nots, 0, sizeof(nots));
    nots[0] = 1;
    int i, j;
    for(i = 1; i < SZ; ++i) {
	if ( !nots[j = i] ) {
	    printf("%d\n", i);
	    while((next(j), j) < SZ && !nots[j]) nots[j] = true;
	}
    }
}
	
int main() {
    calc();
    return 0;
}
