#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 200
#define N 10010
#define INF 10000000000

using namespace std;

typedef long long ll;

int p, v, e;

ll mem[N][N];

//string p_name[N];
int p_e[N];
int p_a[N];
map<string, int> ids;
bool can[N][N];
//set<string> v_power[N];
int v_def[N];

/*ll batman(int i, int j) {
    ll &mi = mem[i][j];
    if (mi != -1) return mi;
    if (j == v) return mi = 0;
    if (i == p && j < v) return mi = INF;

    return mi = (v_power[j].count(p_name[i]) != 0 && p_a[i] >= v_def[j]) ?
	min(p_e[i] + batman(i+1, j+1), batman(i+1, j)) : batman(i+1, j);
	}*/

ll batman() {
    int i, j;

    loop(i, 0, p+1) {
	mem[i][v] = 0;
    }

    loop(i, 0, v) {
	mem[p][i] = INF;
    }

    for(i = p-1; i >= 0; i--) {
	for (j = v-1; j >= 0; j--) {
	    if (can[i][j] && p_a[i] >= v_def[j]) {
		mem[i][j] = min(p_e[i] + mem[i+1][j+1], mem[i+1][j]);
	    } else {
		mem[i][j] = mem[i+1][j];
	    }
	}
    }

    return mem[0][0];
    
}

int main() {
    char in[SZ];
    char name[SZ];
    char * t;
    int i, j;
    while(scanf("%d %d %d\n", &p, &v, &e), p|v|e) {
	ids.clear();
	
	loop(i, 0, p+2) {
	    loop(j, 0, v+2) {
		can[i][j] = false;
	    }
	}
	
	loop(i, 0, p) {
	    scanf("%s %d %d\n", in, p_a+i, p_e+i);
	    //printf("%s\n", in);
	    //p_name[i] = in;
	    ids[in] = i;
	}

	loop(i, 0, v) {
	    scanf("%*s %d %s\n", v_def+i, in);
	    //v_power[i].clear();
	    int n = strlen(in);
	    loop(j, 0, n) {
		if (in[j] == ',') in[j] = ' ';
	    }

	    istringstream is(in);
	    while(is >> name) {
		//v_power[i].insert(name);
		can[ids[name]][i] = true;
	    }
	}

	/*loop(i, 0, p+2) {
	    loop(j, 0, v+2) {
		mem[i][j] = -1;
	    }
	    }*/

	printf("%s\n", batman() <= e ? "Yes": "No");

	/*loop(i, 0, p+1) {
	    loop(j, 0, v+1) {
		printf("%d ", mem[i][j]);
	    }
	    puts("");
	    }*/
    }

    return 0;
}
