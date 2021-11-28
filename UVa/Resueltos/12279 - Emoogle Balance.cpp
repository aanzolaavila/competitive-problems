#include <cstdio>
using namespace std;

int main()
{
    int caso = 1;
    bool finalizado = false;
    while(!finalizado)
    {
        int balance = 0;
        int c;
        scanf("%d", &c);
        if(c == 0)
        {
            finalizado = true;
            continue;
        }

        for (int i = 0; i < c; ++i)
        {
            int n;
            scanf("%d", &n);
            if(n > 0)
                balance++;
            else
                balance--;
        }

        printf("Case %d: %d\n",caso++, balance);
    }

    return 0;
}