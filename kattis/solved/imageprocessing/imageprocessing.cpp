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
    fprintf(stderr, __VA_ARGS__);                                              \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 25

using namespace std;

struct matrix {
  int mat[SZ][SZ];
  int n, m;
};

int main() {
  int h, w, n, m;
  scanf("%d%d%d%d", &h, &w, &n, &m);

  int img[SZ][SZ]; // h * w
  int k[SZ][SZ];   // n * m
  int res[SZ][SZ]; // [h - n + 1][w - m + 1]

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", &img[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &k[i][j]);
    }
  }

#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dprintf("%d ", k[i][j]);
    }
    dprintf("\n");
  }
  dprintf("\n");
#endif

  // flip kernel
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (m >> 1); j++) {
      swap(k[i][j], k[i][m - j - 1]);
    }
  }
  for (int i = 0; i < (n >> 1); i++) {
    for (int j = 0; j < m; j++) {
      swap(k[i][j], k[n - i - 1][j]);
    }
  }

#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dprintf("%d ", k[i][j]);
    }
    dprintf("\n");
  }
#endif

  const int r = h - n + 1;
  const int c = w - m + 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int &v = res[i][j];
      v = 0;

      for (int ki = 0; ki < n; ki++) {
        for (int kj = 0; kj < m; kj++) {
          v += k[ki][kj] * img[i + ki][j + kj];
        }
      }
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d", res[i][j]);
      if (j < c - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
