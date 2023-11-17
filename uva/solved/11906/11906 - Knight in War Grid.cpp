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

#define DEBUG
#ifdef DEBUG
#define dprintf(...)                                                           \
  do {                                                                         \
    fprintf(stderr, "DEBUG: " __VA_ARGS__);                                    \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 110

using namespace std;

typedef struct vertex {
  bool p;   // prohibited
  bool vis; // visited
} vertex;

vertex gs[SZ][SZ];

int r, c, m, n;

int even, odd;

bool is_jumpable(int x, int y) {
  return INRANGE(x, 0, r - 1) && INRANGE(y, 0, c - 1);
}

bool is_visitable(int x, int y) { return gs[x][y].p == 0; }

void solve() {
  even = odd = 0;

  stack<pair<int, int>> s;
  s.push(MP(0, 0));
  while (!s.empty()) {
    auto u = s.top();
    s.pop();

    int x, y;
    x = u.F;
    y = u.S;

    auto &uv = gs[x][y];
    if (uv.vis == 1) {
      continue;
    }

    uv.vis = 1;

    set<pair<int, int>> unique;

    int k = 0;
    int perm = 0;
    LOOP(perm, 0, 4) {
      int sx = perm & 2 ? -1 : 1;
      int sy = perm & 1 ? -1 : 1;

      int nx, ny;
      nx = x + sx * n;
      ny = y + sy * m;
      if (unique.count(MP(nx, ny)) > 0) {
        continue;
      }

      if (is_jumpable(nx, ny) && is_visitable(nx, ny)) {
        k++;
        s.push(MP(nx, ny));
        unique.insert(MP(nx, ny));
      }
    }

    // inverted
    LOOP(perm, 0, 4) {
      int sx = perm & 2 ? -1 : 1;
      int sy = perm & 1 ? -1 : 1;

      int nx, ny;
      nx = x + sx * m;
      ny = y + sy * n;
      if (unique.count(MP(nx, ny)) > 0) {
        continue;
      }

      if (is_jumpable(nx, ny) && is_visitable(nx, ny)) {
        k++;
        s.push(MP(nx, ny));
        unique.insert(MP(nx, ny));
      }
    }

    if (k % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  scanf("%d", &t);

  int cn;
  LOOP(cn, 0, t) {
    memset(gs, 0, sizeof gs);
    scanf("%d%d%d%d", &r, &c, &m, &n);

    int w;
    scanf("%d", &w);

    while (w--) {
      int x, y;
      scanf("%d%d", &x, &y);
      gs[x][y].p = true;
    }

    solve();

    printf("Case %d: %d %d\n", cn + 1, even, odd);
  }

  return 0;
}
