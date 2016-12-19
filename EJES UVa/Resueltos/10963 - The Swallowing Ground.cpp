#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff ; ++i)
#define INF 1000000000
using namespace std;

int main() {
    int n, c, f, min, max, m;
    scanf("%d", &n);
    int i, j;
    bool t = false;
    loop(i, 0, n) {
	scanf("%d", &m);
	min = INF;
	max = -INF;
	loop(j, 0, m) {
	    scanf("%d%d", &c, &f);
	    min = min > c-f ? c-f : min;
	    max = max < c-f ? c-f : max;
	}
	if (t) printf("\n");
	t = true;
	printf("%s\n", min == max ? "yes": "no");
    }

    return 0;
}
