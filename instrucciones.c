
#include "instrucciones.h"
#include <stdint.h>


 void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    *(Rdr+0)=*(Registros+Rn)+*(Registros+Rm);
    if(((1<<7)&*(Rdr+0))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+0)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+0)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+0)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

    mostraralu(Rdr,0);
    mostrarbanderas(Banderas,4);
}



void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    *(Rdr+1)=*(Registros+Rn)&*(Registros+Rm);
    if(((1<<7)&*(Rdr+1))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+1)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+1)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+1)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

    mostraralu(Rdr,1);
    mostrarbanderas(Banderas,4);
}

void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    *(Rdr+2)=*(Registros+Rn)^*(Registros+Rm);
   if(((1<<7)&*(Rdr+2))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+2)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+2)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+2)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

    mostraralu(Rdr,2);
    mostrarbanderas(Banderas,4);
}

void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    *(Rdr+3)=*(Registros+Rm);
    if(((1<<7)&*(Rdr+3))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+3)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+3)<128)) |(((Rm<128))&(*(Rdr+3)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

    mostraralu(Rdr,3);
    mostrarbanderas(Banderas,4);
}

void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    *(Rdr+4)=*(Registros+Rn)|*(Registros+Rm);
   if(((1<<7)&*(Rdr+4))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+4)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+4)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+4)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

    mostraralu(Rdr,4);
    mostrarbanderas(Banderas,4);

}

void SUB (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    if(((1<<7)&*(Rdr+5))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+5)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+5)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+5)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

    mostraralu(Rdr,5);
    mostrarbanderas(Banderas,4);
}

