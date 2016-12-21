#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define SZ 90
#define INF 1000000000

using namespace std;

int n, p;
int i, j, r;
float d, bd;
char prop[SZ];
int br;
char temp[SZ];

inline void ch() {
    strcpy(prop, temp);
    bd = d;
    br = r;
}

int main() {
    int c = 1;
    while(scanf("%d%d\n", &n, &p), n|p) {
	if (c > 1)
	    printf("\n");
	
	br = -INF;
	bd = INF;
	loop(i, 0, n) {
	    fgets(temp, SZ, stdin);
	}

	loop(i, 0, p) {
	    fgets(temp, SZ, stdin);
	    scanf("%f%d\n", &d, &r);
	    if (r > br) {
		ch();
	    } else if (r == br && d < bd) {
		ch();
	    }

	    loop(j, 0, r) {
		fgets(temp, SZ, stdin);
	    }
	}

	printf("RFP #%d\n", c++);
	printf("%s", prop);
    }

    return 0;
}
