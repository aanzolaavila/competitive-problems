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
    fprintf(stderr, __VA_ARGS__);                                              \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 15000

using namespace std;

typedef vector<pair<char *, int>> vs;
typedef map<string, vs> msv;

set<string> ignoreSet;
msv idx;

void add_to_index(char *s, int len) {
  for (auto c = s; *c; c++) {
    *c = tolower(*c);
  }
  dprintf("add_to_index: %s\n", s);

  char *cpbuff = (char *)malloc(len + 50);
  strcpy(cpbuff, s);

  char *ptr = strtok(s, " ");
  while (ptr != NULL) {
    auto w = string(ptr);
    if (ignoreSet.count(w) == 0) {
      int i = ptr - s;
      idx[w].PB(MP(cpbuff, i));
    }

    ptr = strtok(NULL, " ");
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char buff[SZ];
  int len;
  while (fgets(buff, SZ, stdin), strncmp("::", buff, 2) != 0) {
    len = strlen(buff);
    if (buff[len - 1] == '\n') {
      buff[--len] = 0;
    }
    ignoreSet.insert(string(buff));
  }

  dprintf("ignoreset: %d\n", (int)ignoreSet.size());

  while (fgets(buff, SZ, stdin) != NULL) {
    len = strlen(buff);
    if (buff[len - 1] == '\n') {
      buff[--len] = 0;
    }
    dprintf("IN: %s\n", buff);
    add_to_index(buff, len);
  }

  for (auto it = idx.begin(); it != idx.end(); ++it) {
    auto v = it->S;
    for (auto &p : v) {
      char *s = p.F;
      int i = p.S;
      for (auto ptr = s + i; *ptr != ' ' && *ptr != '\0'; ptr++) {
        *ptr = toupper(*ptr);
      }

      printf("%s\n", s);

      for (auto ptr = s + i; *ptr != ' ' && *ptr != '\0'; ptr++) {
        *ptr = tolower(*ptr);
      }
    }
  }

  return 0;
}
