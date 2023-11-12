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
#define SZ 10000000
#define N 1010
#define M 25
#define INF 1000000000

using namespace std;

struct pt {
    int i;
    int x, y;
    int dist(pt &o) {
	return  pow(o.x - x, 2) + pow(o.y - y, 2);
    }
};

pt pts[N];

bool graph[N][N];
bool vis[N];

int d[N][N];

int n;

inline bool cmp(pt &a, pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

void min_dist() {
    int i, j;
    int p1, p2, m;
    loop(i, 0, n) {
	m = INF;
	p1 = p2 = i;
	loop(j, 0, n) {
	    if (i != j && (d[i][j] < m || (d[i][j] == m && cmp(pts[j], pts[p1])))) {
		m = d[i][j];
		p1 = j;
	    }
	}

	m = INF;
	loop(j, 0, n) {
	    if (i != j && j != p1 && (d[i][j] < m || (d[i][j] == m && cmp(pts[j], pts[p2])))) {
		m = d[i][j];
		p2 = j;
	    }
	}

	//printf("(%d, %d)-> (%d, %d)\n", pts[i].x, pts[i].y, pts[p1].x, pts[p1].y);
	//printf("(%d, %d)-> (%d, %d)\n", pts[i].x, pts[i].y, pts[p2].x, pts[p2].y);

	graph[i][p1] = 1;
	graph[i][p2] = 1;
    }
	    
}

void gen() {
    memset(vis, 0, sizeof(vis));

    int i, j;
    loop(i, 0, n) {
	loop(j, 0, n) {
	    graph[i][j] = 0;
	}
    }

    loop(i, 0, n) {
	loop(j, i+1, n) {
	    d[i][j] = d[j][i] = pts[i].dist(pts[j]);
	}
	d[i][i] = INF;
    }

    min_dist();
}

void bfs(int u) {
    int i, v;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()) {
	u = Q.front(); Q.pop();
	loop(i, 0, n) {
	    if (graph[u][i]) {
		v = i;
		if (!vis[v]) {
		    vis[v] = 1;
		    Q.push(v);
		}
	    }
	}
	vis[u] = 1;
	//printf("u: %d Q: %d\n", u, Q.size());
    }
}

int main() {
    int i, j;
    bool reach;

    while(scanf("%d", &n), n) {
	loop(i, 0, n) {
	    scanf("%d%d", &pts[i].x, &pts[i].y);
	    pts[i].i = i;
	}

	gen();

	bfs(0);

	/*
	loop(i, 0, n) {
	    loop(j, 0, n) {
		printf("%d", graph[i][j]);
	    }
	    puts("");
	}

	loop(i, 0, n) {
	    printf("%d", vis[i]);
	}
	puts("");
	*/

	reach = true;
	i = 0;
	while(reach && i < n) {
	    reach = vis[i++];
	}
	
	if (reach) {
	    puts("All stations are reachable.");
	} else {
	    puts("There are stations that are unreachable.");
	}
    }

    return 0;
}
    
