#include "funcBanderas.h"
#include "instrucciones.h"
#include "funcionregistro.h"


void funcBanderas (uint32_t*rd, uint32_t a, uint32_t b, uint32_t* Banderas)
{
	uint32_t c,v,ha,hb,hr;// declaracion de variables 
	ha=a&(1<<31);
	hb=b&(1<<31);
	hr=*rd&(1<<31);
	
    if(*rd>=(1<<31))

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posición 0 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posición 0 un 0 para usarlo en la parte gráfica

    if(*rd==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posición 1 un 0 para usarlo en la parte gráfica

    
	c=(ha&hb)|(ha&~(hr))|(~(hr)&hb);

    if(c>=1)
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posición 2 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posición 2 un 0 para usarlo en la parte gráfica

	v=(ha&hb&~(hr))|(~(ha)&~(hb)&hr);
    if(v>=1)
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 0 para usarlo en la parte gráfica

	return;
}

