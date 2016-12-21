#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

inline int mile(int t) {
    return ( floor( (double)t / 30.0 ) +1) * 10;
}

inline int juice(int t) {
    return ( floor( (double)t / 60.0 ) +1) * 15;
}

int main() {
    int i, k, t, m, j, n, d;
    scanf("%d", &t);

    loop(i, 0, t) {
	m = j = 0;
	scanf("%d", &n);
	loop(k, 0, n) {
	    scanf("%d", &d);
	    m += mile(d);
	    j += juice(d);
	}
	
	printf("Case %d: ", i+1);
	if (m == MIN(m, j)) {
	    printf("Mile ");
	}
	if (j == MIN(m, j)) {
	    printf("Juice ");
	}
	printf("%d\n", MIN(m , j));
    }

    return 0;
}
