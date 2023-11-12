#include <bits/stdc++.h>
#define SZ 256
#define loop(i, a, b) for(i = a; i < b ; i++)

using namespace std;

char in[SZ];

bool valid() {
    stack<char> s;
    char *ptr = in;
    bool valid = true;
    while(*ptr != '\0' && valid) {
        switch(*ptr) {
	case '(':
	case '[':
	    s.push(*ptr);
	    break;
	case ']':
	case ')':
	    if (valid &= !s.empty()) {
		if (*ptr == ']') {
		    valid &= s.top() == '[';
		} else if (*ptr == ')') {
		    valid &= s.top() == '(';
		}
		s.pop();
	    }
	    break;
	}

	// printf("%c(%c)", *ptr, s.top());
	// printf("%c(%c)", 'a', 'b');
	ptr++;
    }

    // printf("\n");

    return s.empty() && valid;
}

int main() {
    int n;
    scanf("%d\n", &n);

    while(n--) {
	fgets(in, SZ, stdin);
	// puts(in);
	printf("%s\n", valid() ? "Yes" : "No");
    }

    return 0;
}
