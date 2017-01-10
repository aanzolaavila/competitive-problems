#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 25
#define INF 1000000000

using namespace std;

char word[SZ];
map<char, char> rev;

const char * strs[] = {
    " -- is not a palindrome.",
    " -- is a regular palindrome.",
    " -- is a mirrored string.",
    " -- is a mirrored palindrome."
};

int palindrome() {
    int p = 3, len = strlen(word)-1;
    
    for(int i = 0; i <= len/2 && p; i++) {
	//printf("DEB : %c, %c\n", word[i], word[len-i-1]);
	p &= ~( (word[i] != word[len-i-1]) << 0 ); // palindrome
	p &= ~( (rev.count(word[i]) ? rev[word[i]] != word[len-i-1] : 1) << 1 ); // mirrored
	//printf("NUM: %d\n", p);
    }

    word[len] = '\0';

    return p;
}

inline void add(char k, char v) {
    rev[k] = v;
    if (k != v)
	rev[v] = k;
}

void addall() {
    const char * c = "AEHIJMOSTUVWXYZ18";
    const char * r = "A3HILMO2TUVWXY518";

    while(*c != '\0') {
	add(*c++, *r++);
    }
}

int main() {
    addall();
    /*typedef map<char, char>::iterator it;
    for(it i = rev.begin(); i != rev.end(); i++) {
	printf("%c -> %c\n", i->first, i->second);
    }
    */
    
    int p;
    while(fgets(word, SZ, stdin) != NULL) {
	printf("%s%s\n\n", word, strs[palindrome()]);
    }

    return 0;
}
