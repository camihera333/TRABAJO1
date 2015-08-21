#include "funcionregistro.h"
long int registros(long int *direc)
{
    int i=0;
    printf(" El banco de registro de las primeras 13 posiciones en la memoria son:\n\n");
    for(i=0;i<=12;i++)
    {
        printf("R[%d]=",i+1);
        printf("%d\n",direc[i]);
    }

}
