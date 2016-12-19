#include <cstdio>
#include <string>

using namespace std;

typedef unsigned long long int ll;

inline bool is_palindrome(const string &n) {
  int l = n.length()-1;
  for(int i = 0; i < (l >> 1)+1 ; ++i) {
    if(n[i] != n[l-i])
      return false;
  }
  return true;
}

inline ll inverse(ll n) {
  if (0 <= n && n <= 9)
    return n;
  ll r = 0;
  while(n) {
    r = r*10 + n % 10;
    n /= 10;
  }
  return r;
}

int main() {
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i) {
    ll p;
    int c = 0;
    scanf("%lli", &p);
    do {
      p += inverse(p);
      ++c;
    }while(!is_palindrome(to_string(p)));

    printf("%d %lli\n", c, p);
  }

  return 0;
}
