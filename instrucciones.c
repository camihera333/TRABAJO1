#include "funcionregistro.h"
#include "funcBanderas.h"
#include <stdint.h>


 void ADD (uint32_t* rd, uint32_t a, uint32_t b) //suma 
{
    *rd=a+b; //En la variable rd  se guarda el resultado de la suma de los valores a y b
}

void AND (uint32_t* rd, uint32_t a, uint32_t b) //AND bit a bit
{
    *rd=a&b; //En la variable rd  se guarda el resultado del AND de los valores a y b
}


void EOR (uint32_t* rd, uint32_t a, uint32_t b) //or exclusiva bit a bit
{
    *rd=a^b; //En la variable rd  se guarda el resultado de la EOR de los valores a y b
}


void ORR (uint32_t* rd, uint32_t a, uint32_t b)//or lógica bit a bit
{
    *rd=a|b;  //En la variable rd  se guarda el resultado de la ORR de los valores a y b
}

void SUB (uint32_t* rd, uint32_t a, uint32_t b) // resta
{
    *rd=a-b; //En la variable rd  se guarda el resultado de la resta de los valores a y b
}

void MUL (uint32_t* rd, uint32_t a, uint32_t b) //multiplicacion
{
    *rd=a*b; //En la variable rd  se guarda el resultado de la multiplicación de los valores a y b 
}

void BIC (uint32_t* rd, uint32_t a, uint32_t b)//and entre un registro y el complemento de otro
{
    *rd=a&(~b); //En la variable rd  se guarda el resultado del AND entre el valor a y el negado de b
}


void LSL (uint32_t* rd, uint32_t a, uint32_t b) //desplazamiento lógico a la izquierda
{
    *rd=a<<b;  //En la variable rd se guarda el resultado del desplazamiento lógico a la izquierda de los valores a y b
}


void LSR (uint32_t* rd, uint32_t a, uint32_t b) //desplazamiento lógico a la derecha
{
    *rd=a>>b;  //En la variable rd se guarda el resultado del desplazamiento lógico a la derecha de los valores a y b
}

void SBC (uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas) // resta con carry
{
    if(*(Banderas+2)==1) // condicional que expresa que si la bandera de carry está encendida, ingrese al if
		*rd=a-b-1; //guarda en rd la resta de a y b y se le resta un 1
	else
		*rd=a-b; //guarda en rd la resta de a y b
}

void ADC (uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas) // suma con carry
{
    if(*(Banderas+2)==1) // condicional que expresa que si la bandera de carry está encendida, ingrese al if
		*rd=a+b+1; //guarda en rd la resta de a y b y se le resta un 1
	else
		*rd=a+b; //guarda en rd la resta de a y b
}

void MOV(uint32_t* rd, uint32_t a) // Escribe un valor en un registro
{
    *rd=a; // guarda en la variable rd, el valor de a
}

void MVN (uint32_t* rd, uint32_t a) // Guarda el complemento de un valor
{
    *rd=~a; // guarda en la variable rd, el valor de a negado
}

void RSB (uint32_t* rd, uint32_t a) // Obtiene en complemento a dos de un valor
{
    *rd=~a+1; // guarda en la variable rd, el valor de a negado más un uno, para hacer el complemento a dos
}

void ROR(uint32_t* rd,uint32_t a,uint32_t b) // rotación a la derecha
{
    int i,j; //variables locales
    uint32_t A=0,help; //variables locales
	j=32-b; //auxiliar para saber en que posición quedan los valores corridos
    for(i=0;i<32;i++) //ciclo para hallar máscara
    {
        if((i>=0)&&(i<b)) //condicion para poner en 1 los bits movidos
            A=A|(1<<i);
    }
    help=a&A; //and del numero y la máscara para extraer los numeros corridos
    *rd=(help<<j)|(a>>b); //or entre los números extraidos (corridos j veces) y el valor inicial corrido b veces hacia la derecha
}

void NOP () //no hace nada
{
}

void CMN (uint32_t a, uint32_t b, uint32_t* Banderas) // suma pero no guarda el resultado, solo modifica banderas
{	
	uint32_t i; //variables locales
	i=a+b; //guarda en la variable local i, el valor de la suma entre a y b
	funcBanderas(&i,a,b,Banderas); //llama a la funcion funcBanderas, para modificar las banderas más no guarda el resultado
}


void CMP (uint32_t a, uint32_t b, uint32_t* Banderas) // resta pero no guarda el resultado, solo modifica banderas
{	
	uint32_t i; //variables locales
	i=a+(~b)+1; //guarda en la variable local i, el valor de la resta entre a y b
	funcBanderas(&i,a,((~b)+1),Banderas); //llama a la funcion funcBanderas, para modificar las banderas más no guarda el resultado
}

void TST (uint32_t a, uint32_t b, uint32_t* Banderas) // AND bit a bit pero no guarda el resultado, solo modifica banderas
{	
	uint32_t i; //variables locales
	i=a&b;//guarda en la variable local i, el valor de la AND entre a y b
	funcBanderas(&i,a,b,Banderas); //llama a la funcion funcBanderas, para modificar las banderas más no guarda el resultado
}


void ASR(uint32_t* rd,uint32_t a,uint32_t b) // desplazamiento aritmético a la derecha
{
    
    uint32_t j,i,k; //variables locales
	i=(1<<31)&a; //máscara para hallar el valor del bit 32
	k=~(1<<31)&a; //máscara para extraer el valor a desplazar negado 
	j=k>>b; //corre k b veces y lo guarda en j
	*rd=i|j; //guarda en rd el valor de la ORR entre i y j
}

void REV (uint32_t* rd,uint32_t a)  // cambia el orden de los bits
{
	int i; //variable local
	uint32_t mas1=0,mas2=0,mas3=0,mas4=0,h1,h2,h3,h4; //variables locales
	for (i=0; i<32;i++) // ciclo para recorrer cada bit
	{
		if ((i>=0)&&(i<8)) //condición para sólo operar con los bits del 0 al 7
		mas1=(1<<i)|mas1; //en máscara1 guarda los  bits del 0 al 7
	
		if ((i>=8)&&(i<16))//condición para sólo operar con los bits del 8 al 15
		mas2=(1<<i)|mas2; //en mas2 guarda los  bits del 8 al 15
	
		if ((i>=16)&&(i<24))//condición para sólo operar con los bits del 16 al 23
		mas3=(1<<i)|mas3; //en mas1 guarda los  bits del 16 al 23
	
		if ((i>=24)&&(i<32))//condición para sólo operar con los bits del 24 al 31
		mas4=(1<<i)|mas4; //en mas4 guarda los  bits del 24 al 31
	}
	h1=mas1&a;//en h1 guarda los  bits del 0 al 7
	h2=mas2&a;//en h2 guarda los  bits del 8 al 15
	h3=mas3&a;//en h3 guarda los  bits del 16 al 23
	h4=mas4&a;//en h4 guarda los  bits del 24 al 31
	
	*rd=(h1<<24)|(h2<<8)|(h3>>8)|(h4>>24); //En rd se guardan en el orden deseado los valores
	
}

void REV16 (uint32_t* rd,uint32_t a)  // cambia el orden de los bits
{
	int i; //variables local
	uint32_t mas1=0,mas2=0,mas3=0,mas4=0,h1,h2,h3,h4; //variables locales
	for (i=0; i<32;i++) // ciclo para recorrer cada bit
	{
		if ((i>=0)&&(i<8)) //condición para sólo operar con los bits del 0 al 7
		mas1=(1<<i)|mas1; //en máscara1 guarda los  bits del 0 al 7
	
		if ((i>=8)&&(i<16))//condición para sólo operar con los bits del 8 al 15
		mas2=(1<<i)|mas2; //en mas2 guarda los  bits del 8 al 15
	
		if ((i>=16)&&(i<24))//condición para sólo operar con los bits del 16 al 23
		mas3=(1<<i)|mas3; //en mas1 guarda los  bits del 16 al 23
	
		if ((i>=24)&&(i<32))//condición para sólo operar con los bits del 24 al 31
		mas4=(1<<i)|mas4; //en mas4 guarda los  bits del 24 al 31
	}
	h1=mas1&a;//en h1 guarda los  bits del 0 al 7
	h2=mas2&a;//en h2 guarda los  bits del 8 al 15
	h3=mas3&a;//en h3 guarda los  bits del 16 al 23
	h4=mas4&a;//en h4 guarda los  bits del 24 al 31
	
	*rd=(h1<<8)|(h2>>8)|(h3<<8)|(h4>>8); //En rd se guardan en el orden deseado los valores
	
}

void REVSH (uint32_t* rd,uint32_t a) //Cambia el orden de los bits, hace extensión de símbolo
{
	int i; //variable local
	uint32_t mas1=0,mas2=0,h1; //variables locales
	for (i=8; i<32;i++) // ciclo para recorrer cada bit
	{
		if((i>=8)&&(i<16))  //condición para sólo operar con los bits del 8 al 15
		mas1=(1<<i)|mas1; //en mas1 guarda los  bits del 8 al 15
	
		if (i>=8) //condicion para los bits mayores a 8
		mas2=(1<<i)|mas2; //en mas2 guarda los  bits mayores a 8
	}
	h1=mas1&a;  //en h2 guarda los  bits del 8 al 15
	
	if(a>=128) //condicion para saber si el valor de a es negativo
		*rd=(h1>>8)|(mas2); //guarde en rd el valor desplazado 8 veces a la derecha y haga un or con mas2
	else
		*rd=(h1>>8); //guarde en rd el valor desplazado 8 veces a la derecha
	
}

