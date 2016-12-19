#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x; it < y; ++it)
#define max(x, y) (x >= y ? x : y)
#define abs(x) (x >= 0 ? x : -x)
#define SZ 1025

using namespace std;

typedef pair< pair<int, int>, int> pii;

int s, d, n, x, y, i;

inline bool comp(pii a, pii b) {
    return max( abs(a.first.first - b.first.first), abs(a.first.second - b.first.second) ) <= 2*d;
}

vector< pii > points;

int main() {
    scanf("%d\n", &s);
    int it;
    loop(it, 0, s) {
	scanf("%d\n%d\n", &d, &n);
	points.resize(0);
	if (points.capacity() < n) points.reserve(n);
	int p;
	loop(p, 0, n) {
	    scanf("%d %d %d", &x, &y, &i);
	    points.push_back(make_pair( make_pair(x, y), i ));
	}
	sort(points.begin(), points.end(), comp);
	loop(p, 0, n) {
	    printf("%d %d %d\n", points[p].first.first, points[p].first.second, points[p].second);
	}
    }

    return 0;
}
	
