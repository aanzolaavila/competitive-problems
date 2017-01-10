#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 2000000
#define INF 1000000000

using namespace std;

char str[SZ];
char par[SZ];

bool isPalindrome(const char * c, int len) {
    bool p = true;
    for(int i = 0; p && i <= len/2; i++) {
	p &= c[i] == c[len-i-1];
    }

    return p;
}

int parse() {
    char *s = str, *d = par;
    int len = 0;
    char tmp;
    while(*s != '\0') {
	tmp = *s++ | (1 << 5);
	if(INRANGE(tmp, 'a', 'z')) {
	    *d++ = tmp;
	    ++len;
	}
    }
    
    *d = '\0';
    return len;
}

int main() {
    int len;
    while(fgets(str, SZ, stdin), strcmp("DONE\n", str) != 0) {
	len = parse();
	printf("%s\n", isPalindrome(par, len) ? "You won't be eaten!" : "Uh oh..");
    }

    return 0;
}
