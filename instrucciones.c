#include "funcionregistro.h"
#include "instrucciones.h"
#include <stdint.h>


void convbits (uint32_t Rn, uint32_t Rm, uint32_t* Registros, uint32_t* bitsRn, uint32_t* bitsRm) //función para convertir decimal a bits, guardando el resultado en un arreglo.
{
    int i;
    for(i=31;i>=0;i--)
    {
     bitsRn[i]=*(Registros+Rn)%2;
    *(Registros+Rn)=(*(Registros+Rn))/2;
    }
        for(i=0;i<=31;i++)
    {
        printf("%d",bitsRn[i]);
    }

printf("\n\n");


    for(i=31;i>=0;i--)
    {
     bitsRm[i]=*(Registros+Rm)%2;
    *(Registros+Rm)=(*(Registros+Rm))/2;
    }
    for(i=0;i<=31;i++)
    {
        printf("%d",bitsRm[i]);
    }
}

 void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //suma
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

}

void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //AND bit a bit 
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

}

void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //or exclusiva bit a bit
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

}

void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // escribe un valor en un registro
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

}

void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //or lógica bit a bit
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
}

void SUB (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // resta
{
    *(Rdr+5)=*(Registros+Rn)-*(Registros+Rm);
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
}

void MVN (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // guarda el complemento del registro
{
      *(Rdr+6)=~*(Registros+Rm);

    if(((1<<7)&*(Rdr+6))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+6)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+6)<128)) |(((Rm<128))&(*(Rdr+6)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void RSB (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // obtiene el complemento a dos de un número
{
    *(Rdr+7)=~*(Registros+Rm);
    *(Rdr+7)=*(Rdr+7)-1;
    *(Rdr+3)=*(Registros+Rm);
    if(((1<<7)&*(Rdr+7))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+7)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+7)<128)) |(((Rm<128))&(*(Rdr+7)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}
void MUL (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //multiplica
{
    *(Rdr+8)=(*(Registros+Rm))*(*(Registros+Rn));

     if(((1<<7)&*(Rdr+8))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+8)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+8)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+8)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void BIC (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //and entre un registro y el complemento de otro
{
    *(Rdr+9)=(*(Registros+Rn))&(~*(Registros+Rm));
    if(((1<<7)&*(Rdr+9))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+9)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+9)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+9)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void NOP () //no hace nada
{
}

void SBC (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // resta con carry
{
    *(Rdr+10)=~*(Registros+Rn);
    *(Rdr+10)=*(Rdr+10)-1;
    *(Rdr+10)=*(Rdr+10)+*(Registros+Rm);
    if(((1<<7)&*(Rdr+10))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+10)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+10)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+10)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void CMN (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // suma pero no guarda el resultado, sólo modifica banderas
{
    int aux=0;
    aux=*(Registros+Rn)+*(Registros+Rm);

    if(((1<<7)&aux)==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(aux==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(aux<128)) |(((Rn<128)&(Rm<128))&(aux>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}

void CMP (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas)  // resta pero no guarda el resultado, sólo modifica banderas
{
    int aux1=0;
    aux1=*(Registros+Rn)-*(Registros+Rm);

    if(((1<<7)&aux1)==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(aux1==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(aux1<128)) |(((Rn<128)&(Rm<128))&(aux1>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}

void LSL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //desplazamiento lógico a la izquierda
{
    *(Rdr+12)=*(Registros+Rn)<<*(Registros+Rm);

    if(((1<<7)&*(Rdr+12))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+13)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+12)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+12)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}
void TST (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // and bit a bit pero no guarda el resultado, sólo modifica banderas
{
    int aux=0;
    aux=*(Registros+Rn)&*(Registros+Rm);

    if(((1<<7)&aux)==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(aux==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(aux<128)) |(((Rn<128)&(Rm<128))&(aux>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}

void LSR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //desplazamiento lógico a la derecha
{
    *(Rdr+14)=*(Registros+Rn)>>*(Registros+Rm);

    if(((1<<7)&*(Rdr+14))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+14)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+14)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+14)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}
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
    *(Rdr+15)=((help[0]<<24)|(help[1]<<16)|(help[2]>>8)|(help[3]>>24));

    *(Rdr+15)=*(registros+Rm);
    if(((1<<7)&*(Rdr+15))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+15)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+15)<128)) |(((Rm<128))&(*(Rdr+15)>=128)))
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
        if((i<16)&&(i>=0))
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
    *(Rdr+16)=((help[0]<<16)|(help[1]>>16));
    *(Rdr+16)=*(registros+Rm);
    if(((1<<7)&*(Rdr+16))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+16)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+16)<128)) |(((Rm<128))&(*(Rdr+16)>=128)))
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
    if (total>=128)
    {*(Rdr+17)=A[1]|total;}
    else
    {*(Rdr+17)=A[1];}
    *(Rdr+17)=*(registros+Rm);
    if(((1<<7)&*(Rdr+17))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+17)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+17)<128)) |(((Rm<128))&(*(Rdr+17)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void ROR(uint32_t Rm,uint32_t Rn,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas) //Rotación a la derecha
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
    *(Rdr+18)=(help2<<help)|(*(registros+Rm)>>Rn);

    *(Rdr+18)=*(registros+Rm);
    if(((1<<7)&*(Rdr+18))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+18)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+18)<128)) |(((Rm<128))&(*(Rdr+18)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
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

    *(Rdr+19)=(help<<help)|(*(registros+Rn)>>Rm);
    *(Rdr+19)=*(registros+Rn);

    if(((1<<7)&*(Rdr+19))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+19)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=128)&(*(Rdr+19)<128)) |(((Rm<128))&(*(Rdr+19)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}

void ADC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //suma con carry
{
    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255){
    *(Banderas+2)=1;
    *(Rdr+19)=c+1;
    }
    else {
        *(Banderas+2)=0;
        *(Rdr+19)=c;
    }

    if(((1<<7)&*(Rdr+19))==128)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(*(Rdr+19)==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

        c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=255)
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=128)&(Rm>=128))&(*(Rdr+19)<128)) |(((Rn<128)&(Rm<128))&(*(Rdr+19)>=128)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;
}


