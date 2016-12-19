#include <bits/stdc++.h>
//#define abs(x) ((x) < 0? -(x) : (x))
#define mod(x, y) ( (x) > 0 ? (x)%(y) : ( ((y)+(x))%(y) ) )
using namespace std;

int i, f, s, t;

inline int abso(const int &x) {
    return x >= 0 ? x : -x;
}

inline int calc() {
    int ans = 120;
    ans += f <= i ? abso(f-i) : 40 - abso(f-i);
    ans += s >= f ? abso(s-f) : 40 - abso(s-f);
    ans += t <= s ? abso(t-s) : 40 - abso(t-s);
    
    return ans*9;
}

int main() {
  while(scanf("%d %d %d %d", &i, &f, &s, &t), i|f|s|t) {
    printf("%d\n", calc());
  }

  return 0;
}
