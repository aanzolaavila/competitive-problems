/* 573 - The Snail */
#include <cstdio>
using namespace std;

int main()
{
	float H, U, D, F, posicion;
	int dia;
	scanf("%f", &H);
	while( H )
	{
		dia = 1;
		posicion = 0.0;
		scanf("%f %f %f", &U, &D, &F);
		float perdido = U * (F/100.0);
		//printf("%f %f %f %f %f\n", H, U, D, F, perdido );
		while(0 <= posicion <= H)
		{
			if(U > 0)
				posicion += U;
			U -= perdido;

			//printf("%f %f %d\n", posicion, U, dia );

			if(posicion > H)
				break;

			posicion -= D;
			if(posicion < 0)
				break;
			dia++;
		}

		if(posicion > H)
			printf("success ");
		else
			printf("failure ");

		printf("on day %d\n", dia);
		scanf("%f", &H);
	}

	return 0;
}