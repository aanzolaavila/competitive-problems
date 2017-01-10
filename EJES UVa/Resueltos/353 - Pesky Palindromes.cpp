#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 100
#define INF 1000000000

using namespace std;

char word[SZ];

bool isPalindrome(string &c) {
    bool p = true;
    for(int i = 0; p && i <= c.size()/2; i++) {
	p &= c[i] == c[c.size()-i-1];
    }

    return p;
}

set<string> pals;
set<string> proc;

void count_palindromes(string &c) {
    if (c.size() >= 1) {
	if (proc.count(c) == 0) {
	    if (isPalindrome(c))
		pals.insert(c);
	    
	    proc.insert(c);
	    string tmp = c.substr(1, string::npos);
	    count_palindromes(tmp);
	    tmp = c.substr(0, c.size()-1);
	    count_palindromes(tmp);
	}
    }
}

int main() {
    string w;
    while(fgets(word, SZ, stdin) != NULL) {
	w = word;
	w.resize(w.size()-1); // \n
	pals.clear();
	proc.clear();
	count_palindromes(w);
	
	printf("The string \'%s\' contains %d palindromes.\n", w.c_str(), pals.size());
    }

    return 0;
}
