#include <bits/stdc++.h>
#define SZ 100
#define loop(n, i, f) for(n = i; n < f; ++n)
using namespace std;

struct pos {
    const short int x, y;
    pos(short int xx, short int yy) : x(xx), y(yy) {}
};

typedef pair< pos, pos > ppp;

map< ppp , int > mem;

short int grid[SZ][SZ];

int n, mx = ~0;

int sum(const pos & p, const pos & s) {
    int i, j, s = 0;
    loop(i, p.x, s.x+1) {
	loop(j, p.y, s.y+1)
	    sum += grid[i][j];
    }
    return s;
}


int calc(const pos & p, const pos & s) {
    ppp actual = make_pair(p, s);
    if ( mem.count(actual) )
	return mem[actual];
    int i, j, s;
    loop(i, p.x, s.x+1) {
	loop(j, p.y, s.y+1)
	    
}

int main() {
    scanf("%d", &n);
    int i, j;
    loop(i, 0, n) {
	loop(j, 0, n) scanf("%d", &grid[i][j]);
    }
    calc(pos(0,0), pos(n-1, n-1));
    printf("%d\n", max);

    return 0;
}
