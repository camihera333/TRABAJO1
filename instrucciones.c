#include "funcionregistro.h"
#include "funcBanderas.h"
#include <stdint.h>
#include "instrucciones.h"
#include "funcioninterfaz.h"
#include "io.h"

uint32_t memout (uint32_t address, uint32_t num, uint8_t* memory) //función que saca los valores de la memoria
{
	//declaración de variables locales
	uint32_t aux2=0;
	uint8_t aux[4];
	int i;
	for (i=0;i<num;i++) //ciclo que determina como se van a guardar los valores 
	{
		aux[i]=memory[address+i]; //los valores se van a tomar en forma ascendente
	}
	
	for (i=0;i<num;i++) // ciclo con el cual se guardan los valores en la memoria
	{	
		//aux2=aux2<<8; //corrimiento del valor aux2
		aux2|=(aux[i]<<(8*i)); //rellenado de los valores en la memoria
	}
	return aux2; //retorna el valor rellenado en la memoria
}

void memint (uint32_t address, uint32_t num, uint8_t* memory, uint32_t num2)
{
	int i; //variable local
	uint8_t h1,h2,h3,h4;
	uint32_t mas1=0,mas2=0,mas3=0,mas4=0; //variables locales
	for (i=0; i<32;i++) // ciclo para recorrer cada bit
	{
		if ((i>=0)&&(i<8)) //condición para sólo operar con los bits del 0 al 7
		mas1=(1<<i)|mas1; //en mas1 guarda los  bits del 0 al 7
	
		if ((i>=8)&&(i<16))//condición para sólo operar con los bits del 8 al 15
		mas2=(1<<i)|mas2; //en mas2 guarda los  bits del 8 al 15
	
		if ((i>=16)&&(i<24))//condición para sólo operar con los bits del 16 al 23
		mas3=(1<<i)|mas3; //en mas3 guarda los  bits del 16 al 23
	
		if ((i>=24)&&(i<32))//condición para sólo operar con los bits del 24 al 31
		mas4=(1<<i)|mas4; //en mas4 guarda los  bits del 24 al 31
	}
	h1=mas1&num2;//en h1 guarda los  bits del 0 al 7
	h2=(mas2&num2)>>8;//en h2 guarda los  bits del 8 al 15
	h3=(mas3&num2)>>16;//en h3 guarda los  bits del 16 al 23
	h4=(mas4&num2)>>24;//en h4 guarda los  bits del 24 al 31
	
	if(num==1)
	{
		memory[address]=h1;
	}
	
	if(num==2)
	{
		memory[address]=h2;
		memory[address+1]=h1;
	}
	
	if(num==3)
	{
		memory[address]=h3;
		memory[address+1]=h2;
		memory[address+2]=h1;		
	}
	
	if(num==4)
	{
		memory[address]=h4;
		memory[address+1]=h3;
		memory[address+2]=h2;
		memory[address+3]=h1;		
	}
}
void nvic(uint32_t* registros,uint32_t* Banderas,uint8_t* memory,uint8_t* irq) 
{
	int i;
	static uint8_t a=0;
	if(a==1)
	{
		if(registros[15]==0xFFFFFFFF)
		{
			popp(registros,memory,Banderas);
			a=0;
		}
	}
	else
	{
		for(i=0;i<=32;i++)
		{
			if(irq[i]==1)
			{
				ppush(registros,memory,Banderas);
				registros[14]=0xFFFFFFFF;
				registros[15]=i+1;
				a=1;
				irq[i]=0;
				break;
			}
		}
	}
}
void ppush (uint32_t* registros,uint8_t* memory,uint32_t* Banderas)  
{
	uint32_t a;//declaración variables locales
	uint8_t register_list[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1};
	a=BitCount(register_list); //declaración variables locales
	uint32_t address;//declaración variables locales
	int i;//declaración variables locales
	address=registros[13]-4*a; //Asignación de valor a address
	for(i=0;i<=14;i++) //ciclo que va hasta el número de registros
	{
		if(register_list[i]==1) //condicion
		{
			if(i==13)
			{
				memory[address]=(uint8_t)(registros[i]);  //guarda en la posición adress del arreglo memory
				memory[address+1]=(uint8_t)(registros[i]>>8);
				memory[address+2]=(uint8_t)(registros[i]>>16);
				memory[address+3]=(uint8_t)(registros[i]>>24);
			}
			else
			{
				memory[address]=(uint8_t)(registros[i]);  //guarda en la posición adress del arreglo memory
				memory[address+1]=(uint8_t)(registros[i]>>8);
				memory[address+2]=(uint8_t)(registros[i]>>16);
				memory[address+3]=(uint8_t)(registros[i]>>24);
			}	
			address=address+4; //Actualiza adress
		}
	}
	registros[13]=registros[13]-4*a; //Actualiza el registro en la posición 13
}
void popp(uint32_t* registros,uint8_t* memory,uint32_t* Banderas) //declaración de función pop
{
	uint32_t a;//declaración variables locales
	uint8_t register_list[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1};
	a=BitCount(register_list);//declaración variables locales
	uint32_t address;//declaración variables locales
	int i;//declaración variables locales
	address=registros[13]; //Asignación de valor a address
	for(i=0;i<=15;i++) //ciclo que va hasta el número de registros
	{
		if(register_list[i]==1) //condicion
		{
			if(i==13)
			{
				registros[i]=((uint32_t)memory[address+3]<<24)|((uint32_t)memory[address+2]<<16)|((uint32_t)memory[address+1]<<8)|((uint32_t)memory[address]);//se guarda en registros en la posición i el valor indicado
			}
			else
			{
				registros[i]=((uint32_t)memory[address+3]<<24)|((uint32_t)memory[address+2]<<16)|((uint32_t)memory[address+1]<<8)|((uint32_t)memory[address]);
			}
				address=address+4; //Se actualiza address
		}
	registros[13]=registros[13]+4*a; //Actualiza el registro en la posición 13
	}
}

uint32_t BitCount(uint8_t* register_list)//declaración de función BitCount
{
	uint32_t cont=0; //declaración variables locales
	int i;
      for(i=0;i<=15;i++) //ciclo que va hasta el número de registros
	  { 
		     if(register_list[i]==1)
			   cont=cont+1; //aumenta el contador 
	  }
	  return cont;
}
void push (uint32_t* registros,uint8_t* register_list,uint8_t* memory)  //declaración de función push
{
	uint32_t a;//declaración variables locales
	a=BitCount(register_list); //declaración variables locales
	uint32_t address;//declaración variables locales
	int i;//declaración variables locales
	address=registros[13]-4*a; //Asignación de valor a address
	for(i=0;i<=14;i++) //ciclo que va hasta el número de registros
	{
		if(register_list[i]==1) //condicion
		{
			
			memory[address]=(uint8_t)(registros[i]);  //guarda en la posición adress del arreglo memory
			memory[address+1]=(uint8_t)(registros[i]>>8);
			memory[address+2]=(uint8_t)(registros[i]>>16);
			memory[address+3]=(uint8_t)(registros[i]>>24);
			address=address+4; //Actualiza adress
		}
	}
	registros[13]=registros[13]-4*a; //Actualiza el registro en la posición 13
}
	
void pop(uint32_t* registros,uint8_t* register_list,uint8_t* memory) //declaración de función pop
{
	uint32_t a;//declaración variables locales
	a=BitCount(register_list);//declaración variables locales
	uint32_t address;//declaración variables locales
	int i;//declaración variables locales
	address=registros[13]; //Asignación de valor a address
	for(i=0;i<=15;i++) //ciclo que va hasta el número de registros
	{
		if(register_list[i]==1) //condicion
		{
			registros[i]=((uint32_t)memory[address+3]<<24)|((uint32_t)memory[address+2]<<16)|((uint32_t)memory[address+1]<<8)|((uint32_t)memory[address]);//se guarda en registros en la posición i el valor indicado
			address=address+4; //Se actualiza address
		}
	}
		registros[13]=registros[13]+4*a; //Actualiza el registro en la posición 13
}

 void LDR (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función LDR
{
	uint32_t address=0;
	address=a+b;
	*rd=memout(address,4,memory);          
}

 void LDRB (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función LDRB
{
	uint32_t dir=a+(b<<2);
	if((dir>=0x20000000)&&(dir<0x40000000))
	{
	uint32_t address=0;
	address=a+b;
	*rd=memout(address,1,memory); 
	}
	if(dir>=0x40000000)
	{
		IOAccess(dir,(uint8_t*)rd, Read);
	}
}

 void LDRH (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función LDRH
{
    uint32_t address=0;
	address=a+b;
	*rd=memout(address,2,memory);   
}

 void LDRSB (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función LDRSB
{
	uint8_t z=0;
	uint32_t address=0, g=4294967040;
	uint32_t aux=0;
	aux=b;
	address=a+aux;
	z=memout(address,1,memory);
	if(z>=128) //condicion para saber si el valor de a es negativo
		*rd=(memout(address,1,memory))|(g); //guarde en rd el valor desplazado 8 veces a la derecha y haga un or con mas2
	else
	*rd=memout(address,1,memory);   
}

 void LDRSH (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función LDRSH
{
	uint8_t z=0;
    uint32_t address=0;
	uint32_t aux=0;
	aux=b;
	address=a+aux;
	z=memout(address,2,memory);
	if(z>=32768) //condicion para saber si el valor de a es negativo
		*rd=(memout(address,2,memory))|(4294901760); //guarde en rd el valor desplazado 8 veces a la derecha y haga un or con mas2
	else
	*rd=memout(address,2,memory);  
}

 void STR (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función STR
 {
	uint32_t address=0;
	address=a+b;
	memint(address,4,memory,*rd);
}
 
 void STRB (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función STRB
 {
	uint32_t dir=a+(b<<2);
	if((dir>=0x20000000)&&(dir<0x40000000))
	{
	uint32_t address=0;
	address=a+b;
	memint(address,1,memory,*rd);
	}
	if(dir>=0x40000000)
	{
		IOAccess(dir, (uint8_t*)rd, Write);
	}
 }
 
 void STRH (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory)  //declaración de función STRH
 {
	uint32_t address=0;
	address=a+b;
	memint(address,2,memory,*rd);
 }


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
	
	uint32_t c,v,ha,hb,hr;
	ha=a&(1<<31); //para sacar el bit más significativo
	hb=b&(1<<31); //para sacar el bit más significativo
	hr=i&(1<<31); //para sacar el bit más significativo
	
    if(i>=(1<<31))

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posición 0 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posición 0 un 0 para usarlo en la parte gráfica

    if(i==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posición 1 un 0 para usarlo en la parte gráfica

   
	c=(ha&&hb)||((!ha)&&(hb)&&(!hr))||(ha&&(!hb)&&(!hr)); //Fórmula para hallar el carry en este caso

    if(c)
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posición 2 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posición 2 un 0 para usarlo en la parte gráfica

	v=(ha&&hb&&(!hr))||((!ha)&&(!hb)&&hr); //Fórmula para hallar el sobreflujo en este caso
    if(v)
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 0 para usarlo en la parte gráfica
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

