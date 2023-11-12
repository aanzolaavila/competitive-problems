#include <cstdio>
using namespace std;

bool todos_iguales(char cadena[], int n, int m)
{
    for(int i = n+1; i <= m; i++)
        if(cadena[i] != cadena[n])
            return false;

    return true;
}

int main()
{
    char cadena[1000050];
    bool finalizado = false;
    int c = 1;
    while(!finalizado)
    {
        if(scanf("%s", cadena) == EOF /*|| cadena[0] == ''*/)
        {
            finalizado = true;
            continue;
        }

        int casos, i, j;
        scanf("%d", &casos);
        printf("Case %i:\n", c++);
        for (int k = 0; k < casos; ++k)
        {
            scanf("%d %d", &i, &j);
            printf("%s\n",(todos_iguales(cadena, (i<j ? i:j), (i>j? i : j))? "Yes": "No"));
        }
    }
    return 0;
}