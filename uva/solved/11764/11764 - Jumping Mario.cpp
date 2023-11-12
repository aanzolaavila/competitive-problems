#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)

using namespace std;

int main() {
    int t, i, j;
    scanf("%d", &t);

    int s, h, l, n, c;
    loop(i, 0, t) {
	scanf("%d", &n);
	h = l = 0;
	
	scanf("%d", &s);
	loop(j, 0, n-1) {
	    scanf("%d", &c);
	    if (c-s > 0) {
		h++;
	    } else if (c-s < 0) {
		l++;
	    }
	    s = c;
	}

	printf("Case %d: %d %d\n", i+1, h, l);
    }

    return 0;
}
