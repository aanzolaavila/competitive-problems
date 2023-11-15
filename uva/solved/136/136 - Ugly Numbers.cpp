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

#define DEBUG
#ifdef DEBUG
#define dprintf(...)                                                           \
  do {                                                                         \
    fprintf(stderr, "DEBUG: " __VA_ARGS__);                                    \
  } while (0);
#else
#define dprintf(...) /**/
#endif

#define SZ 1000000000

using namespace std;

typedef long long ll;

int main() {
  // vector<ll> ugly;
  //
  // for (int k = 0; k < 64; k++) {
  //   for (int j = 0; j < 64; j++) {
  //     for (int i = 0; i < 64; i++) {
  //       ll n = pow(2l, i) * pow(3l, j) * pow(5l, k);
  //       ugly.PB(n);
  //     }
  //   }
  // }
  //
  // sort(ugly.begin(), ugly.end());
  //
  // printf("The 1500'th ugly number is %lld.\n", ugly[1499]);
  printf("The 1500'th ugly number is 859963392.\n");

  return 0;
}
