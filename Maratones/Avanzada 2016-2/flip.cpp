#include <bits/stdc++.h>
#define SZ 10010
#define loop(i, ii, ff) for(i = ii; i < ff; ++i)
using namespace std;

int l[SZ];

int main() {
  int n, i;
  while(scanf("%d", &n), n) {
    loop(i, 0, n) {
      scanf("%d", l+i);
    }
    sort(l, l+n);

    loop(i, 0, n){
      if (i != 0) printf(" ");
      printf("%d", l[i]);
    }
    
    printf("\n");
  }
  return 0;
}
