#include "funcBanderas.h"
#include "instrucciones.h"
#include "funcionregistro.h"


void funcBanderas (uint32_t*rd, uint32_t a, uint32_t b, uint32_t* Banderas)
{
	uint32_t c,v,ha,hb,hr;
	ha=a&(1<<31); //para sacar el bit m�s significativo
	hb=b&(1<<31); //para sacar el bit m�s significativo
	hr=*rd&(1<<31); //para sacar el bit m�s significativo
	
    if(*rd>=(1<<31))

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posici�n 0 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posici�n 0 un 0 para usarlo en la parte gr�fica

    if(*rd==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posici�n 1 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posici�n 1 un 0 para usarlo en la parte gr�fica

   
	c=(ha&&hb)||((!ha)&&(hb)&&(!hr))||(ha&&(!hb)&&(!hr)); //F�rmula para hallar el carry en este caso

    if(c)
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posici�n 2 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posici�n 2 un 0 para usarlo en la parte gr�fica

	v=(ha&&hb&&(!hr))||((!ha)&&(!hb)&&hr); //F�rmula para hallar el sobreflujo en este caso
    if(v)
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 0 para usarlo en la parte gr�fica

	return;
}

void funcBanderas2 (uint32_t*rd, uint32_t a, uint32_t* Banderas)
{
	uint32_t c,v,ha;
	ha=a&(1<<31); //M�scara para sacar el bit m�s significativo
	
    if(*rd>=(1<<31))

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posici�n 0 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posici�n 0 un 0 para usarlo en la parte gr�fica

    if(*rd==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posici�n 1 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posici�n 1 un 0 para usarlo en la parte gr�fica

    
	c=ha;

    if(c>=1)
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posici�n 2 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posici�n 2 un 0 para usarlo en la parte gr�fica

	v=(Banderas[0])^(Banderas[2]); //XOR entre la bandera negativa y la bandera de carry
    if(v>=1) 
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 1 para usarlo en la parte gr�fica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posici�n 3 un 0 para usarlo en la parte gr�fica

	return;
}

