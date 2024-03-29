#include <algorithm>
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

using namespace std;

int main() {
  vector<int> v;

  int n;
  while (scanf("%d", &n) != EOF) {
    v.PB(n);

    int sz = v.size();

#ifdef DEBUG
    dprintf("v: ");
    for (auto &a : v) {
      dprintf("%d ", a);
    }
    dprintf("\n");
#endif

    if (sz % 2 == 0) {
      int p = sz >> 1;
      int a, b;
      nth_element(v.begin(), v.begin() + p - 1, v.end());
      a = v[p - 1];
      dprintf("ptra: %d\n", a);
      nth_element(v.begin(), v.begin() + p, v.end());
      b = v[p];
      dprintf("ptrb: %d\n", b);
      int val = (a + b) >> 1;
      printf("%d\n", val);
    } else {
      int p = (sz >> 1);
      nth_element(v.begin(), v.begin() + p, v.end());
      dprintf("ptr: %d\n", v[p]);
      printf("%d\n", v[p]);
    }
  }

  return 0;
}
