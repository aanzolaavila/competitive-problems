#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int calc(int x) {
    if (1 <= x && x <= 5) return x;

    int c = ceil( log((double)x/5 +1) / log((double)2) ) -1;

    x -= 5*((1 << c) -1);

    return ceil( (double)x / (double)(1 << c) );
}

int main() {
  int n;
  scanf("%d", &n);

  char s[10];
  
  switch(calc(n)) {
  case 1:
    strcpy(s, "Sheldon");
    break;
  case 2:
    strcpy(s, "Leonard");
    break;
  case 3:
    strcpy(s, "Penny");
    break;
  case 4:
    strcpy(s, "Rajesh");
    break;
  case 5:
    strcpy(s, "Howard");
    break;
  }

  printf("%s\n", s);

  return 0;
}
