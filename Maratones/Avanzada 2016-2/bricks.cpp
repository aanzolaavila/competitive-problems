#include <bits/stdc++.h>
using namespace std;
#define SZ 10000
#define loop(i, ii, ff) for(i = ii; i < ff; ++i)
#define INF 1000000000

map<int, int> mem;

int f(int n) {
  if (mem.count(n) != 0)
    return mem[n];
  else {
    if (0 <= n && n <= 2)
      return (mem[n] = 1);
    return (mem[n] = f(n-1) + f(n-3));
  }
}

int main() {
  int n;
  while(scanf("%d", &n), n != -1) {
    printf("%d\n", f(n));
  }

  return 0;
}
