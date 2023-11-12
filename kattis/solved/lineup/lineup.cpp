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

// #define DEBUG
#ifdef DEBUG
#define dprintf(...)                                                           \
  do {                                                                         \
    printf("DEBUG: " __VA_ARGS__);                                             \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 1000

using namespace std;

int main() {
  char buff[SZ];

  int N;
  scanf("%d\n", &N);

  vector<string> names;
  names.reserve(N);

  while (N--) {
    fgets(buff, SZ, stdin);
    int l = strlen(buff);
    if (buff[l - 1] == '\n') {
      buff[l - 1] = '\0';
    }
    dprintf("%s\n", buff);
    names.PB(string(buff));
  }

#ifdef DEBUG
  printf("len(names) = %ld\n", names.size());
#endif

  bool increasing = true;
  bool decreasing = true;

  int i;
  LOOP(i, 0, names.size() - 1) {
    string &a = names[i];
    string &b = names[i + 1];
    if (a < b) {
      decreasing = false;
    } else if (b < a) {
      increasing = false;
    }
  }

  if (increasing) {
    printf("INCREASING\n");
  } else if (decreasing) {
    printf("DECREASING\n");
  } else {
    printf("NEITHER\n");
  }

  return 0;
}
