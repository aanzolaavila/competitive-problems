#include <cstdio>

using namespace std;

bool lucky_number(int n) {
  if (n == 0) return false;
  int i;
  while(n) {
    if ((i = n % 10) != 4 && i != 7)
      return false;
    n /= 10;
  }

  return true;
}

int main() {
  char n[20];

  scanf("%s", n);

  int c = 0;
  
  for(int i = 0; n[i] != '\0' ; ++i) {
    if(n[i] == '4' || n[i] == '7')
      ++c;
  }

  printf("%s", lucky_number(c) ? "YES\n" : "NO\n");

  return 0;
}
