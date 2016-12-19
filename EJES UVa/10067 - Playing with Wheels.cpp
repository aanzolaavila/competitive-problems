#include <bits/stdc++.h>
#define loop(n, i, f) for(n = i; n < f; ++n)
#define INF ~0
#define MOD(n, m) (((n%m)+m)%m)

using namespace std;
typedef short int sint;

char c[4];

inline short int convert(){
    scanf("%c %c %c %c", c, c+1, c+2, c+3);
    return c[0]*1000 + c[1]*100 + c[2]*10 + c[3];
}

enum color_t {white, gray, black};

struct vertex {
    color_t color = white;
    sint id;
    bool forbidden = false;
    unsigned int d = INF;
    vertex * pi = NULL
    vertex(sint dt) : id(dt) {}
};

class graph {
    bool undirected;
    map< sint, vertex> vertices;
    map< sint, set<vertex *> > edges;

public:
    graph(int sz, bool d = true) : undirected(d) {vertices.reserve(sz);}
    void add(int s, int d);
    void bfs(int src);
    void clear();
    void forb(set<sint> f);
};

void graph::add(int s, int d) {
    vertex * ss = &vertices[s] = vertex(s);
    vertex * dd = &vertices[d] = vertex(d);
    
    edges[s].insert(dd);
    if (undirected) edges[d].insert(ss);
}

void graph::bfs(int src) {
    typedef set<vertex *>::iterator it;

    vertex &s = vertices[src];
    s.d = 0;
    queue q<vertex *>;
    q.push(&s);
    while(!q.empty()) {
	vertex &u = q.front(); q.pop();
	for(it i = edges[u.id].begin(); i != edges[u.id].end(); ++i) {
	    vertex &v = **i;
	    if (v.color == white && !v.forbidden) {
		v.color = gray;
		v.pi = &u;
		v.d = u.d +1;
		q.push(&v);
	    }
	}
	u.color = black;
    }
}

void graph::clear() {
    typedef set<vertex>::iterator it;
    for(it i = vertices.begin(); i != vertices.end() ; ++i) {
	*i.color = white;
	*i.forbidden = false;
	*i.d = INF;
	*i.pi = NULL;
    }
}

void graph::forb(set<sint> f) {
    for(set<sint>::iterator i = f.begin(); i != f.end(); ++i) {
	vertices[*i].forbidden = true;
    }
}

graph game(true);

inline sint convert(int * n) {
    return n[0]*1000 + n[1]*100 + n[2]*10 + n[3];
}

void calc(int state = 0) {
    
    
}

int main() {
    int n, i, m, j;
    calc();
    sint init, target;
    set<sint> forbidden;
    loop(i, 0, n) {
	forbidden.clear();
	init = convert(c);
	target = convert(c);
	
	scanf("%d", &m);
	loop(j, 0, m) {
	    forbidden.insert(convert());
	}
	game.forb(forbidden);
	game.bfs(init);
	
