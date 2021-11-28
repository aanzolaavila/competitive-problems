#include <bits/stdc++.h>

using namespace std;

inline int sum(int n) {
  int s = 0;
  while(n) {
    s += (n%10)*(n%10);
    n /= 10;
  }
  return s;
}

set<int> vis;

inline bool happy(int n) {
  vis.clear();
  int a = n;
  
  do {
    vis.insert(a);
    a = sum(a);
  } while(a != 1 && vis.count(a) == 0);

  return a == 1;
}

int main() {

  int t, n, c = 1;
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);
    printf("Case #%d: %d is a%s number.\n", c++, n, happy(n) ? " Happy" : "n Unhappy");
  }

  return 0;
}
