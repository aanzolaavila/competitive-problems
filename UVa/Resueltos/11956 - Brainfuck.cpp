#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 150000
#define N 100
#define INF 1000000000

using namespace std;

int main() {
    char s[SZ];
    unsigned char st[N];
    int t;
    scanf("%d\n", &t);

    int ptr;
    int len;
    int i, j;
    loop(j, 0, t) {
	memset(st, 0, sizeof(st));
	fgets(s, SZ, stdin);
	ptr = 0;
	len = strlen(s)-1;

	loop(i, 0, len) {
	    switch(s[i]) {
	    case '<':
		DEC(ptr, N);
		break;
	    case '>':
		INC(ptr, N);
		break;
	    case '+':
		st[ptr]++;
		break;
	    case '-':
		st[ptr]--;
		break;
	    }
	}

	printf("Case %d:", j+1);
	loop(i, 0, N) {
	    printf(" %.2X", st[i]);
	}
	printf("\n");
    }

    return 0;
}
