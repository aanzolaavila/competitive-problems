#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#define VEC vector<string>
      
using namespace std;

typedef long long int ll;

inline bool cumple(ll a, ll b, ll n) {
  return (a+b)*(a+b) == a*pow(10, n) + b;
}

string convert(ll a, ll b, ll n) {
  string f(to_string(a));
  string l(to_string(b));

  while(n - f.length() != 0)
    f = string("0") + f;

  while(n - l.length() != 0)
    l = string("0") + l;

  return f+l;
}  

void calc(VEC &v, int n) {
  v.resize(0);
  ll lim = pow(10, n);
  for(ll a = 0 ; a < lim; ++a) {
    ll sq = 4*a*(1+lim)+1;
    if (sq < 0) continue;

    sq = sqrt(sq);
    ll b = (1-2*a - sq)/2;
    if (b >= 0 && cumple(a, b, n)) v.push_back(convert(a, b, n));
    b = (1-2*a + sq)/2;
    if (b >= 0 && cumple(a, b, n)) v.push_back(convert(a, b, n));
  }
}

int main() {
  int n;
  VEC v((1 << 9));
  string salida("");

  while( scanf("%d", &n) != EOF ) {
    calc(v, n/2);
    for(auto &e : v)
      salida += e + string("\n");
  }

  printf("%s", salida.c_str());
  
  return 0;
}
