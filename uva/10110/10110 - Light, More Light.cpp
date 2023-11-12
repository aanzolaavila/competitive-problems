#include <bits/stdc++.h>
#define SZ ((unsigned int)~0)

typedef unsigned long long int uint;

using namespace std;

bool notp[SZ];
vector<uint> primes;

void sieve(uint bound) {
    memset(notp, 0, sizeof(notp));
    notp[0] = notp[1] = 1;
    primes.reserve(bound >> 1);
    uint i, j;
    for(i = 2, i < bound; ++i) {
	if (!notp[i]) {
	    primes.push_back(i);
	    for(j = i*i; j < bound; j += i) notp[j] = 1;
	}
    }
}

uint n_divisors(uint n) {
    if (binary_search(primes.begin(), primes.end(), n)) return 1;
    int k = 1, c, p;
    for(int i = 0; n > 1; ++i) {
	c = 0, p = primes[i];
	while (n % p == 0) {
	    ++c;
	    n /= p;
	}
	k *= (c+1);
    }
    return k;
}

bool calc(uint n) {
    
}

int main() {
    sieve(SZ);
    uint n;
    while(scanf("%lld", &n), n) {
	printf("%s\n", calc(n) ? "yes" : "no");
    }

    return 0;
}
