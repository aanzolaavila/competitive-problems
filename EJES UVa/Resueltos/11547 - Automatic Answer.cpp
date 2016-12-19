#include <cstdio>
using namespace std;

int main()
{
    int c, n;
    scanf("%d", &c);
    for(int i = 0; i < c; i++)
    {
        scanf("%d",&n);
        n = ((((((n*567)/9)+7492)*235)/47)-498);
        n = ((n % 100) - (n % 10))/10;
        printf("%d\n", (n>0)? n: -n );
    }

    return 0;
}