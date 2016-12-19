#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x; it < y; ++it)
#define div(n, k) ((int)(n/k))
#define SZ (1 << 18)

using namespace std;

typedef unsigned long long int lli;
typedef map<int, int>::iterator it;

bool notp[SZ];
vector<int> primes;
map<int, int> factors;

void sieve(lli bound) {
    memset(notp, 0, sizeof(notp));
    primes.reserve(bound);
    notp[0] = notp[1] = 1;
    lli i, j;
    loop(i, 2, bound) {
	if (!notp[i]) {
	    primes.push_back(i);
	    for(j = i*i; j < bound; j += i) notp[j] = 1;
	}
    }
}

int n, m;

void factorize() {
    int i = 0;
    while(m > 1 && i < primes.size()) {
	while (m % primes[i] == 0) {
	    factors[primes[i]]++;
	    m /= primes[i];
	}
	++i;
    }
}
	
bool divs() {
    factors.clear();
    if (m <= n) return true;
    factorize();
    if (m > n) return false;
    for(it i = factors.begin(); i != factors.end(); ++i) {
	//printf("%d ^ %d\n", i->first, i->second);
	if (div(n,i->first) < i->second)
	    return false;
    }

    return true;
}
	
int main() {
    sieve(SZ);
    while (scanf("%d %d", &n, &m) != EOF ) {
	int m2(m);
	if (divs())
	    printf("%d divides %d!\n", m2, n);
	else
	    printf("%d does not divide %d!\n", m2, n);
    }
    return 0;
}
