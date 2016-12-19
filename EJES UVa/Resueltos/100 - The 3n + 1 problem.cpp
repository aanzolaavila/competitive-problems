#include <cstdio>
using namespace std;

int cycle_length(int n)
{
    int m = 1;
    while (n > 1)
    {
        if (n % 2)
            n = 3*n +1;
        else
            n /= 2;
        m++;
    }

    return m;
}

int mayor(int i, int j)
{
    int m = cycle_length(i++);
    int actual;
    for(;i <= j; i++)
        if((actual = cycle_length(i)) > m)
            m = actual;

    return m;
}

int main()
{
    int i, j;
    while(scanf("%i %i", &i, &j) != EOF)
    {
        printf("%i %i %i\n", i, j, mayor((i<j? i:j), (i>j? i:j)));
    }
    return 0;
}