#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define N 10

using namespace std;

int main() {
    int i, j, n, v, w;
    scanf("%d", &n);

    bool asc, desc;
    printf("Lumberjacks:\n");
    loop(i, 0, n) {
	asc = desc = true;

	scanf("%d", &v);
	loop(j, 0, N-1) {
	    scanf("%d", &w);
	    asc = asc && w >= v;
	    desc = desc && w <= v;
	    v = w;
	}

	printf("%s\n", asc || desc ? "Ordered" : "Unordered");
    }

    return 0;
}
