#include <bits/stdc++.h>
#define loop(i, x, y) for(i = x; i < y; ++i)
#define SZ 2000010
#define INF 10000000
using namespace std;

int m, l;
char line[SZ];

void calc() {
    if (strchr(line, 'Z') != NULL) {
	m = 0; return; }
	
    int i, j;
    loop(i, 0, l) {
	if (line[i] == 'R') {
	    loop(j, i+1, l) {
		if (line[j] == 'D') {
		    m = j-i < m? j-i : m;
		    break;
		}
	    }

	    for(j = i-1; j >= 0; --j) {
		if (line[j] == 'D') {
		    m = i-j < m? i-j : m;
		    break;
		}
	    }
	}
    }
}

int main() {
    while(scanf("%d", &l), l) {
	m = INF;
	scanf("%s", line);
	calc();
	printf("%d\n", m);
    }

    return 0;
}
