#ifdef __APPLE__
#include "../../stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define loop(it, x, y) for(it = x; it < y; ++it)
#define SZ (1 << 18)
#define MP make_pair
#define F first
#define S second

using namespace std;

typedef unsigned long long large;

bool notp[SZ];
vector<int> primes;

void sieve(large bound) {
    bound++;
    primes.reserve(bound);
    memset(notp, 0, sizeof(notp));
    notp[0] = notp[1] = 1;
    large i, j;
    for(i = 2; i < bound ; i++) {
	if (!notp[i]) {
	    primes.push_back(i);
	    for(j = i*i; j < bound; j += i) {
		notp[j] = 1;
	    }
	}
    }
}

int facs(large n, large p) {
    large s = 0;
    large lim = ((int)(log(n) / (double)log(p)));
    assert(log(p) != 0);
    for(int i = 1; i <= lim; i++) {
	s += (int)(n / (double)pow(p, i));
    }

    return s;
}

vector< pair<int, int> > factors;

bool is_prime(large n) {
    large s = sqrt(n);
    if (s < SZ) return true;
    for(large i = SZ; i < s ; i++) {
	if (n % i == 0) return false;
    }

    return true;
}

inline int fact(int n) {
    switch(n) {
    case 0:
    case 1:
	return 1;
    case 2:
	return 2;
    case 3:
	return 6;
    }
}

bool check(large n, large m) {
    if (n < 3) {
	return fact(n) % m == 0;
    }

    factors.clear();
    int i = 0;
    while(m > 1 && i < primes.size()) {
	if (m % primes[i] == 0) {
	    int c = 0;
	    while(m % primes[i] == 0) {
		++c;
		m /= primes[i];
	    }
	    factors.push_back(MP(primes[i], c));
	}
	i++;
    }

    if (m > 1) {
	factors.push_back(MP(m, 1));
	if (n < m) return false;
    }

    // ++++++++++++++++

    bool f = true;
    for(int i = 0; i < factors.size() && f; i++) {
	f = factors[i].S <= facs(n, factors[i].F);
    }

    return f;
}

int main() {
    sieve(1 << 17);
    large n, m;
    while(scanf("%lld%lld", &n, &m) != EOF) {
	if (m <= n || m == 0 || check(n, m)) {
	    printf("%lld divides %lld!\n", m, n);
	} else {
	    printf("%lld does not divide %lld!\n", m, n);
	}
    }

    return 0;
}
