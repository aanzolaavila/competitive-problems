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
    fprintf(stderr, __VA_ARGS__);                                              \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 100000

using namespace std;

typedef vector<int> vi;

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {
    int sum = 0;
    for (; b; b -= LSOne(b)) {
      sum += ft[b];
    }

    return sum;
  }

  int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  void adjust(int k, int v) {
    for (; k < ft.size(); k += LSOne(k)) {
      ft[k] += v;
    }
  }
};

int main() {
  int n, k;
  scanf("%d%d\n", &n, &k);
  dprintf("%d %d\n", n, k);

  vi t;
  FenwickTree ft(110000);

  int l = 0;
  int i;
  LOOP(i, 0, n) {
    int v;
    scanf("%d", &v);
    t.PB(v);
    dprintf("%d ", t[i]);
    t[i]++; // ensure t[i] is non-zero
    l = MAX(l, t[i]);
    ft.adjust(t[i], 1);
  }
  dprintf("\n");

  int mx = 0;
  l++;
  LOOP(i, 1, l) {
    int s = ft.rsq(i, i + 999);
    s = int(ceil((float)s / k));
    // dprintf("s: %d\n", s);
    s = MAX(1, s);
    mx = MAX(mx, s);
  }

  printf("%d\n", mx);

  return 0;
}
