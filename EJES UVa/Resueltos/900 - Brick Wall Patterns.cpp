#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x ; it < y; ++it)

typedef long long int lli;

using namespace std;

map<int, lli> rec;

lli calc(int n) {
    if (rec.count(n) != 0)
	return rec[n];
    return rec[n] = calc(n-1) + calc(n-2);
}

int main() {
    int n;
    rec[0] = rec[1] = 1;
    while(scanf("%d\n", &n), n != 0) {
	printf("%lli\n", calc(n));
    }

    return 0;
}
