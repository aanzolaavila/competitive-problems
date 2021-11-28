#include <bits/stdc++.h>
#define abs(x) ((x) > 0 ? (x) : -(x))

using namespace std;

int main() {
    long long int n, t;
    while (scanf("%lld %lld", &n, &t) != EOF) {
	printf("%llu\n", abs(t-n));
    }

    return 0;
}
