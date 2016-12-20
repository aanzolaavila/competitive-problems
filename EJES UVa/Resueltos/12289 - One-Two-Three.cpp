#include <bits/stdc++.h>
#define SZ 100
#define WS 3

using namespace std;

const char* dict[] = {"one", "two", "three"};
int nums[] = {1, 2, 3};

inline int f(char * s, const char * w) {
    int c = 0;
    while(*s != '\0' && *w != '\0') {
	if (*s++ == *w++)
	    ++c;
    }
    return c;
}

inline int number(char * s) {
    int i = 0;
    bool found = false;
    while(!found && i < WS) {
	if (f(s, dict[i]) >= strlen(s) -1) {
	    found = true;
	} else
	    ++i;
    }

    return nums[i];
}

int main() {
    
    int n;
    scanf("%d", &n);
    char s[SZ];
    for (int i = 0; i < n; i++) {
	scanf("%s", s);
	printf("%d\n", number(s));
    }

    return 0;
}
