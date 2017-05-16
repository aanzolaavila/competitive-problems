#define NDEBUG
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
#define N 201
#define M 10010
#define INF 1000000000
#define MP make_pair
#define F first
#define S second

using namespace std;

typedef int ll;
typedef pair<ll,ll> ii;
typedef pair<ll, ii> iii;

struct st {
    iii s;
    st() {
	st(0, 0, 0);
    }
    
    st(ll a, ll b, ll c) {
	s.F = a;
	s.S.F = b;
	s.S.S = c;
    }
    
    ll& operator[](int i) {
	i = ABS(i);
	switch(i % 3) {
	case 0:
	    return s.F;
	    break;
	case 1:
	    return s.S.F;
	    break;
	case 2:
	    return s.S.S;
	}
    }

    bool operator<(const st &o) const {
	return s < o.s;
    }
};

int a, b, c, d;

inline const int& acc(int i) {
    i = ABS(i);
    switch(i % 3) {
    case 0:
	return a;
    case 1:
	return b;
    case 2:
	return c;
    }
}

int dd;

bool vis[N][N][N];
typedef pair<unsigned int, st> ver;
typedef set< ver > S;
typedef map<st, S > G;
G graph;
unsigned int dist[N][N][N];

inline void clear() {
    memset(vis, 0, sizeof(vis));
}

inline void visit(st &v) {
    vis[v[0]][v[1]][v[2]] = 1;
}

inline bool is_visited(st &v) {
    return vis[v[0]][v[1]][v[2]];
}

inline int closer(st &v) {
    int i, dr = d;
    loop(i, 0, 3) {
	if (v[i] <= d) {
	    dr = min(dr, d -v[i]);
	}
    }
    
    return dr;
}

void gen() {
    graph.clear();
    clear();
    queue<st> q;
    q.push(st(0, 0, c));

    int i, j;
    int r, val;
    while(!q.empty()) {
	st u = q.front(); q.pop();
	if(! is_visited(u)) {
	    visit(u);

	    loop(i, 0, 3) {
		loop(j, 0, 3) {
		    if (i != j && u[j] < acc(j) && u[i] > 0) {
			st t = u;

			//printf("t: %p u: %p\n", &t, &u);
			
			r = min(acc(j) - u[j], u[i]);
			t[i] -= r;
			t[j] += r;
			assert(t[j] <= acc(j));

			/*if (t[0] > acc(0) || t[1] > acc(1) || t[2] > acc(2)) {
			    printf("ERR: (%d %d %d) -> ", u[0], u[1], u[2]);
			    printf("(%d %d %d)\n", t[0], t[1], t[2]);
			    }*/

			/*if (t[0] + t[1] + t[2] != c) {
			    printf("(%d %d %d)\n", u[0], u[1], u[2]);
			    printf("ERROR: (%d %d %d) c = %d, r = %d (%d -> %d)\n", t[0], t[1], t[2], c, r, i+1, j+1);
			    }*/
			assert(t[0] + t[1] + t[2] == c);
			/*if (closer(t) == dd) {
			    printf("INTERCAMBIO: (%d %d %d) -> ", u[0], u[1], u[2]);
			    printf("(%d %d %d)\n", t[0], t[1], t[2]);
			    }*/
			q.push(t);
			graph[u].insert(MP(r, t));
			val = closer(t);
			dd = min(dd, val);
		    }
		}
	    }
	}
    }

    clear();
}

unsigned int min_dist;

typedef S::iterator it;

inline unsigned int& dis(st &v) {
    return dist[v[0]][v[1]][v[2]];
}

void dijkstra() {
    min_dist = INF;
    memset(dist, 0xff, sizeof dist);

    dist[0][0][c] = 0;
    priority_queue<ver, vector<ver>, greater<ver> > pq;
    pq.push(ver(0, st(0,0,c)));
    
    while(!pq.empty()) {
	ver fro = pq.top(); pq.pop();
	int di = fro.F;
	st u = fro.S;

	if (di > dis(u)) continue;
	
	for(it i = graph[u].begin(); i != graph[u].end(); i++) {
	    ver v = *i;
	    if (dis(u) + v.F < dis(v.S)) {
		dis(v.S) = dis(u) + v.F;
		pq.push(MP(dis(v.S), v.S));
		if (closer(v.S) == dd) {
		    //printf("POSIBLE!! %ld (%d %d %d)\n", min_dist, v.S[0], v.S[1], v.S[2]);
		    if (min_dist > dis(v.S)) {
			min_dist = dis(v.S);
			//printf("SI!! %ld (%d %d %d)\n", min_dist, v.S[0], v.S[1], v.S[2]);
		    }
		}
	    }
	}
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	dd = d;
	if (c <= d) {
	    printf("0 %d\n", c);
	} else {
	    gen();
	    dijkstra();
	    //printf("dd: %d\nSZ: %d\n", dd, graph.size());
	    if (d-dd != 0 && min_dist != INF) {
		printf("%ld %d\n", min_dist, d-dd);
	    } else {
		puts("0 0");
	    }
	}
    }

    return 0;
}
