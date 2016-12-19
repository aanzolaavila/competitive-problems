#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x; it < y; ++it)
#define LEN 90

using namespace std;

char txt[LEN];

int calc() {
    int len = strlen(txt);
    int i, c = 0, sum = 0;
    loop(i, 0, len) {
	if (txt[i] == 'O')
	    sum += ++c;
	else
	    c = 0;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d\n", &n);
    int i;
    loop(i, 0, n) {
	scanf("%s\n", txt);
	printf("%d\n", calc());
    }

    return 0;
}
	
