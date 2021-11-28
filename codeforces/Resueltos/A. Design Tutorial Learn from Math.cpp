#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

#define SZ 1000010

using namespace std;

typedef long long int large;

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

pair<int, int> find_pair(const int n) {
    int i = 4, j;
    bool found = false;
    while(!found) {
	if (!binary_search(primes.begin(), primes.end(), j = n-i))
	    found = true;
	else
	    while(binary_search(primes.begin(), primes.end(), ++i));
    }

    return make_pair(i, j);
}

int main() {
    int n;
    scanf("%d", &n);

    sieve(n);

    pair<int, int> p = find_pair(n);

    printf("%d %d\n", p.first, p.second);

    return 0;
}
