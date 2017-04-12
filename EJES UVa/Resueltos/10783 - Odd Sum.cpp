#include <bits/stdc++.h>
#define loop(i, x, y) for(i = x; i < y; ++i)
#define MOD(x, y) ((((x) % (y))+(y))%(y))

using namespace std;

int a, b;

inline int f() {
    int ia = (int)ceil(((double)a-1)*.5);
    int ib = (b-1)/2;

    //printf("<%d %d>\n", ia, ib);
    
    return ib*(ib+2) - (ia*ia - 1);
}

int main() {
    int t, i;
    scanf("%d", &t);
    loop(i, 0, t) {
	scanf("%d%d", &a, &b);
	printf("Case %d: %d\n", i+1, f());
    }

    return 0;
}
