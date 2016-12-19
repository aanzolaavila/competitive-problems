#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; ++i)
#define SZ 50
#define INF 100000000
using namespace std;

int n, b, h, w, p, a;

int main() {
    int i, j, min;
    while(scanf("%d%d%d%d", &n, &b, &h, &w) != EOF) {
	min = INF;
	loop(i, 0, h) {
	    scanf("%d", &p);

	    for(j = 0; j < w; ++j) {
		scanf("%d", &a);
		min = a >= n && min > p*n ? p*n : min;
	    }
	}

	if (min <= b)
	    printf("%d\n", min);
	else
	    printf("stay home\n");
    }

    return 0;
}
