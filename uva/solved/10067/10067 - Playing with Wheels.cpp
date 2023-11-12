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
#define N 10010
#define M 10
#define INF 1000000000

using namespace std;

typedef int type;

type graph[N][M];
bool vis[N];
int d[N];
int t[4];

inline void gen(int num) {
    int n = num;
    t[0] = n % 10;
    n /= 10;
    t[1] = n % 10;
    n /= 10;
    t[2] = n % 10;
    n /= 10;
    t[3] = n % 10;

    for(int i = 0; i < 4; i++) {
	INC(t[i], 10);
	graph[num][2*i] = t[0] + t[1]*10 + t[2]*100 + t[3]*1000;
	DEC(t[i], 10);
	DEC(t[i], 10);
	graph[num][2*i+1] = t[0] + t[1]*10 + t[2]*100 + t[3]*1000;

	INC(t[i], 10);
    }
}

void generate() {
    int i, j;
    loop(i, 0, N) {
	//printf("%d\n", i);
	gen(i);
	// loop(j, 0, 8) {
	//     printf("%d ", graph[i][j]);
	// }
	// puts("");
    }
}

inline int read() {
    int i;
    loop(i, 0, 4) {
	scanf("%d", &t[4-i-1]);
    }
    
    return t[0] + t[1]*10 + t[2]*100 + t[3]*1000;
}

int bfs(int u, int s) {
    int i, v;
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while(!Q.empty()) {
	u = Q.front(); Q.pop();
	loop(i, 0, 8) {
	    v = graph[u][i];
	    if (!vis[v]) {
		d[v] = d[u]+1;
		vis[v] = 1;
		Q.push(v);
	    }
	}
	vis[u] = 1;
	//printf("u: %d Q: %d\n", u, Q.size());
    }

    return vis[s] ? d[s] : -1;
	    
}

int main() {
    int i, j;
    loop(i, 0, N) {
	loop(j, 0, M) {
	    graph[i][j] = 0;
	}
    }

    generate();
    
    /*
    loop(i, 0, 8) {
	printf("%d ", graph[0][i]);
    }
    puts("");
    */

    int n, ini, tar, f, fr;
    int c[4];
    scanf("%d", &n);

    while(n--){
	memset(vis, 0, sizeof(vis));
	ini = read();
	tar = read();

	scanf("%d", &f);
	while(f--) {
	    fr = read();
	    vis[fr] = 1;
	}

	printf("%d\n", bfs(ini, tar));
    }

    return 0;
}
