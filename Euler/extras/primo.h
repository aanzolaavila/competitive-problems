#include <cmath>
using std::sqrt;

double raiz(double n)
{
    static unsigned double numero_anterior = 1.0;
    static unsigned double res = 1.0;
    
    if (n == numero_anterior)
        return res;
    
    return res = sqrt(numero_anterior = n);
}

bool primo( unsigned int numero )
{   
    static unsigned int numero_anterior = 2;
    static bool res = true;
    
    if(numero == numero_anterior)
        return res;
    
    if ( numero <= 1 ) 
       return false;
    
    int i = raiz( numero ) );
    
    while( i > 1 )
        if ( (numero % i--) == 0) 
        {
            numero_anterior = numero;
            return res = false;
        }    
    
    numero_anterior = numero;
    return res = true;
}