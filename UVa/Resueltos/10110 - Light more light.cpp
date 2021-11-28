#include <bits/stdc++.h>
#define SZ 10000000
#define ABS(x) ((x) >= 0 ? (x) : -(x))

using namespace std;

typedef long long large;
typedef unsigned int uint;

vector<large> primes;
bool notp[SZ];

void sieve(large bound) {
    primes.clear();
    memset(notp, 0, sizeof notp);
    large i, j;
    notp[0] = notp[1] = 1;
    for(i = 2; i < bound; i++) {
	if (!notp[i]) {
	    primes.push_back(i);
	    for(j = i*i; j < bound; j += i) notp[j] = 1;
	}
    }
}

inline large gcd(large a, large b) {
    large x;
    while(b > 0) {
	x = a;
	a = b;
	b = x % a;
    }

    return a;
}

inline large mcm(large a, large b) {
    return ABS(a*b) / gcd(a, b);
}

typedef vector<large>::iterator it;

bool calc(uint n) {
    // it a = upper_bound(primes.begin(), primes.end(); n) -1;
    // printf("%u ", n);
    if (n == 1) return true;
    it a = primes.begin();
    vector<large> e;
    while(n > 1 && *a <= n && a != primes.end()) {
	if (n % *a == 0) {
	    int c = 0;
	    while(n % *a == 0) {
		n /= *a;
		c++;
	    }
	    e.push_back(c);
	}
	a++;
    }

    if (e.size() == 0) return false;
    if (n > 1) e.push_back(1);
    
    int d = 1;
    for(int i = 0; i < e.size(); i++) {
	d *= (e[i]+1);
    }

    // printf("%d ", d);
    
    return d % 2 != 0;
}

int main() {
    sieve((large)(1<<16));
    
    int n;
    while(scanf("%d", &n), n != 0) {
	printf("%s\n", calc(n) ? "yes" : "no");
    }
    
    return 0;
}
