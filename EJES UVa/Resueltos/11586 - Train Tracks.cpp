#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define SZ 500
#define INF 1000000000

using namespace std;

int main() {
    int c, m, f;
    int i, j;
    char str[SZ];
    scanf("%d\n", &c);
    loop(i, 0, c) {
	m = f = 0;
	fgets(str, SZ, stdin);
	int len = strlen(str) -1;
	loop(j, 0, len) {
	    if (str[j] == 'F') {
		++f;
	    } else if (str[j] == 'M') {
		++m;
	    }
	}

	printf("%sLOOP\n", f == m && f != 1 ? "" : "NO ");

    }

    return 0;
}
