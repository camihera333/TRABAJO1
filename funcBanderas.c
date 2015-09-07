#include "funcBanderas.h"
#include "instrucciones.h"
#include "funcionregistro.h"

void funcBanderas (uint32_t Rn, uint32_t Rm, uint32_t Rdr, uint32_t* Registros, uint32_t* Banderas) /*uint32_t registros : puntero a la primera direccion...
                                                                                             del arreglo, size_t t tamaño de arreglo*/
{
    if(Rdr>=(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(Rdr==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((*(Registros+Rn)>=(2^32)/2)&(*(Registros+Rm)>=(2^32)/2))&(Rdr<(2^32)/2)) |(((*(Registros+Rn)<(2^32)/2)&(*(Registros+Rm)<(2^32)/2))&(Rdr>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

	return;
}

void funcBanderas1 (uint32_t Rn, uint32_t Rm, uint32_t Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    if(((1<<7)&Rdr)==(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(Rdr==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if(((Rm>=(2^32)/2)&(Rdr<(2^32)/2)) |(((Rm<(2^32)/2))&(Rdr>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}

void funcBanderas2 (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas)
{
if(((1<<7)&aux)==(2^32)/2)

        *(Banderas+0)=1;
    else
        *(Banderas+0)=0;

    if(aux==0)

        *(Banderas+1)=1;
    else
        *(Banderas+1)=0;

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=(2^32)/2)&(Rm>=(2^32)/2))&(aux<(2^32)/2)) |(((Rn<(2^32)/2)&(Rm<(2^32)/2))&(aux>=(2^32)/2)))
     *(Banderas+3)=1;
    else
        *(Banderas+3)=0;

}

