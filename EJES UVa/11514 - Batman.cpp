#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 110
#define N 1010
#define INF 1000000000

using namespace std;

int p, v, e;

struct power {
    string name;
    int attack;
    int energy;
    power(string n, int a, int c): name(n), attack(a), energy(c) {}
};

struct villain {
    int defense;
    set<string> vuln;
};

vector<power> powers;
//map<string, power> powers_n;
vector<villain> villains;

bool solve();
bool calc(int, int, int);

int main() {
    int i;
    char tmp[SZ];
    char tmp2[SZ];
    char * t;
    int a, c;
    
    while(scanf("%d%d%d", &p, &v, &e), p|v|e) {
	powers.clear();
	//powers_n.clear();
	villains.clear();

	loop(i, 0, p) {
	    scanf("%s %d %d", tmp, &a, &c);
	    string n(tmp);
	    power po(n, a, c);
	    powers.push_back(po);
	    //powers_n[n] = po;
	}

	loop(i, 0, v) {
	    villain v;
	    scanf("%*s %d %s\n", &a, tmp2);
	    printf("%d %s : ", a, tmp2);
	    v.defense = a;
	    t = strtok(tmp2, ",");
	    while(t != NULL) {
		printf("%s ", t);
		v.vuln.insert(string(t));
		t = strtok(NULL, ",");
	    }
	    puts("");
	    //sort(v.vuln.begin(), v.vuln.end());
	    villains.push_back(v);
	}

	printf("%s\n", solve() ? "Yes" : "No");
    }

    return 0;
}

int mem[N][N][2];

bool solve() {
    int i, j;
    loop(i, 0, N) {
	loop(j, 0, N) {
	    mem[i][j][0] = -1;
	    mem[i][j][1] = INF;
	}
    }
    return calc(0, 0, e);
}

bool calc(int i, int j, int e) {
    
}
