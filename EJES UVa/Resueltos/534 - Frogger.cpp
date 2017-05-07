#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) < (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 2000
#define N 210
#define INF 1000000000
#define EPS 1e-9
#define X first
#define Y second
#define F first
#define S second
#define MP make_pair


using namespace std;

typedef int ll;
typedef pair<ll, ll> pt;
typedef vector< pair<double, pt> > vii;
typedef vector< pair<double, ll> > vi;

int n;
pt pts[N];

vii graph;
vi mst[N];

struct UnionFind {
    vector<int> p, rank;
    UnionFind(int n) {
	int i;
	rank.assign(n, 0);
	p.assign(n, 0);
	loop(i, 0, n) {
	    p[i] = i;
	}
    }

    int findSet(int i) {
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
	if (!isSameSet(i, j)) {
	    int x = findSet(i), y = findSet(j);
	    if (rank[x] > rank[y]) {
		p[y] = x;
	    } else {
		p[x] = y;
		if (rank[x] == rank[y]) {
		    rank[y]++;
		}
	    }
	}
    }
};

bool vis[N];
pair<double, ll> p[N];

double dfs(int ss, int v) {
    memset(vis, 0, sizeof(vis));
    int i, u;
    loop(i, 0, N) {
	p[i].S = i;
    }
    
    double mx = -INF;
    stack<ll> s;
    s.push(ss);
    while(!s.empty()) {
	u = s.top(); s.pop();
	if (!vis[u]) {
	    vis[u] = 1;
	    loop(i, 0, mst[u].size()) {
		if(!vis[mst[u][i].S]) {
		    s.push(mst[u][i].S);
		    p[mst[u][i].S] = MP(mst[u][i].F, u);
		}
	    }
	}
    }

    i = v;
    while(p[i].S != i) {
	mx = max(mx, p[i].F);
	i = p[i].S;
    }

    return mx;
}

double calc() {
    int i;
    loop(i, 0, N) {
	mst[i].clear();
    }

    double mst_max = -INF;
    UnionFind UF(n);
    loop(i, 0, graph.size()) {
	pair<double, pt > front = graph[i];
	if (!UF.isSameSet(front.S.F, front.S.S)) {
	    mst_max = max(mst_max, front.F);
	    mst[front.S.F].push_back(MP(front.F, front.S.S));
	    mst[front.S.S].push_back(MP(front.F, front.S.F));
	    UF.unionSet(front.S.F, front.S.S);
	}
    }

    double dfs_r = dfs(0, 1);
    //printf("EQ: %d ", dfs_r == mst_max);

    return dfs_r;
}

double dist(pt &a, pt &b) {
    return sqrt(pow(a.X-b.X, 2) + pow(a.Y - b.Y, 2));
}

inline int node(int i, int j) {
    return i*N + j;
}

int main() {
    int c = 1;
    int i, j;
    while(scanf("%d", &n), n) {
	graph.clear();
	
	loop(i, 0, n) {
	    scanf("%d%d", &pts[i].X, &pts[i].Y);
	}

	loop(i, 0, n) {
	    loop(j, 0, n) {
		graph.push_back(MP(dist(pts[i], pts[j]), MP(i, j)));
	    }
	}
	sort(graph.begin(), graph.end());

	float r = calc();
	printf("Scenario #%d\nFrog Distance = %.3f\n\n", c++, r);
    }

    return 0;
}
