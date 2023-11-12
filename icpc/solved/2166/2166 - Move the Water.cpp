#ifdef __APPLE__
#include "../../stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 100100
#define N 3
#define INF 1000000000
#define EPS 1e-9

using namespace std;

int c1, c2, c3, a1, a2, a3, b1, b2, b3;

inline const int& acc(int i) {
    switch(i%N) {
    case 0:
	return c1;
    case 1:
	return c2;
    case 2:
	return c3;
    }
}

struct ver {
    int j1, j2, j3;

    int& operator[](int i) {
	switch(i%N) {
	case 0:
	    return j1;
	case 1:
	    return j2;
	case 2:
	    return j3;
	}
    }

    bool operator<(const ver& o) const {
	bool r = j1 < o.j1;
	r |= j1 == o.j1 && j2 < o.j2;
	r |= j1 == o.j1 && j2 == o.j2 && j3 < o.j3;
	return r;
    }

    /*bool operator==(const ver& o) const {
	return j1 == o.j1 && j2 == o.j2 && j3 == o.j3;
	}*/
};

typedef set<ver> vver;
map<ver, vver > graph;
map<ver, int> vis;

inline int move(int s, int d, int cd) {
    //printf("MOVE: %d %d %d", s, d, cd);
    return cd - d > s ? s : cd - d;
}

void gen(ver &ini) {
    queue<ver> q;
    q.push(ini);
    int i, j, r, k;
    while(!q.empty()) {
	ver &a = q.front(); q.pop();
	loop(i, 0, N){
	    loop(j, i+1, i+N) {
		ver tmp;
		r = move(a[i], a[j], acc(j));
		//r = RANGE(r, 0, acc(j));
		//printf(" r = %d\n", r);
		//if (r < 0) printf("Falla!!!! %d\n", r);
		if (r > 0) {
		    loop(k, 0, N) {
			tmp[k] = a[k];
		    }
		    tmp[i] -= r;
		    tmp[j] += r;

		    //printf("TMP: %d %d %d\n", tmp[0], tmp[1], tmp[2]);

		    if (! graph.count(a)) {
			graph[a] = vver();
		    }

		    if (! graph.count(tmp)) {
			q.push(tmp);
			graph[a].insert(tmp);
		    }
		}
	    }
	}
    }
}

typedef vver::iterator it;

void bfs(ver s) {
    vis[s] = 0;
    queue<ver> q;
    q.push(s);
    while(!q.empty()) {
	ver u = q.front(); q.pop();
	vver &adj = graph[u];
	for(it i = adj.begin() ; i != adj.end(); i++) {
	    if (!vis.count(*i)) {
		vis[*i] = vis[u]+1;
		q.push(*i);
	    }
	}
    }
}

int main() {
    ver ini;
    ver fin;
    while(scanf("%d%d%d%d%d%d%d%d%d", &c1, &c2, &c3, &a1, &a2, &a3, &b1, &b2, &b3), c1) {
	graph.clear();
	vis.clear();
	ini[0] = a1;
	ini[1] = a2;
	ini[2] = a3;

	fin[0] = b1;
	fin[1] = b2;
	fin[2] = b3;

	if (b1+b2+b3 != a1+a2+a3) {
	    puts("-1");
	    continue;
	}

	gen(ini);
	bfs(ini);
	printf("%d\n", vis.count(fin) ? vis[fin] : -1);
    }

    return 0;
}
