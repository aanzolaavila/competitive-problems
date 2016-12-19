#include <bits/stdc++.h>

#define SZ 100000000

using namespace std;

typedef long long int large;
typedef set<large>::iterator it;

bool notp[SZ];
vector<int> primes;
large Bound;

void sieve(int bound) {
    large i, j;
    Bound = bound +1;
    primes.reserve(Bound);
    memset(notp, 0, sizeof(notp));
    notp[0] = notp[1] = 1;
    for(i = 2; i <= Bound; ++i) {
	if (!notp[i]) {
	    for( j = i*i; j <= Bound; j += i ) notp[j] = 1;
	    primes.push_back((int)i);
	}
    }
}

bool notu[SZ];
set<large> uglys;

void ugly(large bound) {
    large i, j;
    memset(notu, 0, sizeof(notu));
    notu[0] = 1;

    for(i = 3; i < primes.size(); ++i) {
	for( j = primes[i]; j <= bound ; j += primes[i] ) {
	    notu[j] = 1;
	}
    }

    for(i = 0; uglys.size() != bound; ++i) {
	if (!notu[i])
	    uglys.insert(i);
    }
}
    
int main() {

    sieve(1600000);
    ugly((large)1600000);

    it i = uglys.begin();
    advance(i, 15000);

    int k = 0;
    /*for(it j = uglys.begin(); k < uglys.size(); ++j, ++k) {
	printf("%lli ", *j);
	}*/
    
    printf("The 1500'th ugly number is %lli.\n", *i);

    return 0;
}
