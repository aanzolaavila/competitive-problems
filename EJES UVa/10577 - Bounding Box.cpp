#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 110
#define N 101
#define EPS 1e-9
#define INF 1000000000

using namespace std;

typedef long double ll;

struct p {
    ll x, y;
    ll dist(const p &o) {
	ll dx = fabs(o.x - x);
	ll dy = fabs(o.y - y);
	return sqrt(dx*dx + dy*dy);
    }
};

ll area(ll a, ll b, ll c) {
    ll s = (a+b+c)*0.5L;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

ll rr(ll a, ll b, ll c) {
    return a*b*c/4.0L/area(a,b,c);
}

ll radius(p a, p b, p c) {
    return rr(a.dist(b), b.dist(c), c.dist(a));
}

int n;
p a, b, c;
long double pi = acos(-1.0L);

void rot(ll r, ll &x, ll &y, int i) {
    ll theta = atan2(y, x) + ((ll)i)*2.0L*pi/((ll)n);
    x = r*cos(theta);
    y = r*sin(theta);
    //printf("x: %Lf, y: %Lf\n", x, y);
}

void ml(ll &m, ll &b, p &p1, p &p2) {
    m = (p2.y - p1.y) / (p2.x - p1.x);
    b = (p1.x < p2.x ? p1 : p2).y - m*(p1.x < p2.x ? p1.x : p2.x);
}

void mp(ll &m, ll &b, p &p1, p &p2) {
    ll m1, b1;
    ml(m1, b1, p1, p2);
    m = - (p2.x - p1.x) / (p2.y - p1.y);
    //ll c = (p2.y - p1.y) / (p2.x - p1.x) * (p2.x + p1.x)/2 - m*(p2.x + p1.x)/2;
    //b = (p1.x < p2.x ? p1 : p2).y - m*min(p1.x, p2.x) + c;
    b = b1 + (m1-m)*(p2.x+p1.x)/2;
    //printf("m: %Lf, b: %Lf\n", m, b);
}

p calc_center() {
    p p1, p2, p3;
    p1 = a;
    p2 = fabs(a.y - b.y) >= EPS ? b : c;
    p3 = fabs(a.y - b.y) >= EPS ? c : b;

    ll m1, b1;
    ll m2, b2;

    mp(m1, b1, p1, p2);
    if ( abs(p2.y - p3.y) < EPS) p2 = a;
    mp(m2, b2, p2, p3);
    
    ll x = (b2 - b1) / (m1 - m2);
    p r;
    r.x = x, r.y = m1*x+b1;
    //printf("CENTER x: %Lf, y: %Lf\n", r.x, r.y);
    return r;
}

ll solve(ll r) {
    ll x = a.x, y = a.y;
    p center = calc_center();
    r = sqrt( pow(center.x - x, 2) + pow(center.y - y, 2) );
    //printf("%s <%.16Lf> ", rr != r ? "Si" : "No", rr-r);
    x -= center.x;
    y -= center.y;
    int i;
    
    ll minx, maxx, miny, maxy;
    minx = maxx = x;
    miny = maxy = y;

    ll xx, yy;

    loop(i, 0, n-1) {
	xx = x;
	yy = y;
	rot(r, xx, yy, i+1);
	minx = min(minx, xx);
	maxx = max(maxx, xx);
	miny = min(miny, yy);
	maxy = max(maxy, yy);
    }

    return (maxx - minx) * (maxy - miny);
}

int main() {
    ll res;
    int t = 1;
    
    while(scanf("%d", &n), n) {
	scanf("%Lf %Lf", &a.x, &a.y);
	scanf("%Lf %Lf", &b.x, &b.y);
	scanf("%Lf %Lf", &c.x, &c.y);

	res = solve(radius(a, b, c));

	printf("Polygon %d: %.3Lf\n", t++, res);
    }

    return 0;
}
