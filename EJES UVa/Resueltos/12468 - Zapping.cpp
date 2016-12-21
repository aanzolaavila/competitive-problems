#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))

using namespace std;

const double pi = acos(-1.0);
const double r = 50.0/pi;

inline int dist(double a, double b) {
    double theta = acos(cos(ABS(a/r - b/r)));
    return (int)((theta * r) + 0.5);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b), a != -1 && b != -1) {
	printf("%d\n", dist(a, b));
    }

    return 0;
}
