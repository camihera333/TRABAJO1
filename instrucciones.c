#include "funcionregistro.h"
#include "instrucciones.h"
#include "funcBanderas.h"
#include <stdint.h>

 void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //suma
{
    *(Rdr+0)=*(Registros+Rn)+*(Registros+Rm);
}


void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //AND bit a bit
{
    *(Rdr+1)=*(Registros+Rn)&*(Registros+Rm);
}


void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //or exclusiva bit a bit
{
    *(Rdr+2)=*(Registros+Rn)^*(Registros+Rm);
}


void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //or lógica bit a bit
{
    *(Rdr+3)=*(Registros+Rn)|*(Registros+Rm);
}


void SUB (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // resta
{
    *(Rdr+4)=*(Registros+Rn)-*(Registros+Rm);
}


void MUL (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //multiplica
{
    *(Rdr+5)=(*(Registros+Rm))*(*(Registros+Rn));

}


void BIC (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //and entre un registro y el complemento de otro
{
    *(Rdr+6)=(*(Registros+Rn))&(~*(Registros+Rm));
}


void LSL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //desplazamiento lógico a la izquierda
{
    *(Rdr+7)=*(Registros+Rn)<<*(Registros+Rm);
}


void LSR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //desplazamiento lógico a la derecha
{
    *(Rdr+8)=*(Registros+Rn)>>*(Registros+Rm);
}

void SBC (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // resta con carry
{
    *(Rdr+9)=~*(Registros+Rn);
    *(Rdr+9)=*(Rdr+9)-1;
    *(Rdr+9)=*(Rdr+9)+*(Registros+Rm);
}

void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // escribe un valor en un registro
{
    *(Rdr+10)=*(Registros+Rm);
}

void MVN (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // guarda el complemento del registro
{
      *(Rdr+11)=~*(Registros+Rm);
}

void RSB (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // obtiene el complemento a dos de un número
{
    *(Rdr+12)=~*(Registros+Rm);
    *(Rdr+12)=*(Rdr+12)-1;
    *(Rdr+12)=*(Registros+Rm);
}

void ASR(uint32_t Rn,uint32_t Rm,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas) // desplazamiento aritmético a la derecha
{
    int help,i;
    uint32_t A=0;
    help=32-Rn;
    for(i=0;i<32;i++)
    {
        if((i>=0)&&(i<=Rn))
            A=A|(1<<i);
    }

    *(Rdr+13)=(help<<help)|(*(registros+Rn)>>Rm);
    *(Rdr+13)=*(registros+Rn);
}

void CMN (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t * Registros, uint32_t* Banderas) // suma pero no guarda el resultado, sólo modifica banderas
{
    int aux=0;
    aux=*(Registros+Rn)+*(Registros+Rm);
}

void CMP (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)  // resta pero no guarda el resultado, sólo modifica banderas
{
    int aux=0;
    aux=*(Registros+Rn)-*(Registros+Rm);
}

void TST (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // and bit a bit pero no guarda el resultado, sólo modifica banderas
{
    int aux=0;
    aux=*(Registros+Rn)&*(Registros+Rm);
}

void NOP () //no hace nada
{
}

//las funciones ALU que vienen a continuación requieren un procedimiento individual para la
//realización de las banderas por lo que no se pone dicho procedimiento dento de cada una de las funciones


void REV(uint32_t Rm,uint32_t* Rdr,uint32_t* registros, uint32_t* Banderas) // cambia el orden de los bits
{
    uint32_t help[4],A[4]={0,0,0,0};
    int i=0;
    for(i=0;i<32;i++)
    {
        if((i<8)&&(i>=0))
        {
          A[0]=(A[0]|1<<i);
        }
        if((i<16)&&(i>=8))
        {
          A[1]=(A[1]|1<<i);
        }
        if((i<24)&&(i>=16))
        {
          A[2]=(A[2]|1<<i);
        }
        if((i<32)&&(i>=24))
        {
          A[3]=(A[3]|1<<i);
        }
    }
    help[0]=(*(registros+Rm)&A[0]);
    help[1]=(*(registros+Rm)&A[1]);
    help[2]=(*(registros+Rm)&A[2]);
    help[3]=(*(registros+Rm)&A[3]);
    *(Rdr+17)=((help[0]<<24)|(help[1]<<16)|(help[2]>>8)|(help[3]>>24));

    *(Rdr+17)=*(registros+Rm);
    if(((1<<7)&*(Rdr+17))==(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+17)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=(2^32)/2)&(*(Rdr+17)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+17)>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void REV16(uint32_t Rm,uint32_t* Rdr,uint32_t* registros,uint32_t* Banderas) //cambia el orden de los bits en cada 16 bits
{
    uint32_t help[2],A[2]={0,0};
    int i=0;
    for(i=0;i<32;i++)
    {
        if((i<18)&&(i>=0))
        {
          A[0]=(A[0]|1<<i);
        }
        if((i<32)&&(i>=16))
        {
          A[1]=(A[1]|1<<i);
        }
    }
    help[0]=(*(registros+Rm)&A[0]);
    help[1]=(*(registros+Rm)&A[1]);
    *(Rdr+18)=((help[0]<<16)|(help[1]>>16));
    *(Rdr+18)=*(registros+Rm);
    if(((1<<7)&*(Rdr+18))==(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+18)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=(2^32)/2)&(*(Rdr+18)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+18)>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void REVSH(uint32_t Rm,uint32_t* Rdr,uint32_t* registros, uint32_t* Banderas) //cambia el orden de los bits del halfword bajo
{
    uint32_t help,A[2]={0,0},total=0;
    int i=0;
    for(i=8;i<32;i++)
    {
       if ((i>=8)&&(i<16))
       A[0]=(A[0]|1<<i);
       if ((i>=8)&&(i<32))
       A[1]=(A[1]|1<<i);
    }
    help=(*(registros+Rm)&A[0]);
    total=(help>>8);
    if (total>=(2^32)/2)
    {*(Rdr+19)=A[1]|total;}
    else
    {*(Rdr+19)=A[1];}
    *(Rdr+19)=*(registros+Rm);
    if(((1<<7)&*(Rdr+19))==(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+19)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=(2^32)/2)&(*(Rdr+19)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+19)>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}


void ROR(uint32_t Rn,uint32_t Rm,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas) //Rotación a la derecha

{
    int help,i;
    uint32_t A=0,help2;
    help=32-Rn;
    for(i=0;i<32;i++)
    {
        if((i>=0)&&(i<=Rn))
            A=A|(1<<i);
    }
    help2=*(registros+Rm)&A;
    *(Rdr+20)=(help2<<help)|(*(registros+Rm)>>Rn);

    *(Rdr+20)=*(registros+Rm);
    if(((1<<7)&*(Rdr+20))==(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+20)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=(2^32)/2)&(*(Rdr+20)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+20)>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}




void ADC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //suma con carry
{
    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=(2^32)){
    *(Banderas+2)=1;
    *(Rdr+21)=c+1;
    }
    else {
        *(Banderas+2)=0;
        *(Rdr+21)=c;
    }

    if(((1<<7)&*(Rdr+21))==(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+21)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

        c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=(2^32)/2)&(Rm>=(2^32)/2))&(*(Rdr+21)<(2^32)/2)) |(((Rn<(2^32)/2)&(Rm<(2^32)/2))&(*(Rdr+21)>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}
