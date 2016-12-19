#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; ++i)
using namespace std;

int main() {
    int n, f;
    unsigned long long sum;
    scanf("%d", &n);
    int i, j, a, b;
    loop(i, 0, n) {
	scanf("%d", &f);
	sum = 0;
	loop(j, 0, f) {
	    scanf("%d %*d %d", &a, &b);
	    sum += a*b;
	}
	printf("%lld\n", sum);
    }

    return 0;
}
