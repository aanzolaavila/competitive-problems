#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define SZ 100

using namespace std;

int *ops = NULL;

int main() {
    int i, n, p, x, w;
    char s[SZ];
    scanf("%*d\n");
    while(scanf("%d\n", &n) != EOF) {
	x = i = 0;
	if (ops != NULL)
	    delete[] ops;
	ops = new int[n];

	loop(w, 0, n) {
	    fgets(s, SZ, stdin);

	    if (strstr(s, "LEFT") != NULL) {
		ops[i] = -1;
	    } else if (strstr(s, "RIGHT") != NULL) {
		ops[i] = 1;
	    } else {
		sscanf(s, "%*s%*s%d", &p);
		ops[i] = ops[p-1];
	    }

	    x += ops[i++];
	}

	printf("%d\n", x);
    }

    return 0;
}
