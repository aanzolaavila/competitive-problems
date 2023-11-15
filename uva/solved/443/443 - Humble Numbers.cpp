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

#define SZ 20

typedef long long ll;

const char *getSuff(int n) {
  static const char suffixes[][3] = {"th", "st", "nd", "rd"};
  auto ord = n % 100;
  if (ord / 10 == 1) {
    ord = 0;
  }
  ord = ord % 10;
  if (ord > 3) {
    ord = 0;
  }
  return suffixes[ord];
}

int main() {
  vector<ll> h;

  ll i, j, k, l;
  LOOP(l, 0, SZ) {
    LOOP(k, 0, SZ + 5) {
      LOOP(j, 0, SZ + 10) {
        LOOP(i, 0, SZ + 15) {
          ll n = pow(2ull, i) * pow(3ull, j) * pow(5ull, k) * pow(7ull, l);
          if (0 < n && n <= 2000000000) {
            h.PB(n);
          }
        }
      }
    }
  }

  sort(h.begin(), h.end());

#ifdef DEBUG
  dprintf("size: %d\n", (int)h.size());
  i = 0;
  for (auto &v : h) {
    dprintf("%llu %llu\n", ++i, v);
  }
#endif

  int n;
  while (scanf("%d", &n), n) {
    const char *s = getSuff(n);
    printf("The %d%s humble number is %lld.\n", n, s, h[n - 1]);
  }

  return 0;
}
