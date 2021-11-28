#include <bits/stdc++.h>
#define range(n, x, y) ( x <= n && n <= y )
#define SZ 500000
using namespace std;

typedef set<string>::iterator it;

char a;

inline bool valid() {
    if ( range(a, 'A', 'Z') ) {
	a |= (1<<5);
	return true;
    }
    return range(a, 'a', 'z') || a == ' ';
}

int main() {
    char in[SZ] = "";
    int i = 0;
    while( (a = getchar()) != EOF ) {
	in[i++] = valid() ? a : ' ';
    }
    in[i] = '\0';

    set<string> m;

    m.insert(string(strtok(in, " ")));
    char * word;
    while( (word = strtok(NULL, " ")) != NULL ) {
	m.insert(string(word));
    }

    for(it i = m.begin(); i != m.end(); ++i) {
	cout << *i << '\n';
    }

    return 0;
}
