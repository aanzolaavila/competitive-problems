#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char palabra[16];
    int c = 1;
    bool finalizado = false;
    while(! finalizado)
    {
        scanf("%s", palabra);
        if(!strcmp(palabra, "#"))
        {
            finalizado = true;
            continue;
        }

        int caso = 0;

        if(!strcmp(palabra, "HELLO"))
            caso = 1;
        if(!strcmp(palabra, "HOLA"))
            caso = 2;
        if(!strcmp(palabra, "HALLO"))
            caso = 3;
        if(!strcmp(palabra, "BONJOUR"))
            caso = 4;
        if(!strcmp(palabra, "CIAO"))
            caso = 5;
        if(!strcmp(palabra, "ZDRAVSTVUJTE"))
            caso = 6;

        switch (caso)
        {
            case 1:
                printf("Case %d: ENGLISH\n", c++);
                break;
            case 2:
                printf("Case %d: SPANISH\n", c++);
                break;
            case 3:
                printf("Case %d: GERMAN\n", c++);
                break;
            case 4:
                printf("Case %d: FRENCH\n", c++);
                break;
            case 5:
                printf("Case %d: ITALIAN\n", c++);
                break;
            case 6:
                printf("Case %d: RUSSIAN\n", c++);
                break;
            default:
                printf("Case %d: UNKNOWN\n", c++);
                break;
        }
    }

    return 0;
}