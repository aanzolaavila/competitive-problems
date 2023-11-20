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

// #define NDEBUG
#ifndef NDEBUG
#define dprintf(...)                                                           \
  do {                                                                         \
    fprintf(stderr, "DEBUG: " __VA_ARGS__);                                    \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 10
#define BSZ 32

using namespace std;

bitset<BSZ> unknown;
bitset<BSZ> bs;

char op[SZ];

void _and(int i, int j) {
  bool r;
  bool unk = true;

  if ((!unknown[i] & bs[i]) && (!unknown[j] & bs[j])) {
    r = 1;
    unk = 0;
  } else if (!unknown[i] && !bs[i]) {
    r = 0;
    unk = 0;
  } else if (!unknown[j] && !bs[j]) {
    r = 0;
    unk = 0;
  }

  bs[i] = r;
  unknown[i] = unk;
}
void _or(int i, int j) {
  bool r;
  bool unk = true;

  if ((!unknown[i] & !bs[i]) && (!unknown[j] & !bs[j])) {
    r = 0;
    unk = 0;
  } else if (!unknown[i] && bs[i]) {
    r = 1;
    unk = 0;
  } else if (!unknown[j] && bs[j]) {
    r = 1;
    unk = 0;
  }

  bs[i] = r;
  unknown[i] = unk;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, i, j;
  while (scanf("%d\n", &n), n) {
    unknown.set(); // all 1s
    bs.reset();
    while (n--) {
      scanf("%s ", op);
      if (strncmp("SET", op, 3) == 0) {
        scanf("%d\n", &i);
        bs[i] = 1;
        unknown[i] = 0;
      } else if (strncmp("CLEAR", op, 5) == 0) {
        scanf("%d\n", &i);
        bs[i] = 0;
        unknown[i] = 0;
      } else if (strncmp("AND", op, 3) == 0) {
        scanf("%d%d\n", &i, &j);
        _and(i, j);
      } else if (strncmp("OR", op, 2) == 0) {
        scanf("%d%d\n", &i, &j);
        _or(i, j);
      }
    }

    for (int i = bs.size() - 1; i >= 0; i--) {
      if (unknown[i]) {
        printf("?");
      } else {
        printf("%c", bs[i] ? '1' : '0');
      }
    }
    printf("\n");
  }

  return 0;
}
