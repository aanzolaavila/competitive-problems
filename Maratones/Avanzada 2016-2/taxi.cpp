#include <bits/stdc++.h>
#define SZ 110
#define loop(i, ii, ff) for(i = ii; i < ff; ++i)
using namespace std;

int gs[SZ];
int n, i;

int calc() {
  int i = 0, j = n-1;
  int a;
  int c = 0;
  while(i < j) {
    if (gs[j] == 4) {
      ++c;
      --j;
    } else if (gs[j] + gs[i] == 4) {
      ++c;
      --j;
      ++i;
    } else if (gs[i] + gs[j] > 4) {
      ++c;
      --j;
    } else if ((a = gs[i++] + gs[j--]) < 4) {
      if (a <= 4) {
	while(a + gs[i] <= 4){
	  a += gs[i++];
	}
	++c;
      }
    }
  }
  if (i == j) ++c;
  return c;
}

int main() {
  while(scanf("%d", &n), n) {
    loop(i, 0, n) {
      scanf("%d", &gs[i]);
    }

    sort(gs, gs+n);
    printf("%d\n", calc());
  }
  
  return 0;
}
