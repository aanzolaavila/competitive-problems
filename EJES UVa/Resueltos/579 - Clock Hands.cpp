#include <cstdio>
#include <cmath>

#define PI 3.14159265

using namespace std;

inline double angle(int h, int m) {
  return (PI/180.0)*(h*30.0-(11.0/2.0)*m);
}

inline double inverse(double angle) {
  return (180.0/PI)*angle;
}

int main() {
  int h, m;
  while(scanf("%d:%d", &h, &m), h != 0 || m != 0) {
    printf("%.3f\n", inverse(acos(cos(angle(h, m)))));
  }
  return 0;
}
