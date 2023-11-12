#include <bits/stdc++.h>
#define SZ 100000

using namespace std;

int main() {
    bool state = true; // 1 = ``, 0 = ''
    char input[SZ];
    char * token = NULL;
    int len;
    
    while(fgets(input, SZ, stdin) != NULL) {
	len = strlen(input);
	for(int i = 0; i < len; ++i) {
	    if (input[i] == '\"') {
		printf("%s", state ? "``" : "''");
		state = ! state;
	    } else
		putchar(input[i]);
	}
    }

    return 0;
}
