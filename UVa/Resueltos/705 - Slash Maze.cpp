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
#define N 12800
#define SZ 500
#define MP make_pair
#define F first
#define S second
#define INF 100000000

using namespace std;

char slash[N][SZ];
int w, h;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi graph[N];
bool vis[N];
ll d[N];

inline int node(int i, int j) {
    //printf("NODE(%d, %d) = %d\n", i, j, i*w+j);
    return i*w+j;
}

inline void g(int i, int j, int ii, int jj){
    //printf("(%d, %d) -> (%d, %d)\n", i, j, ii, jj);
    graph[node(i, j)].push_back(node(ii, jj));
    graph[node(ii, jj)].push_back(node(i, j));
}

void gen() {
    memset(vis, 0, sizeof(vis));
    
    int i, j;
    loop(j, 0, w-1) {
	loop(i, 0, h) {
	    if (slash[i][j] == '\\') {
		if (slash[i][j+1] == '\\') {
		    //g(2*i, j, 2*i+1, j+1);
		    g(2*i+1, j+1, 2*i, j);
		} else {
		    g(2*i, j, 2*i, j+1);
		}
	    } else {
		if (slash[i][j+1] == '\\') {
		    //g(2*i+1, j, 2*i+1, j+1);
		    g(2*i+1, j+1, 2*i+1, j);
		} else {
		    //g(2*i+1, j, 2*i, j+1);
		    g(2*i, j+1, 2*i+1, j);
		}
	    }
	}
    }

    /*
    loop(j, 0, w) {
	loop(i, 0, h-1) {
	    //g(2*i+1, j, 2*i+2, j);
	    g(2*i+2, j, 2*i+1, j); // arriba
	    g(2*i+1, j, 2*i+2, j); // abajo
	}
    }
    */

    loop(j, 0, w) {
	loop(i, 0, h-1) {
	    if (slash[i][j] == '\\') {
		if (slash[i+1][j] == '\\') {
		    g(2*i+1, j, 2*i+2, j); // abajo
		} else {
		    g(2*i+2, j, 2*i+1, j); // arriba
		}
	    } else {
		if (slash[i+1][j] == '\\') {
		    g(2*i+1, j, 2*i+2, j); // abajo
		} else {
		    g(2*i+2, j, 2*i+1, j); // arriba
		}
	    }
	}
    }
	
}

int k;
ll l;

void dfs(int ss) {
    stack<int> s;
    d[ss] = 0;
    s.push(ss);
    int i, u;
    bool f = false;
    while(!s.empty() && !f) {
	u = s.top(); s.pop();
	if (!vis[u]) {
	    vis[u] = 1;
	    vi &e = graph[u];
	    loop(i, 0, e.size()) {
		//printf("(%d)->(%d)\n", u, e[i]);
		if (!vis[e[i]]) {
		    s.push(e[i]);
		    d[e[i]] = d[u]+1;
		} else if (abs(d[e[i]] - d[u]) > 1) {
		    //printf("<<AQUI\n");
		    k++;
		    l = max(l, abs(d[e[i]] - d[u])+1);
		    f =  true;
		}
	    }
	}
    }
    //if (f) printf("Se encuentra.\n");
}

void dfs() {
    int i, lim = 2*h*w;
    loop(i, 0, lim) {
	if (!vis[i]) {
	    //printf("Visitando: %d\n", i);
	    dfs(i);
	}
    }
}

int main() {
    int i, c = 1;
    while(scanf("%d%d\n", &w, &h), w|h) {
	//memset(graph, 0, sizeof(graph));
	k = 0;
	l = -INF;
	loop(i, 0, N) {
	    graph[i].clear();
	}
	
	loop(i, 0, h) {
	    fgets(slash[i], SZ, stdin);
	}

	gen();
	dfs();
	printf("Maze #%d:\n", c++);
	if (k != 0) {
	    printf("%d Cycles; the longest has length %lld.\n\n", k, l);
	} else {
	    puts("There are no cycles.\n");
	}
    }
    
    return 0;
}
