#include <bits/stdc++.h>
using namespace std;
#define SZ 10000
#define loop(i, ii, ff) for(i = ii; i < ff; ++i)

map<int, int> mem;

int f(int n) {
  if (mem.count(n) != 0) {
    return mem[n];
  } else {
    return mem[n] = (n <= 100 ? f(f(n+11)) : n - 10);
  }
}

int main() {
  int n, i;
  while(scanf("%d", &n), n) {
    printf("f91(%d) = %d\n", n, f(n));
  }

  return 0;
}
