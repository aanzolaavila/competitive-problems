#include <bits/stdc++.h>
#define SZ 100

using namespace std;

int main() {
    char s[SZ];
    int i = 1;
    while(scanf("%s", s), strcmp(s, "*")) {
	printf("Case %d: ", i++);
	if (strcmp("Hajj", s) == 0) {
	    printf("Hajj-e-Akbar\n");
	} else {
	    printf("Hajj-e-Asghar\n");
	}
    }

    return 0;
}
