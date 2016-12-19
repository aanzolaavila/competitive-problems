#include <bits/stdc++.h>

#define INF 10000000
#define SZ 1000010

using namespace std;

typedef long long int lli;

int mem[SZ];

inline lli f91(int n) {
    return mem[n] != INF ? mem[n] : mem[n] = (n >= 101 ? n -10 : f91( f91(n + 11) ));
}

int main() {
    for (int i = 0; i < SZ; ++i) mem[i] = INF;
    int n;
    while(scanf("%d", &n), n) {
	printf("f91(%d) = %lld\n", n, f91(n));
    }

    return 0;
}
