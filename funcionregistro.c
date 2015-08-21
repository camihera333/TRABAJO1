#include "funcionregistro.h"

void mostrarregistros(uint32_t *registros, size_t t)
{
	int i;

	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	if(!registros)
		return;

	for(i=0; i<t; i++)
	{
		if( (i % 4) == 0 )
			printf("\n");
        //else
		SetConsoleTextAttribute(hCon,PURPLE);
		printf("R%-2d:", i);
		SetConsoleTextAttribute(hCon,GREEN);
		printf("%.8X\t", registros[i]);
	}
	printf("\n");

	return;
}

