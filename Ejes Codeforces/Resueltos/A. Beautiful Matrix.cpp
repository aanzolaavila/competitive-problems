#include <cstdio>

#define LIM 5

using namespace std;

inline int abs(int i) {
  return i >= 0 ? i : -i;
}

int main() {
  int s = 0, i, j;
  for(i = 0; i < LIM && !s; ++i) {
    for(j = 0; j < LIM && !s; ++j) {
      scanf("%d", &s);
    }
  }

  printf("%d", abs(3-i) + abs(3-j));

  return 0;
}
