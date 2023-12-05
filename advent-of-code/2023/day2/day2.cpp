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

#define SZ 10000

using namespace std;

char buff[SZ];

bool calc(char *ptr) {
  int c;
  int read;
  char bag[10];

  struct {
    int red;
    int green;
    int blue;
  } cubes;
  memset(&cubes, 0, sizeof(cubes));

  while (*ptr != '\0') {
    sscanf(ptr, "%d %[^,;]%n", &c, bag, &read);
    ptr += read;
    dprintf("%d %s\n", c, bag);

    if (strcmp("red", bag) == 0) {
      cubes.red += c;
    } else if (strcmp("green", bag) == 0) {
      cubes.green += c;
    } else {
      assert(strcmp("blue", bag) == 0);
      cubes.blue += c;
    }

    if (cubes.red > 12) {
      return false;
    }
    if (cubes.green > 13) {
      return false;
    }
    if (cubes.blue > 14) {
      return false;
    }

    if (*ptr++ == ';') {
      memset(&cubes, 0, sizeof(cubes));
      dprintf("reset\n");
    }
  }

  return true;
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

    int game;
    int n;
    sscanf(buff, "Game %d: %n\n", &game, &n);

    dprintf("%s\n", buff + n);

    if (calc(buff + n)) {
      s += game;
    }
  }

  printf("%d\n", s);

  return 0;
}
