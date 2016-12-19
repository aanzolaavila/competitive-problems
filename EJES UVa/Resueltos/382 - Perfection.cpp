#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x; it < y; ++it)
#define SZ 10

using namespace std;

typedef long long int lli;

inline int digs(int n) {
    int c = 0;
    do {
	n /= 10;
	++c;
    } while(n);
    return c;
}

inline void format(int n) {
    int d = digs(n), i;
    loop(i, 0, 5-d)
	printf(" ");
    printf("%d  ", n);
}

lli sum(int n) {
    lli s = 0;
    int i;
    loop(i, 1, n/2+1) {
	s += n % i == 0 ? i : 0;
    }
    return s;
}

int main() {
    int n;
    lli s;
    printf("PERFECTION OUTPUT\n");
    while (scanf("%d", &n), n != 0) {
	format(n);
	if ((s = sum(n)) == n)
	    printf("PERFECT\n");
	else if (s > n)
	    printf("ABUNDANT\n");
	else
	    printf("DEFICIENT\n");
    }
    printf("END OF OUTPUT\n");

    return 0;
}
