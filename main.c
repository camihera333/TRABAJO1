#include <stdio.h>
#include <stdlib.h>
#include "funcionregistro.h"
#include "colors.h"
#include "instrucciones.h"
main()
{
    uint32_t registros[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	mostrarregistros(registros, 13);
	return 0;
    long int Rdr[6];
    long int Rn,Rm;
    Rdr[0]=ADD(Rn,Rm);
    Rdr[1]=AND(Rn,Rm);
    Rdr[2]=EOR(Rn,Rm);
    Rdr[3]=MOV(Rm);
    Rdr[4]=ORR(Rn,Rm);
    Rdr[5]=SUB(Rn,Rm);




}
