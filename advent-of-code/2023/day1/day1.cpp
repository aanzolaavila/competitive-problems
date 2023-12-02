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

#define NDEBUG
#ifndef NDEBUG
#define dprintf(...)                                                           \
  do {                                                                         \
    fprintf(stderr, "DEBUG: " __VA_ARGS__);                                    \
  } while (0);
#else
#define dprintf(...) /**/
#endif

using namespace std;

#define SZ 10000

char buff[SZ];

int proc() {
  auto ptr = buff;
  int a, b;
  a = b = -1;

  char c;
  while ((c = *ptr++) != '\0') {
    if (INRANGE(c, '0', '9')) {
      if (a < 0) {
        a = c - '0';
      }

      b = c - '0';
    }
  }

  assert(a > 0);
  assert(b > 0);

  return a * 10 + b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int s = 0;

  while (fgets(buff, SZ, stdin) != NULL) {
    int l = strlen(buff);
    if (buff[l - 1] == '\n') {
      buff[--l] = '\0';
    }

    int r = proc();
    dprintf("%d\n", r);
    s += r;
  }

  printf("%d\n", s);

  return 0;
}
