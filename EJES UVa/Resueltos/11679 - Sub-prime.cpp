#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)

using namespace std;

int *r = NULL;

inline bool all(int b) {
    bool c = true;
    
    for(int i = 0; i < b && c; ++i) {
	c = r[i] >= 0;
    }

    return c;
}

int main() {
    int b, n, i, d, c, a;
    while(scanf("%d%d", &b, &n), b | n) {
	if (r != NULL)
	    delete[] r;
	r = new int[b];

	loop(i, 0, b) {
	    scanf("%d", &r[i]);
	}

	loop(i, 0, n) {
	    scanf("%d%d%d", &d, &c, &a);
	    r[d-1] -= a;
	    r[c-1] += a;
	}

	printf("%s\n", all(b) ? "S" : "N");
    }

    return 0;
}
