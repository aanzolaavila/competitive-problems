#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 10100
#define N 101
#define INF 1e12
#define EPS 1e-5
#define EPS2 1e-9

using namespace std;

typedef double ld;

int n;

struct pt {
    ld x, y;
    
    ld dist_sq(const pt &o) {
	return sqrt(pow(o.x - x, 2) + pow(o.y - y, 2));
    }

    bool operator==(pt &o) {
	return abs(o.x-x) < EPS && abs(o.y-y) < EPS;
    }
};

pt pts[SZ];

ld mdist1() {
    ld m = INF;
    for(int i = 0; i < n-1; i++) {
	for(int j = i+1; j < n && (pts[i].x + m > pts[j].x); j++) {
	    m = min(m, pts[i].dist_sq(pts[j]));
	}
    }

    return m;
}

ld mdist(int i, int j) {
    if (j - i <= 1) return INF;
    if (j - i == 2) return pts[i].dist_sq(pts[j]);

    int mid = (i+j) / 2;
    ld m = min(mdist(i, mid), mdist(mid+1, j));

    ld x = (pts[mid].x + pts[mid+1].x)*0.5;

    ld mi = m;

    if (m < EPS) return 0.0L;
    
    for(int l = mid+1; (pts[l].x < x+m) && (l <= j); l++) {
	for(int k = mid; (pts[k].x > x-m) && (k >= i); k-- ) {
	    mi = min(mi, pts[k].dist_sq(pts[l]));
	}
    }

    return min(m, mi);
}

ld min_dist() {
    return abs(mdist1());
}

bool cmp(pt &a, pt &b) {
    return ( abs(a.x - b.x) < EPS2 && a.y < b.y ) || a.x < b.x ;
}

bool cmpx(pt &a, pt &b) {
    return a.x < b.x;
}

bool cmpy(pt &a, pt &b) {
    return a.y < b.y;
}

int main() {
    int i;
    ld m;

    while(scanf("%d", &n), n) {
	loop(i, 0, n) {
	    scanf("%lf%lf", &pts[i].x, &pts[i].y);
	}

	sort(pts, pts+n, cmp);
	m = min_dist();

	//printf("DEB: %.38lf %.38lf  ", m, 10000.0 - m);
	
	if (10000.0 - m > EPS) {
	    printf("%.4lf\n", m);
	} else {
	    puts("INFINITY");
	}
    }

    return 0;
}
