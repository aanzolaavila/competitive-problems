#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define SZ 25

using namespace std;

int main() {
    int casen = 1;
    int n, m, c;
    int state;
    int i, j, sum, max;
    int ca[SZ];
    while(scanf("%d%d%d", &n, &m, &c), n|m|c) {
	max = sum = state = 0;
	loop(i, 0, n) {
	    scanf("%d", ca+i);
	}

	loop(i, 0, m) {
	    scanf("%d", &j);
	    state ^= (1 << (j-1));

	    sum = 0;
	    loop(j, 0, n) {
		sum += state & (1 << j) ? ca[j] : 0;
	    }
	    max = max < sum ? sum : max;
	}

	sum = 0;
	loop(i, 0, n) {
	    sum += state & (1 << i) ? ca[i] : 0;
	}

	printf("Sequence %d\n", casen++);
	printf("Fuse was %sblown.\n", sum > c ? "" : "not ");
	if (sum <= c) {
	    printf("Maximal power consumption was %d amperes.\n", max);
	}
	printf("\n");
    }

    return 0;
}
