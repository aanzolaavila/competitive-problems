#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 120
#define N 25
#define INF 1000000000
#define F first
#define S second
#define MP make_pair

using namespace std;

int ns[N];
char in[SZ];

int read() {
    char * ptr = strtok(in, " ");
    int i = 0;
    int n = 0;
    while(ptr != NULL) {
	while(*ptr != '\0' && *ptr != '\n') {
	    i *= 10;
	    i += *ptr - '0';
	    ++ptr;
	}
	ns[n++] = i;
	i = 0;
	ptr = strtok(NULL, " ");
    }

    return n;
}

int sum(int n) {
    int s = 0;
    int i;
    loop(i, 0, n) {
	s += ns[i];
    }

    return s;
}

int su, n;

bool f(int i, int s) {
    if (s == su/2) return true;
    if (s != su/2 && i >= n) return false;

    return f(i+1, s+ns[i]) || f(i+1, s);
}

bool calc(int n) {
    su = sum(n);
    if (su % 2 != 0) return false;

    return f(0, 0);
}

int main() {
    int m;
    scanf("%d\n", &m);

    while(m--) {
	fgets(in, SZ, stdin);
	n = read();
	printf("%s\n", calc(n) ? "YES" : "NO");
    }
    
    return 0;
}
