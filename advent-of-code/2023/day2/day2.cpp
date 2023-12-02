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

const char *numbers[] = {
    "zero", "one", "two",   "three", "four",
    "five", "six", "seven", "eight", "nine",
};

int get_number(const char *ptr) {
  char c = *ptr;
  if (INRANGE(c, '0', '9')) {
    return c - '0';
  }

  for (int i = 1; i < 10; i++) {
    // dprintf("numbers[%d] = %s\n", i, numbers[i]);
    if (strncmp(ptr, numbers[i], strlen(numbers[i])) == 0) {
      return i;
    }
  }

  return -1;
}

int proc() {
  auto ptr = buff;
  int a, b;
  a = b = -1;

  while (*ptr != '\0') {
    int n = get_number(ptr++);
    if (n > 0) {
      if (a < 0) {
        a = n;
      }
      b = n;
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
