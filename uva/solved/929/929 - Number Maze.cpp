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
#define SZ 1500000
#define N 1010
#define DIR 4
#define INF 1000000000
#define F first
#define S second
#define MP make_pair

using namespace std;

int n, m;
int maze[N][N];

int dir[][2] = {{0,1},{1,0},{-1,0},{0,-1}};

typedef int ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

vii graph[SZ];
int dist[SZ];
int V;

inline int node(int i, int j) {
    return i*(max(m, n))+j;
}

void gen() {
    int i, j, k;
    loop(i, 0, n) {
	loop(j, 0, m) {
	    loop(k, 0, DIR) {
		int x = i+dir[k][0];
		int y = j+dir[k][1];
		if(INRANGE(x, 0, n-1)) {
		    if(INRANGE(y, 0, m-1)) { // no dirigido
			graph[node(i, j)].push_back(MP(node(x, y), maze[x][y]));
			//graph[node(x, y)].push_back(MP(node(i, j), maze[i][j]));
		    }
		}
	    }
	}
    }
}

void sp(ll s) {
    int i;
    loop(i, 0, SZ) {
	dist[i] = INF;
    }
    
    dist[s] = maze[0][0];
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(dist[s], s));
    
    while(!pq.empty()) {
	ii front = pq.top(); pq.pop();
	int d = front.F, u = front.S;
	if (d > dist[u]) continue;
	loop(i, 0, graph[u].size()) {
	    ii &v = graph[u][i];
	    if (dist[u] + v.S < dist[v.F]) {
		dist[v.F] = dist[u] + v.S;
		pq.push(ii(dist[v.F], v.F));
	    }
	}
    }
}

void bucket_sp(ll s) {
    int i;
    loop(i, 0, SZ) {
	dist[i] = INF;
    }

    vector<list<int>::iterator> its(m*n);
    list<int> B[9*m*n +1];
    B[0].push_back(s);
    dist[s] = 0;

    i = 0;
    int j;
    while(true) {
	while(B[i].size() == 0 && i < m*n) {
	    i++;
	}

	if (i == m*n) break;

	int u = B[i].front();
	B[i].pop_front();

	loop(j, 0, graph[u].size()) {
	    int v = graph[u][j].F;
	    int w = graph[u][j].S;

	    int du = dist[u];
	    int dv = dist[v];
	    
	    if (dv > du + w) {
		if (dv != INF) {
		    B[dv].erase(its[v]);
		}

		dist[v] = du +w;
		dv = dist[v];

		B[dv].push_front(v);

		its[v] = B[dv].begin();
	    }
	}
    }
}

int main() {
    int t;
    scanf("%d", &t);

    int i, j;
    while(t--) {
	loop(i, 0, SZ) {
	    graph[i].clear();
	}
	
	scanf("%d%d", &n, &m);
	loop(i, 0, n) {
	    loop(j, 0, m) {
		scanf("%d", &maze[i][j]);
	    }
	}

	gen();
	sp(0);
	//bucket_sp(0);
	printf("%d\n", dist[node(n-1, m-1)]);

	/*loop(i, 0, n) {
	    loop(j, 0, m) {
		printf("(%d, %d, %d) = %d\n", i, j, maze[i][j], dist[node(i, j)]);
	    }
	}
	*/
    }

    return 0;
}
