#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 20000000
#define N 101
#define INF 1000000000

char in[SZ];
char out[SZ];
char * pout;
int nums[N];

int cread(char * p, int &n) {
    n = 0;
    int r = 0;
    while(! INRANGE(*p, '0', '9')) ++p, ++r;
    
    while(INRANGE(*p, '0', '9')) {
	n *= 10;
	n += *p - '0';
	++p;
	++r;
    }

    return r;
}

void cprint(const char *s) {
    while(*s != '\0') {
	*pout++ = *s++;
    }
    *pout = '\0';
}

int main() {
    int n, i, j, r, max;
    char * p;
    char tmp[512];
    while(scanf("%d\n", &n), n) {
	fgets(in, SZ, stdin);
	out[0] = '\0';
	pout = out;
	memset(nums, 0, sizeof(nums));

	p = in;
	max = -1;
	loop(i, 0, n) {
	    r = cread(p, j);
	    nums[j]++;
	    p += r;
	    max = MAX(max, j);
	}

	loop(i, 0, max+1) {
	    while(nums[i]--) {
		sprintf(tmp, "%d", i);
		cprint(tmp);
		if (! (i == max && nums[i] == 0) ) {
		    cprint(" ");
		}
	    }
	}
	*pout = '\0';
	puts(out);
	    
    }
    
    return 0;
}
