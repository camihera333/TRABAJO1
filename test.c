#include <stdio.h>
#include <stdlib.h>

#include "funcionregistro.h"
#include "instrucciones.h"
#include <stdint.h>

#include "colors.h"
int main(void)
{
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[13]={0,1,2,0,0,0,0,0,0,0,0,0,0};
    uint32_t Rdr[23]={0};
    uint32_t Rn=1,Rm=2;
    uint32_t bitsRn[32],bitsRm[32];

	mostrarregistros(Rdr, 13);
    ADD(Rn,Rm,Rdr,registros,Banderas);
    AND(Rn,Rm,Rdr,registros,Banderas);
    EOR(Rn,Rm,Rdr,registros,Banderas);
    MOV(Rm,Rdr,registros,Banderas);
    ORR(Rn,Rm,Rdr,registros,Banderas);
    SUB(Rn,Rm,Rdr,registros,Banderas);
    MVN(Rm,Rdr,registros,Banderas);
    RSB(Rm,Rdr,registros,Banderas);
    MUL(Rn,Rm,Rdr,registros,Banderas);
    BIC(Rn,Rm,Rdr,registros,Banderas);
    NOP();
    SBC(Rn,Rm,Rdr,registros,Banderas);
    CMN(Rn,Rm,Rdr,registros,Banderas);
    CMP(Rn,Rm,Rdr,registros,Banderas);
    LSL(Rn,Rm,Rdr,registros,Banderas);
    LSR(Rn,Rm,Rdr,registros,Banderas);
    REV(Rm,Rdr,registros,Banderas);
    REV16(Rm,Rdr,registros,Banderas);
    REVSH(Rm,Rdr,registros,Banderas);
    ROR(Rm,Rn,Rdr,registros,Banderas);
    ADC(Rn,Rm,Rdr,registros,Banderas);
    ASR(Rm,Rn,Rdr,registros,Banderas);
    TST(Rn,Rm,Rdr,registros,Banderas);


    int i;
    for(i=0;i<=22;i++)
    {
    mostraralu(Rdr,i);
    mostrarbanderas(Banderas,4);
    }

    return 0;
}
