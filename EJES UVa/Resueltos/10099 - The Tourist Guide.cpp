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
#define N 110
#define MP make_pair
#define F first
#define S second
#define INF 100000000

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<ll, ii> iii;
typedef vector< iii > viii;

//vvii graph;
vii graph[N];
viii edges;
bool vis[N];

ll c1, c2, p;

void dfs(ll u, ll v, ll lim) {
    memset(vis, 0, sizeof(vis));

    if (u == v) {
	vis[u] = 1;
	return;
    }

    stack<ll> s;
    s.push(u);
    int i;
    while(!s.empty()) {
	u = s.top(); s.pop();
	if (!vis[u]) {
	    vis[u] = 1;
	    vii &e = graph[u];
	    loop(i, 0, e.size()) {
		if (!vis[e[i].S] && e[i].F >= lim) {
		    s.push(e[i].S);
		}
	    }
	}
    }
}

typedef viii::iterator it;

int calc() {
    bool r = false;
    int mx;
    for(it i = edges.begin(); i != edges.end() && !r; i++) {
	dfs((*i).S.F, (*i).S.S , (*i).F);
	if (vis[c1] && vis[c2]) {
	    mx = (*i).F;
	    r = true;
	}
    }

    return mx;
}

bool cmp(iii &a, iii &b) {
    return a > b;
}

int main() {
    int n, r, c = 1;
    int i;
    
    while(scanf("%d%d", &n, &r), n|r) {
	loop(i, 0, N) {
	    graph[i].clear();
	}
	edges.clear();
	memset(vis, 0, sizeof(vis));

	loop(i, 0, r) {
	    scanf("%ld%ld%ld", &c1, &c2, &p);
	    graph[c1-1].push_back(MP(p, c2-1));
	    graph[c2-1].push_back(MP(p, c1-1));
	    edges.push_back(MP(p, MP(c1-1, c2-1)));
	    //printf("%ld %ld %ld\n", c1, c2, p);
	    //printf("");
	}

	sort(edges.begin(), edges.end(), cmp);
	scanf("%ld%ld%ld", &c1, &c2, &p);
	c1--;
	c2--;

	ll mx = calc();
	//printf("R: %ld\n", mx);
	printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", c++, (int)ceil(p / (double)(mx-1)));
    }

    return 0;
}
    
