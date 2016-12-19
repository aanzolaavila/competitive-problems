#include <bits/stdc++.h>

#define f(x) ((int)((x) / 2))
#define odds(x) ((x)*((x)+2) +1)
#define loop(i, x, y) for(i = x; i < y; ++i)

using namespace std;

int main() {
    int t, a, b, i;
    scanf("%d", &t);
    loop(i, 0, t) {
	scanf("%d\n%d", &a, &b);
	printf("Case %d: %d\n", i+1, odds(f(b-1)) - odds(f(a-2)));
    }

    return 0;
}
