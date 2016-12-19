#include <bits/stdc++.h>
#define loop(n, i, f) for(n = i; n < f; ++n)
#define MOD(x, y) ( ((x % y) + y) % y )
#define DIM 4
using namespace std;

class puzzle {
    vector< vector< int > > conf;
    pair<int, int> pos;
public:
    puzzle(int *a) {
	int i, j, p = 0;
	loop(i, 0, DIM) {
	    loop(j, 0, DIM) {
		conf[i][j] = a[p++];
		if (conf[i][j] == 0) pos = make_pair(i, j);
	    }
	}
    }

    ~puzzle() {}

    friend puzzle move( puzzle &, int, int );
};

puzzle move( puzzle & p, int dx, int dy ) {
    int i = p.pos.first, j = p.pos.second;
    puzzle n = p;
    swap(n.conf[i][j], n.conf[i+dx][j+dy]);
    return n;
}

map< puzzle, int > mem;

char solution[100];

typedef unsigned int lli;

template<class T>
struct node {
    lli d;
    T * pi;
    char step;
    node(lli dd, char stepp, T * pii = NULL) {
	d = dd;
	pi = pii;
	step = stepp;
    }
    ~node() {}
};

set< node< puzzle > > nodes; 
map< puzzle, set> edges;

int sol[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
puzzle solved( sol );

void calc(puzzle init, int n = 0) {
    if (n == 51) return;
    if (n > 0 && init == solved) return;
    if (n)





int main() {
    int n;
    scanf("%d", &n);
    int conf[DIM*DIM];
    int i, j;
    loop(i, 0, n) {
	loop(j, 0, DIM*DIM) {
	    scanf("%d", conf[i]);
	}
	nodes.insert(solved)
	solve(puzzle(conf));
	printf("%s\n", solution);
    }

    return 0;
}
