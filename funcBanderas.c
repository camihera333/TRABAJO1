#include "funcBanderas.h"
#include "instrucciones.h"
#include "funcionregistro.h"

void funcBanderas (uint32_t Rn, uint32_t Rm, uint32_t Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    if(Rdr>=(2^32)/2)

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posici�n 0 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posici�n 0 un 0 para usarlo en la parte gr�fica

    if(Rdr==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posici�n 1 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posici�n 1 un 0 para usarlo en la parte gr�fica

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posici�n 2 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posici�n 2 un 0 para usarlo en la parte gr�fica

    if((((*(Registros+Rn)>=(2^32)/2)&(*(Registros+Rm)>=(2^32)/2))&(Rdr<(2^32)/2)) |(((*(Registros+Rn)<(2^32)/2)&(*(Registros+Rm)<(2^32)/2))&(Rdr>=(2^32)/2)))
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 0 para usarlo en la parte gr�fica

	return;
}

void funcBanderas1 (uint32_t Rn, uint32_t Rm, uint32_t Rdr, uint32_t* Registros, uint32_t* Banderas)
{
    if(((1<<7)&Rdr)==(2^32)/2)

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posici�n 0 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posici�n 0 un 0 para usarlo en la parte gr�fica

    if(Rdr==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posici�n 1 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posici�n 1 un 0 para usarlo en la parte gr�fica

    uint32_t c;
    c=*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posici�n 2 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posici�n 2 un 0 para usarlo en la parte gr�fica

    if(((Rm>=(2^32)/2)&(Rdr<(2^32)/2)) |(((Rm<(2^32)/2))&(Rdr>=(2^32)/2)))
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 0 para usarlo en la parte gr�fica

}

void funcBanderas2 (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas)
{
if(((1<<7)&aux)==(2^32)/2)

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posici�n 0 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posici�n 0 un 0 para usarlo en la parte gr�fica

    if(aux==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posici�n 1 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posici�n 1 un 0 para usarlo en la parte gr�fica

    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posici�n 2 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posici�n 2 un 0 para usarlo en la parte gr�fica

    if((((Rn>=(2^32)/2)&(Rm>=(2^32)/2))&(aux<(2^32)/2)) |(((Rn<(2^32)/2)&(Rm<(2^32)/2))&(aux>=(2^32)/2)))
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 0 para usarlo en la parte gr�fica

}

