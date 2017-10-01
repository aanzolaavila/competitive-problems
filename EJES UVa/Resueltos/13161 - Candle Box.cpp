#include <bits/stdc++.h>
#define loop(i, a, b) for(i = a; i < b ; i++)


using namespace std;

int d, R, T;

inline int calc() {
    int r = ( 2.0*d-2.0 + sqrt( (2-2*d)*(2-2*d) - 8.0*(-d+d*d-2.0*(R+T)-18.0) ) ) / 4.0;

    if (2*(R+T) == 2*r*r + 2*(1-d)*r + d*d -d -18) {
	return R - r*(r+1)/2 + 6;
    }

    r = ( 2.0*d-2.0 - sqrt( (2-2*d)*(2-2*d) - 8.0*(-d+d*d-2.0*(R+T)-18.0) ) ) / 4.0;
    return R - r*(r+1)/2 + 6;
}

int main() {
    while(scanf("%d%d%d", &d, &R, &T) != EOF) {
	printf("%d\n", calc());
    }

    return 0;
}
