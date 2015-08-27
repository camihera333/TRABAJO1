#include "funcionregistro.h"

void mostrarregistros(uint32_t* registros, size_t t)
{
	int i;

	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	if(!registros)
		return;

	for(i=0; i<t; i++)
	{
		if( (i % 4) == 0 )
			printf("\n");
		SetConsoleTextAttribute(hCon,PURPLE);
		printf("R%-2d:", i);
		SetConsoleTextAttribute(hCon,YELLOW);
		printf("%d\t\t", registros[i]);
	}
	printf("\n");
	return;
}


void mostrarbanderas(uint32_t* banderas, size_t t)
{
	int i;

	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	for(i=0; i<t; i++)
	{
		if( (i % 4) == 0 )
            printf("\n");
        if(*(banderas+i)==1)
            {
          SetConsoleTextAttribute(hCon,GREEN);
		printf("    N\t\t");
            }
        else
        {
          SetConsoleTextAttribute(hCon,RED);
		printf("    N\t\t");
        }
	}
	SetConsoleTextAttribute(hCon,WHITE);
	printf("\n\n\n");

	return;

}

void mostraralu(uint32_t* Rdr, size_t t)
{
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);

          SetConsoleTextAttribute(hCon,WHITE);
		printf("\t\tEl %d valor ALU es:  %d\t\t",t+1,*(Rdr+t));


	SetConsoleTextAttribute(hCon,WHITE);
	printf("\n");

	return;

}
