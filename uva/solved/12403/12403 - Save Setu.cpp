#include <bits/stdc++.h>
#define SZ 1000

using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);

    long long int s = 0;
    char str[SZ];
    int d = 0;
    for(int i = 0; i < t; i++) {
	fgets(str, SZ, stdin);
	//scanf("%s\n", str);
	if( strcmp("donate", strtok(str, " ")) == 0 ) {
	    sscanf(strtok(NULL, " "), "%d", &d);
	    s += d;
	} else {
	    printf("%ld\n", s);
	}
    }

    return 0;
}
