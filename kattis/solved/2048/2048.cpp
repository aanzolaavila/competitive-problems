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

int dirs[][6] = {
    // direction, initial pos, traverse dir
    {1, 0, 0, 0, 0, 1},  // left
    {0, 1, 0, 0, 1, 0},  // up
    {-1, 0, 3, 0, 0, 1}, // right
    {0, -1, 0, 3, 1, 0}, // down
};

int g[4][4];

void reduce_row(int x, int y, int dx, int dy) {
  int u, v;
  LOOP(u, 0, 3) {
    int ux, uy;
    ux = x + u * dx;
    uy = y + u * dy;
    if (!INRANGE(ux, 0, 3) || !INRANGE(uy, 0, 3)) {
      continue;
    }
    dprintf("ux: %d uy: %d", ux, uy);

    int &cur = g[ux][uy];
    dprintf(" cur: %d----\n", cur);

    v = u + 1;
    int vx, vy;
    bool done = false;
    do {
      vx = x + v * dx;
      vy = y + v * dy;
      if (!INRANGE(vx, 0, 3) || !INRANGE(vy, 0, 3)) {
        break;
      }
      dprintf("vx: %d vy: %d", vx, vy);
      v++;

      int &npos = g[vx][vy];
      dprintf(" npos: %d\n", npos);

      if (cur == 0 && npos != 0) {
        cur = npos;
        npos = 0;
      }

    } while (!done && INRANGE(vx, 0, 3) && INRANGE(vy, 0, 3));
  }
}

void mix_row(int x, int y, int dx, int dy) {
  int u, v;
  LOOP(u, 0, 3) {
    int ux, uy;
    ux = x + u * dx;
    uy = y + u * dy;
    if (!INRANGE(ux, 0, 3) || !INRANGE(uy, 0, 3)) {
      continue;
    }
    dprintf("ux: %d uy: %d", ux, uy);

    int &cur = g[ux][uy];
    dprintf(" cur: %d----\n", cur);

    v = u + 1;
    int vx, vy;
    vx = x + v * dx;
    vy = y + v * dy;
    dprintf("vx: %d vy: %d", vx, vy);

    if (INRANGE(vx, 0, 3) && INRANGE(vy, 0, 3)) {
      int &npos = g[vx][vy];
      dprintf(" npos: %d\n", npos);

      if (cur == npos) {
        cur += npos;
        npos = 0;
      }
    }
  }
}

void mix(int x, int y, int dx, int dy, int dirx, int diry) {
  while (INRANGE(x, 0, 3) && INRANGE(y, 0, 3)) {
    mix_row(x, y, dx, dy);
    // traversal
    x += dirx;
    y += diry;
    dprintf("x: %d y: %d\n\n", x, y);
  }
}

void reduce(int x, int y, int dx, int dy, int dirx, int diry) {
  while (INRANGE(x, 0, 3) && INRANGE(y, 0, 3)) {
    reduce_row(x, y, dx, dy);
    // traversal
    x += dirx;
    y += diry;
    dprintf("x: %d y: %d\n\n", x, y);
  }
}

void apply(int op) {
  assert(0 <= op && op < 4);

  const int &dx = dirs[op][0];
  const int &dy = dirs[op][1];
  const int &x0 = dirs[op][2];
  const int &y0 = dirs[op][3];
  const int &dirx = dirs[op][4];
  const int &diry = dirs[op][5];
  dprintf("x0: %d y0: %d\n", x0, y0);
  dprintf("dirx: %d diry: %d\n", dirx, diry);

  reduce(x0, y0, dx, dy, dirx, diry);
  mix(x0, y0, dx, dy, dirx, diry);
  reduce(x0, y0, dx, dy, dirx, diry);
}

int main() {
  int i, j;
  LOOP(j, 0, 4) {
    LOOP(i, 0, 4) { scanf("%d", &g[i][j]); }
  }
  int op;
  scanf("%d", &op);

#ifdef DEBUG
  LOOP(j, 0, 4) {
    LOOP(i, 0, 4) { dprintf("%4d ", g[i][j]); }
    dprintf("\n");
  }
  dprintf("op: %d\n", op);
#endif

  apply(op);

  LOOP(j, 0, 4) {
    LOOP(i, 0, 4) {
      printf("%d", g[i][j]);
      if (i < 3) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
