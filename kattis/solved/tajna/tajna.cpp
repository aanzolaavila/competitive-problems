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

#define SZ 200

using namespace std;

typedef long long ll;

int main() {
  char buff[SZ];
  fgets(buff, SZ, stdin);
  int len = strlen(buff);
  if (buff[len - 1] == '\n') {
    buff[--len] = '\0';
  }

  dprintf("s: %s\n", buff);

  int r = 1, c = len;

  for (int i = 2; i < len; i++) {
    if (len % i == 0 && i <= (len / i)) {
      r = i;
      c = len / i;
      assert(len == c * i);
    }
  }

  swap(r, c);

  dprintf("r: %d c: %d\n", r, c);

  char ans[SZ][SZ];

  int pos = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      ans[i][j] = buff[pos++];
    }
  }
  assert(pos == len);

  char res[SZ];
  pos = 0;
  for (int j = 0; j < c; j++) {
    for (int i = 0; i < r; i++) {
      res[pos++] = ans[i][j];
    }
  }
  assert(pos == len);
  res[pos] = '\0';

  dprintf("pos: %d\n", pos);

  printf("%s\n", res);

  return 0;
}
