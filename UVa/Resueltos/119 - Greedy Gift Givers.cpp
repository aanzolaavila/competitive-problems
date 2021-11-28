#include <cstdio>
#include <cstring>
using std::strcmp;
using std::strcpy;

class hash
{
    public:
        hash();
        hash(char [], int);
        ~hash();
        int existe(char []) const;
        int valor(char []) const;
        int valor(int) const;
        char const * clave(int) const;
        int agregar(char []);
        int agregar(char [], int);
        bool modificar(char [], int);
        bool modificar(int, int);
        int tamanio() const {return cantidad;}
    private:
        const static unsigned int capacidad = 256;
        unsigned int cantidad = 0;
        char nombres[capacidad][capacidad];
        int valores[capacidad];
};

int hash::existe(char clave[]) const
{
    for(int i = 0; i < cantidad; i++)
        if(!strcmp(clave, nombres[i]))
            return i;

    return -1;
}

int hash::valor(char clave[]) const
{
    int pos = existe(clave);
    if(pos >=0)
        return valores[pos];
    return 0;
}

int hash::valor(int n) const
{
    return (0 <= n <= cantidad)? valores[n] : 0;
}

hash::hash()
{
    // No hace nada...
}

hash::hash(char clave[], int valor)
{
    cantidad = 1;
    strcpy(nombres[0], clave);
    valores[0] = valor;
}

hash::~hash()
{
    // No hace nada...
}

char const * hash::clave(int n) const
{
    return (0 <= n <= cantidad)? nombres[n] : NULL;
}

int hash::agregar(char clave[])
{
    int i;
    if(i = existe(clave) >= 0)
        return i;

    if(cantidad == capacidad)
        return -1;
    strcpy(nombres[cantidad], clave);
    valores[cantidad++] = 0;
    return cantidad-1;
}

int hash::agregar(char clave[], int valor)
{
    int i;
    if (i = existe(clave))
        return -1;

    if(cantidad == capacidad)
        return -1;
    strcpy(nombres[cantidad], clave);
    valores[cantidad] = valor;
    return cantidad++;
}

bool hash::modificar(char clave[], int valor)
{
    int i;
    if (i = existe(clave) >= 0)
    {
        valores[i] = valor;
        return true;
    }
    
    return false;
}

bool hash::modificar(int n, int valor)
{
    if (0 <= n < cantidad)
    {
        valores[n] = valor;
        return true;
    }

    return false;
}

/* ---------------------------------------------------*/
using namespace std;

int main()
{
    int np;
    bool ultima_linea = scanf("%d", &np) != EOF;
    while( ultima_linea )
    {
        char nombre[15];
        int valor, c;
        hash personas;

        for(int i = 0; i < np; i++)
        {
            scanf("%s", nombre);
            personas.agregar(nombre);
        }

        for (int i = 0; i < np; ++i)
        {
            scanf("%s %d %d", nombre, &valor, &c);
            int pos = personas.existe(nombre);
            if(c > 0)
                personas.modificar(pos, personas.valor(pos) - valor + (valor % (c > 0? c:1)));
            for (int j = 0; j < c; ++j)
            {
                scanf("%s", nombre);
                pos = personas.existe(nombre);
                personas.modificar(pos, personas.valor(pos)+(valor/c));
            }
        }

        for (int i = 0; i < np; ++i)
            printf("%s %d\n", personas.clave(i), personas.valor(i) );
        
        if(ultima_linea = scanf("%d", &np) != EOF)
            printf("\n");
    }

    return 0;
}