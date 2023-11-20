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

#define SZ 1000010

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank;

public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) {
      p[i] = i;
    }
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }

  void clear() {
    for (int &n : p) {
      n = 0;
    }

    for (int &n : rank) {
      n = 0;
    }
  }

  void print_rank() {
    for (int &v : rank) {
      dprintf("%d, ", v);
    }
    dprintf("\n");
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  UnionFind uf(SZ);

  int n, q;
  scanf("%d%d\n", &n, &q);

  while (q--) {
    char op;
    int i, j;
    scanf("%c %d%d\n", &op, &i, &j);
    dprintf("op: %c i: %d j: %d\n", op, i, j);
    switch (op) {
    case '=':
      uf.unionSet(i, j);
      break;
    case '?':
      printf("%s\n", (uf.isSameSet(i, j)) ? "yes" : "no");
    }
  }

  return 0;
}
