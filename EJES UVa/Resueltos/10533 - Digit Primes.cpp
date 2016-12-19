#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x; it < y; ++it)
#define SZ 1000010

using namespace std;

typedef long long int lli;

bool notp[SZ];
bool notdp[SZ];
vector<int> dprimes;

inline int sum(int n) {
    int s = 0;
    do {
	s += n % 10;
	n /= 10;
    } while(n);
    return s;
}

void sieve(lli bound) {
    memset(notp, 0, sizeof(notp));
    memset(notdp, 0, sizeof(notdp));
    dprimes.reserve(SZ);
    notp[0] = notp[1] = 1;
    notdp[0] = notdp[1] = 1;
    lli i, j;
    loop(i, 2, bound) {
	if (!notp[i]) {
	    if (notp[sum(i)]) notdp[i] = 1;
	    else dprimes.push_back(i);
	    for(j = i*i; j < bound; j += i) notp[j] = notdp[j] = 1;
	}
    }
}

int main() {
    sieve(SZ);
    int n, a, b, i, j, c;
    scanf("%d", &n);
    loop(i, 0, n) {
	scanf("%d %d", &a, &b);
	c = upper_bound(dprimes.begin(), dprimes.end(), b) - lower_bound(dprimes.begin(), dprimes.end(), a);
	printf("%d\n", c);
    }

    return 0;
}
