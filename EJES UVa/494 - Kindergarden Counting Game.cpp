#include <bits/stdc++.h>
#define SZ 1000000000

using namespace std;

char input[SZ];

inline bool is_letter(const char &l) {
    return ('a' <= l && l <= 'z') || ('A' <= l && l <= 'Z');
}

inline bool valid(char * tok) {
    int i = 0;
    bool v = false;
    while( !(v = is_letter(tok[i])) && tok[i] != '\0') ++i;
    return v;
}

int main() {
    int c, j;
    char * token;
    char separators[100] = "";

    j = 0;
    for(char i = ' '; i <= '~'; ++i) {
	if (!is_letter(i)) {
	    separators[j++] = i;
	    
	}
	//putchar(i);
    }
    separators[j] = '\0';

    //printf("%s\n", separators);
    
    while (fgets(input, SZ, stdin) != NULL) {
	c = 0;
	token = strtok(input, separators);
	do {
	    c += valid(token) ? 1 : 0;
	    token = strtok(NULL, separators);
	} while(token != NULL);
	printf("%d\n", c);
    }

    return 0;
}
