#include "funcionregistro.h"
#include "funcBanderas.h"
#include <stdint.h>


 void ADD (uint32_t* rd, uint32_t a, uint32_t b) //suma 
{
    *rd=a+b; //En el arreglo Rdr en la posici�n cero se guarda el resultado de la suma
                                              // de los valores del registro en la posici�n Rn y Rm
}

void AND (uint32_t* rd, uint32_t a, uint32_t b) //AND bit a bit
{
    *rd=a&b; //En el arreglo Rdr en la posici�n uno se guarda el resultado AND
                                              // de los valores del registro en la posici�n Rn y Rm
}


void EOR (uint32_t* rd, uint32_t a, uint32_t b) //or exclusiva bit a bit
{
    *rd=a^b; //En el arreglo Rdr en la posici�n dos se guarda el resultado de EOR
                                              // de los valores del registro en la posici�n Rn y Rm
}


void ORR (uint32_t* rd, uint32_t a, uint32_t b)//or l�gica bit a bit
{
    *rd=a|b;  //En el arreglo Rdr en la posici�n tres se guarda el resultado de ORR
                                              // de los valores del registro en la posici�n Rn y Rm
}


void SUB (uint32_t* rd, uint32_t a, uint32_t b) // resta
{
    *rd=a-b;//En el arreglo Rdr en la posici�n cuatro se guarda el resultado de la resta
                                              // de los valores del registro en la posici�n Rn y Rm
}


void MUL (uint32_t* rd, uint32_t a, uint32_t b) //multiplicacion
{
    *rd=a*b; //En el arreglo Rdr en la posici�n cinco se guarda el resultado de la multiplicaci�n
                                                 // de los valores del registro en la posici�n Rn y Rm
}


void BIC (uint32_t* rd, uint32_t a, uint32_t b)//and entre un registro y el complemento de otro
{
    *rd=a&~b; //En el arreglo Rdr en la posici�n seis se guarda el resultado de BIC
                                              // de los valores del registro en la posici�n Rn y Rm
}


void LSL (uint32_t* rd, uint32_t a, uint32_t b) //desplazamiento l�gico a la izquierda
{
    *rd=a<<b;  //En el arreglo Rdr en la posici�n siete se guarda el resultado del desplazamiento
                                              // l�gico a la izquierda de los valores del registro en la posici�n Rn y Rm
}


void LSR (uint32_t* rd, uint32_t a, uint32_t b) //desplazamiento l�gico a la derecha
{
    *rd=a>>b;  //En el arreglo Rdr en la posici�n ocho se guarda el resultado del desplazamiento
                                              // l�gico a la derecha de los valores del registro en la posici�n Rn y Rm
}

void SBC (uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas) // resta con carry
{
    if(*(Banderas+2)==1)
		*rd=a-b-1;
	else
		*rd=a-b;
}

void ADC (uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas) // resta con carry
{
    if(*(Banderas+2)==1)
		*rd=a+b+1;
	else
		*rd=a+b;
}

void MOV (uint32_t* rd, uint32_t a) // resta con carry
{
    *rd=a;
}

void MVN (uint32_t* rd, uint32_t a) // resta con carry
{
    *rd=~a;
}

void RSB (uint32_t* rd, uint32_t a) // resta con carry
{
    *rd=~a+1;
}

void ROR(uint32_t* rd,uint32_t a,uint32_t b) // desplazamiento aritm�tico a la derecha
{
    int i,j; //variables locales
    uint32_t A=0,help; //variables locales
	j=32-b; //auxiliar para saber en que posici�n quedan los valores corridos
    for(i=0;i<32;i++) //ciclo para hallar m�scara
    {
        if((i>=0)&&(i<b)) //condicion para poner en 1 los bits movidos
            A=A|(1<<i);
    }
    help=a&A; //and del numero y la m�scara para extraer los numeros corridos
    *rd=(help<<j)|(a>>b); //or entre los n�meros extraidos (corridos j veces) y el valor inicial corrido b veces hacia la derecha
}

void NOP () //no hace nada
{
}

void CMN (uint32_t a, uint32_t b, uint32_t* Banderas) // resta con carry
{	
	uint32_t i;
	i=a+b;
	funcBanderas(&i,a,b,Banderas);
}


void CMP (uint32_t a, uint32_t b, uint32_t* Banderas) // resta con carry
{	
	uint32_t i;
	i=a-b;
	funcBanderas(&i,a,b,Banderas);
}

void TST (uint32_t a, uint32_t b, uint32_t* Banderas) // resta con carry
{	
	uint32_t i;
	i=a&b;
	funcBanderas(&i,a,b,Banderas);
}


void ASR(uint32_t* rd,uint32_t a,uint32_t b) // desplazamiento aritm�tico a la derecha
{
    
    uint32_t j,i,k; //variables locales
	i=(1<<31)&a;
	k=~(1<<31)&a;
	j=k>>b;
	*rd=i|j;
}

void REV (uint32_t* rd,uint32_t a) 
{
	int i;
	uint32_t mas1=0,mas2=0,mas3=0,mas4=0,h1,h2,h3,h4;
	for (i=0; i<32;i++)
	{
		if ((i>=0)&&(i<8))
		mas1=(1<<i)|mas1;
	
		if ((i>=8)&&(i<16))
		mas2=(1<<i)|mas2;
	
		if ((i>=16)&&(i<24))
		mas3=(1<<i)|mas3;
	
		if ((i>=24)&&(i<32))
		mas4=(1<<i)|mas4;
	}
	h1=mas1&a;
	h2=mas2&a;
	h3=mas3&a;
	h4=mas4&a;
	
	*rd=(h1<<24)|(h2<<8)|(h3>>8)|(h4>>24);
	
}

void REV16 (uint32_t* rd,uint32_t a) 
{
	int i;
	uint32_t mas1=0,mas2=0,mas3=0,mas4=0,h1,h2,h3,h4;
	for (i=0; i<32;i++)
	{
		if ((i>=0)&&(i<8))
		mas1=(1<<i)|mas1;
	
		if ((i>=8)&&(i<16))
		mas2=(1<<i)|mas2;
	
		if ((i>=16)&&(i<24))
		mas3=(1<<i)|mas3;
	
		if ((i>=24)&&(i<32))
		mas4=(1<<i)|mas4;
	}
	h1=mas1&a;
	h2=mas2&a;
	h3=mas3&a;
	h4=mas4&a;
	
	*rd=(h1<<8)|(h2>>8)|(h3<<8)|(h4>>8);
	
}

void REVSH (uint32_t* rd,uint32_t a) 
{
	int i;
	uint32_t mas1=0,mas2=0,h1;
	for (i=8; i<32;i++)
	{
		if((i>=8)&&(i<16))
		mas1=(1<<i)|mas1;
	
		if (i>=8)
		mas2=(1<<i)|mas2;
	}
	h1=mas1&a;
	
	if(a>=128)
		*rd=(h1>>8)|(mas2);
	else
		*rd=(h1>>8);
	
}
