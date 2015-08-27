#include <stdio.h>
#include <stdlib.h>

#include "funcionregistro.h"
#include "instrucciones.h"
#include <stdint.h>

int main(void)
{
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[13]={0,24,34,0,0,0,0,0,0,0,0,0,0};
    uint32_t Rdr[6];
    uint32_t Rn=1,Rm=2;
	mostrarregistros(registros, 13);
	printf("\n");


    ADD(Rn,Rm,Rdr,registros,Banderas);
    AND(Rn,Rm,Rdr,registros,Banderas);
    EOR(Rn,Rm,Rdr,registros,Banderas);
    MOV(Rm,Rdr,registros,Banderas);
    ORR(Rn,Rm,Rdr,registros,Banderas);
    SUB(Rn,Rm,Rdr,registros,Banderas);

    return 0;
}
