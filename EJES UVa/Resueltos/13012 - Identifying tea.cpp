#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x; it < y; ++it)

using namespace std;

int main() {
    int n, c, i, s;
    while (scanf("%d\n", &n) != EOF) {
	s = 0;
	loop(i, 0, 5) {
	    s += (scanf("%d", &c), c) == n ? 1 : 0;
	}
	printf("%d\n", s);
    }

    return 0;
}
    
