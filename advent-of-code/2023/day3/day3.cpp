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

typedef unsigned long long ull;
typedef unsigned int uint;

typedef pair<int, int> ii;

char buff[SZ];
int len;
set<ii> symbols;
map<ii, int> numpos;
vector<int> numbers;

void proc_line() {
  static int row = 0;
  auto ptr = buff;

  while (*ptr != '\0') {
    if (INRANGE(*ptr, '0', '9')) {
      char c;
      int n = 0;
      int digits = 0;

      ii pos = MP(row, len - (buff - ptr));

      while ((c = *ptr++) != '\0' && INRANGE(c, '0', '9')) {
        n *= 10;
        n += c - '0';
        digits++;
      }
      ptr--;

      numbers.PB(n);

      dprintf("n: %d, digits: %d, row: %d, x: %d, y: %d\n", n, digits, row,
              pos.S, pos.F);

      while (digits--) {
        numpos[pos] = numbers.size() - 1;
        pos.S++;
      }
    }

    if (*ptr != '.' && *ptr != '\0') {
      ii pos = MP(row, len - (buff - ptr));
      symbols.insert(pos);
    }

    ptr++;
  }

  row++;
}

int dirs[][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                 {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

ull get_answer() {
  ull s = 0;

  set<int> processed;

  for (auto &sym : symbols) {
    int x, y;
    x = sym.F;
    y = sym.S;
    dprintf("sym: (%d, %d)\n", x, y);

    int i;
    LOOP(i, 0, 8) {
      int dx = dirs[i][0];
      int dy = dirs[i][1];

      ii pos = MP(x + dx, y + dy);
      dprintf("test: (%d, %d)\n", pos.F, pos.S);
      if (numpos.count(pos) > 0) {
        int idx = numpos[pos];
        assert(idx < numbers.size());
        if (processed.count(idx) == 0) {
          int &n = numbers[idx];
          processed.insert(idx);
          s += n;
        }
      }
    }
  }

  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (fgets(buff, SZ, stdin) != NULL) {
    len = strlen(buff);
    if (buff[len - 1] == '\n') {
      buff[--len] = '\0';
    }
    dprintf("%s\n", buff);
    proc_line();
  }

  dprintf("numbers: %lu\n", numbers.size());
#ifndef NDEBUG
  dprintf("[");
  for (auto &pos : numpos) {
    dprintf("\t(%d, %d) %d, \n", pos.F.F, pos.F.S, pos.S);
  }
  dprintf("]\n");
#endif

  printf("%llu\n", get_answer());

  return 0;
}
