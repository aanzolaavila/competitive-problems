#include <bits/stdc++.h>

#define loop(it,x,y) for(it = x; it < y; ++it)
#define abs(x) (x >= 0 ? (x) : -(x))

using namespace std;

typedef pair< int, int > pii;

int c;
vector< pii > vals;

inline bool comp(pii a, pii b) {
    return a.second < b.second;
}

void f_sort() {
    sort(vals.begin(), vals.end(), comp);
    int x;
    loop(x, 0, vals.size()) {
	c += abs(vals[x].first - x);
	printf("(%d,%d) ", vals[x].first, vals[x].second);
    }
}
    
int main() {
    int n, i, x;
    while (scanf("%d\n", &n) != EOF) {
	c = 0;
	vals.reserve(n);
	loop(i, 0, n) {
	    scanf("%d ", &x);
	    vals.push_back( make_pair(i, x) );
	}
	f_sort();
	printf("Minimum exchange operations : %d\n", c);
	vals.clear();
    }

    return 0;
}
