#include <cstring>
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

#define SZ 10000

using namespace std;

// ### ### ### ### ### ### ### ### ### ###
// ***   * *** *** * * *** *** *** *** ***
// * *   *   *   * * * *   *     * * * * *
// * *   * *** *** *** *** ***   * *** ***
// * *   * *     *   *   * * *   * * *   *
// ***   * *** ***   * *** ***   * *** ***

char nums[][16] = {"***"
                   "* *"
                   "* *"
                   "* *"
                   "***",

                   "  *"
                   "  *"
                   "  *"
                   "  *"
                   "  *",

                   "***"
                   "  *"
                   "***"
                   "*  "
                   "***",

                   "***"
                   "  *"
                   "***"
                   "  *"
                   "***",

                   "* *"
                   "* *"
                   "***"
                   "  *"
                   "  *",

                   "***"
                   "*  "
                   "***"
                   "  *"
                   "***",

                   "***"
                   "*  "
                   "***"
                   "* *"
                   "***",

                   "***"
                   "  *"
                   "  *"
                   "  *"
                   "  *",

                   "***"
                   "* *"
                   "***"
                   "* *"
                   "***",

                   "***"
                   "* *"
                   "***"
                   "  *"
                   "***"};

int match(char dis[5][SZ], int offset) {
  int pos = 0;

  while (pos < 10) {
    int i;
    bool found = true;
    LOOP(i, 0, 5) {
      dprintf("pos: %d - i: %d - o: %d - %.3s \n", pos, i, offset,
              dis[i] + offset);

      if (strncmp(dis[i] + offset, nums[pos] + (i * 3), 3) != 0) {
        dprintf("match: '%.3s' ? '%.3s'\n", dis[i] + offset,
                nums[pos] + (i * 3));
        pos++;
        found = false;
        break;
      }
    }

    if (found) {
      dprintf("match pos: %d\n", pos);
      return pos;
    }
  }

  dprintf("match pos: %d\n", 0);
  return 0;
}

int main() {
  char dis[5][SZ];
  int len = 0;
  int i;
  LOOP(i, 0, 5) {
    fgets(dis[i], SZ, stdin);
    int l = strlen(dis[i]);
    if (dis[i][l - 1] == '\n') {
      dis[i][--l] = '\0';
    }
    len = MAX(len, l);
    dprintf("'%s'\n", dis[i]);
  }

  // fill grid with spaces
  LOOP(i, 0, 5) {
    int j;
    LOOP(j, 0, len) {
      char &c = dis[i][j];
      if (c != '*') {
        c = ' ';
      }
    }
    dis[i][len] = '\0';
  }

#ifdef DEBUG
  dprintf("\n");
  LOOP(i, 0, 5) { dprintf("'%s'\n", dis[i]); }
#endif

  char num[SZ];
  memset(num, 0, sizeof num);

  int p = 0;
  for (int i = 0; i < len; i += 4) {
    int n = match(dis, i);
    // dprintf("nc: %d\n", n);
    char c = '0' + n;
    num[p++] = c;
  }

  dprintf("n: %s\n", num);

  int ans = atoi(num);
  if (ans % 6 == 0) {
    printf("BEER!!\n");
  } else {
    printf("BOOM!!\n");
  }

  return 0;
}
