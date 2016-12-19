#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli a, b, c;

inline int calc() {
    int op = 0, p = 0;
    do {
	p += a % 10 + b % 10;
	a /= 10; b /= 10;
	if (p >= 10){ ++op; p /= 10; } else p = 0;
    } while(a || b);

    return op;
}

int main() {
    while(scanf("%lli %lli", &a, &b), a != 0 || b != 0) {
	switch(c = calc()) {
	case 0:
	    printf("No carry operation.\n");
	    break;
	case 1:
	    printf("1 carry operation.\n");
	    break;
	default:
	    printf("%lli carry operations.\n", c);
	}
    }

    return 0;
}
