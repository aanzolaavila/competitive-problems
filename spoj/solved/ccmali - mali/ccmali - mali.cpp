#include <bits/stdc++.h>
#define F first
#define S second
#define INF 100000000;

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n, a, b, s;
    ii sa, sb;
    while(scanf("%d", &n) != EOF) {
	sa.F = INF; sa.S = 0;
	sb.F = INF; sb.S = 0;
	while(n--) {
	    scanf("%d%d", &a, &b);
	    sa.F = min(a, sa.F);
	    sa.S = max(a, sa.S);
	    sb.F = min(b, sb.F);
	    sb.S = max(b, sb.S);

	    s = max(sa.F + sb.S, sa.S + sb.F);
	    printf("%d\n", s);
	}
    }

    return 0;
}
