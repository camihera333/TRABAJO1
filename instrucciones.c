#include "funcionregistro.h"
#include "instrucciones.h"
#include "funcBanderas.h"
#include <stdint.h>


 void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //suma
{
    *(Rdr+0)=*(Registros+Rn)+*(Registros+Rm); //En el arreglo Rdr en la posición cero se guarda el resultado de la suma
                                              // de los valores del registro en la posición Rn y Rm
}


void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //AND bit a bit
{
    *(Rdr+1)=*(Registros+Rn)&*(Registros+Rm); //En el arreglo Rdr en la posición uno se guarda el resultado AND
                                              // de los valores del registro en la posición Rn y Rm
}


void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //or exclusiva bit a bit
{
    *(Rdr+2)=*(Registros+Rn)^*(Registros+Rm); //En el arreglo Rdr en la posición dos se guarda el resultado de EOR
                                              // de los valores del registro en la posición Rn y Rm
}


void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //or lógica bit a bit
{
    *(Rdr+3)=*(Registros+Rn)|*(Registros+Rm);  //En el arreglo Rdr en la posición tres se guarda el resultado de ORR
                                              // de los valores del registro en la posición Rn y Rm
}


void SUB (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // resta
{
    *(Rdr+4)=*(Registros+Rn)-*(Registros+Rm); //En el arreglo Rdr en la posición cuatro se guarda el resultado de la resta
                                              // de los valores del registro en la posición Rn y Rm
}


void MUL (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //multiplicacion
{
    *(Rdr+5)=(*(Registros+Rm))*(*(Registros+Rn)); //En el arreglo Rdr en la posición cinco se guarda el resultado de la multiplicación
                                                 // de los valores del registro en la posición Rn y Rm
}


void BIC (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //and entre un registro y el complemento de otro
{
    *(Rdr+6)=(*(Registros+Rn))&(~*(Registros+Rm)); //En el arreglo Rdr en la posición seis se guarda el resultado de BIC
                                              // de los valores del registro en la posición Rn y Rm
}


void LSL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //desplazamiento lógico a la izquierda
{
    *(Rdr+7)=*(Registros+Rn)<<*(Registros+Rm);  //En el arreglo Rdr en la posición siete se guarda el resultado del desplazamiento
                                              // lógico a la izquierda de los valores del registro en la posición Rn y Rm
}


void LSR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //desplazamiento lógico a la derecha
{
    *(Rdr+8)=*(Registros+Rn)>>*(Registros+Rm);  //En el arreglo Rdr en la posición ocho se guarda el resultado del desplazamiento
                                              // lógico a la derecha de los valores del registro en la posición Rn y Rm
}

void SBC (uint32_t Rn,uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // resta con carry
{
    *(Rdr+9)=~*(Registros+Rn); //En el arreglo Rdr en la posición nueve se guarda el resultado de la negación del valor del registro en la posición Rn
    *(Rdr+9)=*(Rdr+9)-1; // Al valor hallado en la linea anterior se le resta 1 y se guarda en la misma posición
    *(Rdr+9)=*(Rdr+9)+*(Registros+Rm); //El resultado de la linea anterior se le suma el valor del registro en la posición Rm
}

void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // escribe un valor en un registro
{
    *(Rdr+10)=*(Registros+Rm);  //En el arreglo Rdr en la posición diez se guarda el resultado del valor del registro en la posición Rm y Rm
}

void MVN (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // guarda el complemento del registro
{
      *(Rdr+11)=~*(Registros+Rm); //En el arreglo Rdr en la posición oce se guarda el resultado del complemento del valor del registro en la posición Rm
}

void RSB (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) // obtiene el complemento a dos de un número
{
    *(Rdr+12)=~*(Registros+Rm); // //En el arreglo Rdr en la posición doce se guarda el resultado negado del valor del registro en la posición Rm
    *(Rdr+12)=*(Rdr+12)-1; // Al valor hallado en la linea anterior se le resta 1 y se guarda en la misma posición
    *(Rdr+12)=*(Registros+Rm); //El resultado de la linea anterior se guarda en el arreglo posición Rm

}

void ASR(uint32_t Rn,uint32_t Rm,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas) // desplazamiento aritmético a la derecha
{
    //se declaran variables iteradoras y condicionadoras para el numero de 32 bits que se está manejando
    int help,i;
    uint32_t A=0;
    help=32-Rn;
    // se hace un ciclo for que permite el desplazamiento aritmético a la derecha bit a bit.
    for(i=0;i<32;i++)
    {
        if((i>=0)&&(i<=Rn))
            A=A|(1<<i);
    }

    *(Rdr+13)=(help<<help)|(*(registros+Rn)>>Rm);
    *(Rdr+13)=*(registros+Rn); //En el arreglo Rdr en la posición trece se guarda el valor
                               // desplazado que ahora se encuentra en el arreglo registros en la posición Rn
}

int CMN (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t * Registros, uint32_t* Banderas) // suma pero no guarda el resultado, sólo modifica banderas
{
    aux=*(Registros+Rn)+*(Registros+Rm); //se guarda en la variable auxiliar  (aux) la suma de los valores del registro en la posición Rm y Rn
                                         //Se guarda en una auxiliar porque esta operación solo modifica banderas.
	return aux;
}

int CMP (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas)  // resta pero no guarda el resultado, sólo modifica banderas
{
    aux=*(Registros+Rn)-*(Registros+Rm); //se guarda en la variable auxiliar (aux) la resta de los valores del registro en la posición Rm y Rn
                                         //Se guarda en una auxiliar porque esta operación solo modifica banderas.
    return aux;
}


int TST (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas) // and bit a bit pero no guarda el resultado, sólo modifica banderas
{
    aux=*(Registros+Rn)&*(Registros+Rm); //se guarda en la variable auxiliar (aux) el AND de los valores del registro en la posición Rm y Rn
                                         //Se guarda en una auxiliar porque esta operación solo modifica banderas.
	return aux;
}


void NOP () //no hace nada
{
}

//las funciones ALU que vienen a continuación requieren un procedimiento individual para la
//realización de las banderas por lo que no se pone dicho procedimiento dento de cada una de las funciones


void REV(uint32_t Rm,uint32_t* Rdr,uint32_t* registros, uint32_t* Banderas) // cambia el orden de los bits
{
    //se declaran variables locales e iteradores
    uint32_t help[4],A[4]={0,0,0,0};
    int i=0;
    //por medio del siguiente for se agrupan los bits de 8 en 8 para cambiar el orden de los mismos, se van guardando los datos en un arreglo local.
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
    help[0]=(*(registros+Rm)&A[0]); //se guarda en help en la primera posición, el and entre registros en la posición Rm y A en la primera posición
    help[1]=(*(registros+Rm)&A[1]); //se guarda en help en la segunda posición, el and entre registros en la posición Rm y A en la segunda posición
    help[2]=(*(registros+Rm)&A[2]); //se guarda en help en la tercera posición, el and entre registros en la posición Rm y A en la tercera posición
    help[3]=(*(registros+Rm)&A[3]); //se guarda en help en la cuarta posición, el and entre registros en la posición Rm y A en la cuarta posición
    *(Rdr+17)=((help[0]<<24)|(help[1]<<16)|(help[2]>>8)|(help[3]>>24));
	*(Rdr+17)=*(registros+Rm); // se guarda en el arreglo Rdr en la posición 17 el resultado de los valores ya cambiados de posición.
    if(((1<<7)&*(Rdr+17))==(2^32)/2) //se evalua el resultado de esta operación con la condición de bandera negativa en un if

        *(Banderas+0)=1; //si el resultado es negativa se almacena en el arreglo banderas en la posición 0 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+0)=0; //si el resultado no es negativa se almacena en el arreglo banderas en la posición 0 un 0 para usarlo en la parte gráfica

    if(*(Rdr+17)==0) //se evalua si el resultado es cero, para activar o no la bandera cero

        *(Banderas+1)=1; //si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+1)=0; //si el resultado no es cero se almacena en el arreglo banderas en la posición 1 un 0 para usarlo en la parte gráfica

    uint32_t c;
    c=*(registros+Rm); //se guarda el valor del registro en la posición Rm para evaluar la condición de carry y activar o no la bandera

    if(c>=(2^32))
    *(Banderas+2)=1; //si el resultado tiene carry se almacena en el arreglo banderas en la posición 2 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+2)=0; //si el resultado no tiene carry se almacena en el arreglo banderas en la posición 2 un 0 para usarlo en la parte gráfica

    if(((Rm>=(2^32)/2)&(*(Rdr+17)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+17)>=(2^32)/2))) // se evalua si los operadores son de signo igual o diferente del resultado
                                                                                       //para activar o no la bandera de sobreflujo

     *(Banderas+3)=1; //si el resultado tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+3)=0; //si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 0 para usarlo en la parte gráfica
}

void REV16(uint32_t Rm,uint32_t* Rdr,uint32_t* registros,uint32_t* Banderas) //cambia el orden de los bits en cada 16 bits
{
    //se declaran variables locales e iteradores
    uint32_t help[2],A[2]={0,0};
    int i=0;
    //por medio del siguiente for se agrupan los bits de 16 en 16 para cambiar el orden de los mismos, se van guardando los datos en un arreglo local.
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
    help[0]=(*(registros+Rm)&A[0]); //se guarda en help en la primera posición, el and entre registros en la posición Rm y A en la primera posición
    help[1]=(*(registros+Rm)&A[1]); //se guarda en help en la segunda posición, el and entre registros en la posición Rm y A en la segunda posición
    *(Rdr+18)=((help[0]<<16)|(help[1]>>16));
    *(Rdr+18)=*(registros+Rm); // se guarda en el arreglo Rdr en la posición 18 el resultado de los valores ya cambiados de posición.
    if(((1<<7)&*(Rdr+18))==(2^32)/2) //se evalua el resultado de esta operación con la condición de bandera negativa en un if

        *(Banderas+0)=1; //si el resultado es negativa se almacena en el arreglo banderas en la posición 0 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+0)=0; //si el resultado no es negativa se almacena en el arreglo banderas en la posición 0 un 0 para usarlo en la parte gráfica

    if(*(Rdr+18)==0) //se evalua el resultado de esta operación con la condición de bandera cero en un if

        *(Banderas+1)=1; //si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+1)=0; //si el resultado no es cero se almacena en el arreglo banderas en la posición 1 un 0 para usarlo en la parte gráfica

    uint32_t c;
    c=*(registros+Rm); //se guarda el valor del registro en la posición Rm para evaluar la condición de carry y activar o no la bandera

    if(c>=(2^32))
    *(Banderas+2)=1; //si el resultado tiene carry se almacena en el arreglo banderas en la posición 2 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+2)=0; //si el resultado no tiene carry se almacena en el arreglo banderas en la posición 2 un 0 para usarlo en la parte gráfica

    if(((Rm>=(2^32)/2)&(*(Rdr+18)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+18)>=(2^32)/2))) // se evalua si los operadores son de signo igual o diferente del resultado
                                                                                       //para activar o no la bandera de sobreflujo

     *(Banderas+3)=1; //si el resultado tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+3)=0; //si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 0 para usarlo en la parte gráfica
}

void REVSH(uint32_t Rm,uint32_t* Rdr,uint32_t* registros, uint32_t* Banderas) //cambia el orden de los bits del halfword bajo
{
    //se crean variables locales e iteradores
    uint32_t help,A[2]={0,0},total=0;
    int i=0;
    //por medio del siguiente for se agrupan los bits de 16 en 16 para cambiar el orden de los mismos de manera especifica en esta función, se van guardando los datos en un arreglo local.
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
    {*(Rdr+19)=A[1];} //se guarda en help en la primera posición, el and entre registros en la posición Rm y A en la primera posición
    *(Rdr+19)=*(registros+Rm); // se guarda en el arreglo Rdr en la posición 19 el resultado de los valores ya cambiados de posición.
    if(((1<<7)&*(Rdr+19))==(2^32)/2) //se evalua el resultado de esta operación con la condición de bandera negativa en un if

        *(Banderas+0)=1;  //si el resultado es negativa se almacena en el arreglo banderas en la posición 0 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+0)=0;  //si el resultado no es negativa se almacena en el arreglo banderas en la posición 0 un 0 para usarlo en la parte gráfica

    if(*(Rdr+19)==0) //se evalua el resultado de esta operación con la condición de bandera cero en un if

        *(Banderas+1)=1;  //si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+1)=0;  //si el resultado no es cero se almacena en el arreglo banderas en la posición 1 un 0 para usarlo en la parte gráfica

    uint32_t c;
    c=*(registros+Rm); //se guarda el valor del registro en la posición Rm para evaluar la condición de carry y activar o no la bandera

    if(c>=(2^32))
    *(Banderas+2)=1;  //si el resultado tiene carry se almacena en el arreglo banderas en la posición 2 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+2)=0;  //si el resultado no tiene carry se almacena en el arreglo banderas en la posición 2 un 0 para usarlo en la parte gráfica

    if(((Rm>=(2^32)/2)&(*(Rdr+19)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+19)>=(2^32)/2))) // se evalua si los operadores son de signo igual o diferente del resultado
                                                                                       //para activar o no la bandera de sobreflujo
     *(Banderas+3)=1; //si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+3)=0; //si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 0 para usarlo en la parte gráfica
}


void ROR(uint32_t Rn,uint32_t Rm,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas) //Rotación a la derecha

{
    //se crean variables locales e iteradores
    int help,i;
    uint32_t A=0,help2;
    help=32-Rn;
    //por medio del siguiente for se hace la respectiva rotacion para cambiar el orden de los mismos de manera especifica en esta función, se van guardando los datos en un arreglo local.
    for(i=0;i<32;i++)
    {
        if((i>=0)&&(i<=Rn))
            A=A|(1<<i);
    }
    help2=*(registros+Rm)&A;
    *(Rdr+20)=(help2<<help)|(*(registros+Rm)>>Rn);

    *(Rdr+20)=*(registros+Rm);
    if(((1<<7)&*(Rdr+20))==(2^32)/2)//se evalua el resultado de esta operación con la condición de bandera negativa en un if


        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posición 0 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posición 0 un 0 para usarlo en la parte gráfica

    if(*(Rdr+20)==0)//se evalua el resultado de esta operación con la condición de bandera cero en un if

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+1)=0;//si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica

    uint32_t c;
    c=*(registros+Rm);//se guarda el valor del registro en la posición Rm para evaluar la condición de carry y activar o no la bandera

    if(c>=(2^32))
    *(Banderas+2)=1;//si el resultado tiene carry se almacena en el arreglo banderas en la posición 2 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+2)=0;//si el resultado no tiene carry se almacena en el arreglo banderas en la posición 2 un 0 para usarlo en la parte gráfica

    if(((Rm>=(2^32)/2)&(*(Rdr+20)<(2^32)/2)) |(((Rm<(2^32)/2))&(*(Rdr+20)>=(2^32)/2))) // se evalua si los operadores son de signo igual o diferente del resultado
                                                                                       //para activar o no la bandera de sobreflujo
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+3)=0;//si el resultado  no tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 0 para usarlo en la parte gráfica
}




void ADC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas) //suma con carry
{
    //se crean variables locales
    uint32_t c;
    c=*(Registros+Rn)+*(Registros+Rm);//se guarda el valor del registro en la posición Rm para evaluar la condición de carry y activar o no la bandera

    if(c>=(2^32)){
    *(Banderas+2)=1;
    *(Rdr+21)=c+1;//si el resultado tiene carry se almacena en el arreglo banderas en la posición 21 un c+1 para usarlo en la parte gráfica
    }
    else {
        *(Banderas+2)=0;
        *(Rdr+21)=c;//si el resultado no tiene carry se almacena en el arreglo banderas en la posición 21 un c para usarlo en la parte gráfica
    }

    if(((1<<7)&*(Rdr+21))==(2^32)/2)

        *(Banderas+0)=1;//si el resultado es negativa se almacena en el arreglo banderas en la posición 0 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+0)=0;//si el resultado no es negativa se almacena en el arreglo banderas en la posición 0 un 0 para usarlo en la parte gráfica

    if(*(Rdr+21)==0)

        *(Banderas+1)=1;//si el resultado es cero se almacena en el arreglo banderas en la posición 1 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+1)=0;//si el resultado no es cero se almacena en el arreglo banderas en la posición 1 un 0 para usarlo en la parte gráfica

        c=*(Registros+Rn)+*(Registros+Rm);

    if(c>=(2^32))
    *(Banderas+2)=1;
    else
        *(Banderas+2)=0;

    if((((Rn>=(2^32)/2)&(Rm>=(2^32)/2))&(*(Rdr+21)<(2^32)/2)) |(((Rn<(2^32)/2)&(Rm<(2^32)/2))&(*(Rdr+21)>=(2^32)/2)))// se evalua si los operadores son de signo igual o diferente del resultado
                                                                                                                     //para activar o no la bandera de sobreflujo
     *(Banderas+3)=1;//si el resultado  tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 1 para usarlo en la parte gráfica
    else
        *(Banderas+3)=0;//si el resultado no tiene sobreflujo se almacena en el arreglo banderas en la posición 3 un 0 para usarlo en la parte gráfica
}