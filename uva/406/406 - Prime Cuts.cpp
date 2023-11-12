#ifdef __APPLE__
#include "../../stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define SZ 1500
#define loop(x, i, f) for (x = i; x < f; ++x)

using namespace std;

typedef long long int lli;
typedef vector<int>::iterator it;

bool notp[SZ];
vector<int> primes;
int n, c;

void sieve(lli sz) {
  primes.clear();
  primes.reserve(sz);
  memset(notp, 0, sizeof(notp));
  notp[0] = notp[1] = 1;
  primes.push_back(1);
  lli i, j;
  loop(i, 2, sz) {
    if (!notp[i]) {
      for (j = i * i; j < sz; j += i)
        notp[j] = 1;
      primes.push_back(i);
    }
  }
}

void print_primes(it &low, it &up) {
  it lim = upper_bound(primes.begin(), primes.end(), n);

  int size = lim - primes.begin();
  int middle = size / 2;
  int e = n % 2 == 0 ? c * 2 : c * 2 - 1;

  int l, u;
  l = middle - e / 2;
  l = l < 0 ? 0 : l;
  u = middle + e / 2;
  u = u > size ? size : u;
  if (n % 2 != 0 and *(lim - 1) != n)
    ++u;

  low = primes.begin() + l;
  up = primes.begin() + u;
}

int main() {
  sieve(1001);
  char in[15] = "";
  bool nline = false;
  it low, up;
  while (fgets(in, sizeof(in), stdin) != NULL) {
    sscanf(in, "%d %d", &n, &c);
    if (nline)
      printf("\n");
    printf("%s:", strtok(in, "\n"));

    print_primes(low, up);
    for (it i = low; i != up; ++i) {
      printf(" %d", *i);
    }

    printf("\n");
    nline = true;
  }

  return 0;
}
