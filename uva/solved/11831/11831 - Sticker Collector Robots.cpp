#include <cstdio>
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

#define SZ 110

using namespace std;

void turn_right(int &x, int &y) {
  swap(x, y);
  y = -y;
}

void turn_left(int &x, int &y) {
  swap(x, y);
  x = -x;
}

char g[SZ][SZ];

void print_grid(int x, int y, int n, int m) {
  int i, j;
  LOOP(i, 0, n) {
    LOOP(j, 0, m) {
      if (x == j && y == i) {
        dprintf("o");
      } else {
        dprintf("%c", g[j][i]);
      }
    }
    dprintf("\n");
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, s;
  while (scanf("%d%d%d\n", &n, &m, &s), n | m | s) {
    dprintf("n: %d m: %d s: %d\n", n, m, s);
    int x, y;
    int dx, dy;
    int i, j;
    LOOP(i, 0, n) {
      LOOP(j, 0, m) {
        char &c = g[j][i];
        scanf("%c", &c);
        switch (c) {
        case '.':
        case '*':
        case '#':
          break;
        default:
          x = j, y = i; // found start point
        }

        switch (c) {
        case 'N':
          dx = 0, dy = -1;
          break;
        case 'S':
          dx = 0, dy = 1;
          break;
        case 'L':
          dx = 1, dy = 0;
          break;
        case 'O':
          dx = -1, dy = 0;
          break;
        }
      }
      scanf("\n");
    }

    dprintf("x: %d y: %d, dx: %d dy: %d\n", x, y, dx, dy);

#ifdef DEBUG
    print_grid(x, y, n, m);
#endif

    int score = 0;
    char op;
    while (s--) {
      scanf("%c", &op);

      switch (op) {
      case 'D':
        turn_left(dx, dy);
        break;
      case 'E':
        turn_right(dx, dy);
        break;
      case 'F':
        int nx, ny;
        nx = x + dx;
        ny = y + dy;
        if (INRANGE(nx, 0, m - 1) && INRANGE(ny, 0, n - 1)) {
          char &c = g[nx][ny];
          if (c != '#') {
            x = nx;
            y = ny;
            if (c == '*') {
              score++;
              c = '.';
            }
          }
        }
      }

#ifdef DEBUG
      dprintf("\nop: %c - score: %d\n", op, score);
      print_grid(x, y, n, m);
#endif
    }
    scanf("\n");

    printf("%d\n", score);
  }

  return 0;
}
