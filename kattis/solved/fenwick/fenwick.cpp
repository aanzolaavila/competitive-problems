#ifdef __APPLE__
#include "../../stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 100000000
// or use numeric_limits<type>::max()
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n)-1) % (n))
#define INC(v, n) (v = ((v) + 1) % (n))
#define LOOP(i, ii, ff) for (i = (ii); i < (ff); i++)
#define LSOne(i) ((i) & -(i))

// #define DEBUG
#ifdef DEBUG
#define dprintf(...)                                                           \
  do {                                                                         \
    fprintf(stderr, "DEBUG: " __VA_ARGS__);                                    \
  } while (0);
#else
#define dprintf(...) /**/
#endif

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  ll rsq(int j) {
    ll s = 0;
    for (; j; j -= LSOne(j)) {
      s += ft[j];
    }
    return s;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

  void update(int i, ll v) {
    for (; i < ft.size(); i += LSOne(i)) {
      ft[i] += v;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  scanf("%d%d\n", &n, &q);

  FenwickTree ft(n);
  while (q--) {
    char op;
    int k;
    ll v;
    scanf("%c", &op);
    dprintf("op: %c\n", op);

    switch (op) {
    case '?':
      scanf("%d\n", &k);
      dprintf("%d\n", k);
      v = ft.rsq(k);
      printf("%lld\n", v);
      break;
    case '+':
      scanf("%d%lld\n", &k, &v);
      dprintf("%d %d\n", k, v);
      ft.update(k + 1, v);
      break;
    }
  }

  return 0;
}
