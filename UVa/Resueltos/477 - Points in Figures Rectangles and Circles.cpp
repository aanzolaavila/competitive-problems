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
#define SZ 1000
#define INF 1000000000
#define EPS 1e-9

using namespace std;

typedef double lf;

enum {C = 0, R};

struct point {
    lf x, y;
    lf dist(const point &o) {
	return sqrt( pow(x - o.x, 2) + pow(y - o.y, 2) );
    }
};

struct fig {
    bool f;
    point p1, p2;

    bool ins(const point &o) {
	bool r = false;

	if (f == C) {
	    r = p1.dist(o) < p2.x; // p2.x = r
	} else {
	    r = p1.x < o.x && o.x < p2.x;
	    r = r && p2.y < o.y && o.y < p1.y;
	}

	return r;
    }

    void print() {
	printf("(%p) p1: %lf %lf p2: %lf %lf\n", this, p1.x, p1.y, p2.x, p2.y);
    }
    
};

vector<fig> figures;

int main() {
    char c;
    char in[SZ];

    lf d1, d2, d3, d4;
    
    while(scanf("%c", &c), c != '*') {
	if (c != 'c' && c != 'r') continue;
	
	fgets(in, SZ, stdin);
	figures.push_back(fig());
	fig &a = figures.back();
	switch(c) {
	case 'r':
	    a.f = R;
	    sscanf(in, "%lf%lf%lf%lf", &d1, &d2, &d3,&d4);
	    a.p1.x = d1;
	    a.p1.y = d2;
	    a.p2.x = d3;
	    a.p2.y = d4;
	    break;
	case 'c':
	    a.f = C;
	    sscanf(in, "%lf%lf%lf", &d1, &d2, &d3);
	    a.p1.x = d1;
	    a.p1.y = d2;
	    a.p2.x = d3;
	    break;
	}
    }

    int i;
    /*loop(i, 0, figures.size()){
	figures[i].print();
    }
    */

    point a;
    int t = 1;
    bool cont;
    fgets(in, SZ, stdin); // ignora
    while(fgets(in, SZ, stdin), strstr(in, "9999.9 9999.9") == NULL) {
	sscanf(in, "%lf%lf", &a.x, &a.y);

	//printf("FIGURE %d: %lf %lf\n", t, a.x, a.y);

	cont = false;
	loop(i, 0, figures.size()) {
	    if (figures[i].ins(a)) {
		printf("Point %d is contained in figure %d\n", t, i+1);
		cont = true;
	    }
	}

	if (!cont) {
	    printf("Point %d is not contained in any figure\n", t);
	}

	++t;
    }
    
    return 0;
}
