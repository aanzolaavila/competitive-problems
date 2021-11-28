#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define INF 100000000

using namespace std;

int main() {
    int i, j, t, n, m, v;

    scanf("%d", &t);
    loop(i, 0, t) {
	m = -INF;

	scanf("%d", &n);
	loop(j, 0, n) {
	    scanf("%d", &v);
	    m = m < v ? v : m;
	}

	printf("Case %d: %d\n", i+1, m);

    }

    return 0;

}
