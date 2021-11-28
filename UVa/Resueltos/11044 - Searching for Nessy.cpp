#include <cstdio>
using namespace std;

int balizas(int n, int m)
{
    int x = (int)(n/3) + ((n % 3 > 0)? 1:0);
    return ((int)(m/3) + ((m % 3 > 0)? 1:0))*x;
}

int main()
{
    int casos, n, m;
    scanf("%d", &casos);
    for(int i = 0; i < casos ; i++)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", balizas(n-2,m-2));
    }
}