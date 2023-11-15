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
    fprintf(stderr, "DEBUG: " __VA_ARGS__);                                    \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 100

using namespace std;

int main() {
  char buff[SZ];

  while (fgets(buff, SZ, stdin), strncmp(buff, "#", 1) != 0) {
    dprintf("buff: %s\n", buff);
    int len = strlen(buff);
    if (buff[len - 1] == '\n') {
      buff[--len] = '\0';
    }

    bool suc = next_permutation(buff, buff + len);
    if (suc) {
      printf("%s\n", buff);
    } else {
      printf("No Successor\n");
    }
  }

  return 0;
}
