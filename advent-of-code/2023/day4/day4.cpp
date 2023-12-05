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
    fprintf(stderr, __VA_ARGS__);                                              \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 10000

using namespace std;

char buff[SZ];

vector<int> get_numbers(char *ptr) {
  int v, n;
  vector<int> nums;
  while (sscanf(ptr, "%d%n", &v, &n) != EOF) {
    nums.PB(v);
    ptr += n;
  }

  return nums;
}

int calc(char *ptr) {
  vector<int> win;
  vector<int> curr;

  char *tk = strtok(ptr, "|");
  assert(tk != NULL);

  win = get_numbers(tk);
  tk = strtok(NULL, "|");
  curr = get_numbers(tk);

  sort(win.begin(), win.end());
  sort(curr.begin(), curr.end());

  vector<int> intersect;
  set_intersection(win.begin(), win.end(), curr.begin(), curr.end(),
                   back_inserter(intersect));

  dprintf("intersect: %lu\n", intersect.size());
  for (auto &n : intersect) {
    dprintf("%d, ", n);
  }
  dprintf("\n");

  return 1 << (intersect.size() - 1);
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

    auto ptr = buff;

    int n;
    sscanf(ptr, "Card %*d: %n", &n);
    ptr += n;

    s += calc(ptr);
  }

  printf("%d\n", s);

  return 0;
}
