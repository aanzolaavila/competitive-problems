#include <cstdio>
#include <cstring>

#define SZ 101

using namespace std;

int main() {
    char s[SZ];
    char t[SZ];

    scanf("%s", s);
    scanf("%s", t);

    int ls = strlen(s);
    int lt = strlen(t);

    bool r = ls == lt;

    for(int i = 0; i < lt && r ; ++i) {
	if ( t[i] != s[ls-i-1] )
	    r = false;
    }

    printf("%s\n", r ? "YES" : "NO");

    return 0;
}
