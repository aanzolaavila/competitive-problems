#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define SZ 1500000
#define INF 1000000000

using namespace std;

char s[SZ];
int n;

inline int f() {
    if (n == 1 && s[0] == '1')
	return 1;
    int i = 1;
    int b;
    do {
	++i;
	b = n;
	n = ((int)log10(n)) +1;
    } while(n != b);

    return i;
}

int main() {
    while(scanf("%s%n\n", s, &n), strcmp("END", s) != 0) {
	printf("%d\n", f());
    }
    
    return 0;
}
