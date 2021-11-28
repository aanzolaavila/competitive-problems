//#define NDEBUG
#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 2000000
#define N 1000000
#define INF 1000000000
#define MP make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
ll calc(char * ptr) {
    ll sum = 0;

    int l1[3], l2[3];
    memset(l1, 0, sizeof l1);
    memset(l2, 0, sizeof l2);

    int * f = l1;
    int * lf = l2;
    while(*ptr != '\0') {
	int r = (*ptr - '0') % 3;
	f[(r + 0) % 3] = lf[0] +1;
	f[(r + 1) % 3] = lf[1];
	f[(r + 2) % 3] = lf[2];

	sum += f[0];
	swap(f, lf);
	ptr++;
    }

    return sum;
}

char in[SZ];

int main() {

    int i;
    while(fgets(in, SZ, stdin) != NULL) {
	i = 0;
	while(in[i] != '\0') {
	    if (in[i] == '\n') {
		in[i] = '\0';
		break;
	    }

	    if (!INRANGE(in[i], '0', '9')) {
		in[i] = ' ';
	    }
	    i++;
	}

	ll sum = 0;
	char * ptr = strtok(in, " ");
	while(ptr != NULL) {
	    sum += calc(ptr);
	    ptr = strtok(NULL, " ");
	}

	printf("%ld\n", sum);
    }

    return 0;
}
