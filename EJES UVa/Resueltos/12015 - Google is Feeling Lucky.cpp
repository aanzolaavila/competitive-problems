#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define SZ 15
#define N 10
#define INF 1000000000

using namespace std;

char s[SZ][100];
int v[SZ];

int main() {
    int i, j, t;
    scanf("%d", &t);

    int max;
    loop(i, 0, t) {
	max = -INF;

	loop(j, 0, N) {
	    scanf("%s %d", &s[j], &v[j]);
	    max = max < v[j] ? v[j] : max;
	}

	printf("Case #%d:\n", i+1);
	loop(j, 0, N) {
	    if (v[j] == max) {
		printf("%s\n", s[j]);
	    }
	}
    }

    return 0;
}
