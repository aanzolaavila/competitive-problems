#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int l, w, h;
    
    for(int i = 0; i < n; i++) {
	scanf("%d%d%d", &l, &w, &h);
	printf("Case %d: %s\n", i+1, (l <= 20 && w <= 20 && h <= 20 ? "good" : "bad"));
    }

    return 0;
}
