#include <bits/stdc++.h>
#define loop(i,ii, ff) for(i = ii; i < ff ; ++i)
#define SZ 1000000

using namespace std;

char str[SZ];
char r;

void calc() {
    int n = strlen(str);
    int i;
    if ( !strcmp(str, "1") || !strcmp(str, "4") || !strcmp(str, "78") ) {
	r = '+';
    } else if (!strcmp(str+n-2, "35")) {
	r = '-';
    } else if (str[0] == '9' && str[n-1] == '4') {
	r = '*';
    } else if (str[0] == '1' && str[1] == '9' && str[2] == '0') {
	r = '?';
    } else
	r = '?';
}

int main() {
    int n, i;
    scanf("%d", &n);
    loop(i, 0, n){
	scanf("%s", str);
	calc();
	printf("%c\n", r);
    }
    return 0;
}
