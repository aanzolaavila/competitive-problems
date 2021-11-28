#include <bits/stdc++.h>

#define loop(c, i, n) for(c = i; c < n; ++c)

using namespace std;

enum color_t {white, black, no_color};

struct vertex {
    int id;
    vertex *pi;
    bool visited;
    color_t color;

    vertex(int i, vertex *pii = NULL, bool vis = false, color_t col = no_color) : pi(pii), visited(vis), color(col), id(i) {}
    ~vertex() {}
};

class graph {
    bool undirected;
    vector<vertex> vertices;
    map<int, set<int> > edges;
    
public:
    graph(bool dir) : undirected(dir) {}
    ~graph() {}
    void add(int s, int e);
    bool bfs(int);
    void clear(int);
};

void graph::add(int s, int e) {
    edges[s].insert(e);
    if (undirected) edges[e].insert(s);
}

bool graph::bfs(int src) {
    typedef set<int>::iterator it;

    vertex * s = &vertices[src];
    s->color = white;
    queue<vertex *> q;
    q.push(s);
    while(!q.empty()) {
	vertex &u = *q.front(); q.pop();
	for(it i = edges[u.id].begin(); i != edges[u.id].end(); ++i) {
	    vertex &v = vertices[*i];
	    switch(v.color) {
	    case no_color:
		v.color = u.color == white ? black : white;
		break;
	    default:
		if (u.color == v.color)
		    return false;
		continue;
	    }
	    v.pi = &u;
	    q.push(&v);
	}
    }

    return true;
}

void graph::clear(int sz) {
    vertices.clear();
    edges.clear();
    vertices.reserve(sz);
    int i;
    loop(i, 0, sz) {
	vertices.push_back(vertex(i));
    }
}

int main() {
    int n, l, s, f, i;
    graph g(true);
    while(scanf("%d", &n), n) {
	scanf("%d", &l);
	g.clear(n);
	loop(i, 0, l) {
	    scanf("%d %d", &s, &f);
	    g.add(s, f);
	}

	printf("%s.\n", g.bfs(0) ? "BICOLORABLE" : "NOT BICOLORABLE" );
    }
}
