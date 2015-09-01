##include <stdio.h>
#include <stdlib.h>

#include "funcionregistro.h"
#include "instrucciones.h"
#include <stdint.h>

#include "colors.h"
int main(void)
{
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[13]={0,1,2,0,0,0,0,0,0,0,0,0,0};
    uint32_t Rdr[23]={0};
    uint32_t Rn=1,Rm=2;
    uint32_t bitsRn[32],bitsRm[32];

	mostrarregistros(Rdr, 13);
    ADD(Rn,Rm,Rdr,registros,Banderas);//suma
<<<<<<< HEAD
    AND(Rn,Rm,Rdr,registros,Banderas);//AND bit a bit
    EOR(Rn,Rm,Rdr,registros,Banderas);//OR exclusiva bit a bit
    MOV(Rm,Rdr,registros,Banderas); //escribe un valor en registro
    ORR(Rn,Rm,Rdr,registros,Banderas); // or l骻ica bit a bit
    SUB(Rn,Rm,Rdr,registros,Banderas); //resta
    MVN(Rm,Rdr,registros,Banderas); //guarda el complemento de un registro
    RSB(Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un n鷐ero
=======
    AND(Rn,Rm,Rdr,registros,Banderas);//AND bit a bit 
    EOR(Rn,Rm,Rdr,registros,Banderas);//OR exclusiva bit a bit
    MOV(Rm,Rdr,registros,Banderas); //escribe un valor en registro
    ORR(Rn,Rm,Rdr,registros,Banderas); // or l贸gica bit a bit
    SUB(Rn,Rm,Rdr,registros,Banderas); //resta
    MVN(Rm,Rdr,registros,Banderas); //guarda el complemento de un registro
    RSB(Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un n煤mero
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
    MUL(Rn,Rm,Rdr,registros,Banderas); //multiplica
    BIC(Rn,Rm,Rdr,registros,Banderas); // and entre un registro y el complemento de otro
    NOP(); //no hace nada
    SBC(Rn,Rm,Rdr,registros,Banderas); // resta con carry
    CMN(Rn,Rm,Rdr,registros,Banderas); //suma pero no guarda el resultado, solo modifica banderas
    CMP(Rn,Rm,Rdr,registros,Banderas); //resta pero no guarda el resultado, solo modifica banderas
<<<<<<< HEAD
    LSL(Rn,Rm,Rdr,registros,Banderas); // desplazamiento l骻ico a la izquierda
    LSR(Rn,Rm,Rdr,registros,Banderas); //desplazamiento l骻ico a la derecha
    REV(Rm,Rdr,registros,Banderas); //cambia el orden de los bits
    REV16(Rm,Rdr,registros,Banderas); //cambia el orden de los bits cada 16 bits
    REVSH(Rm,Rdr,registros,Banderas); //cambia el orden de los bits del halfword bajo
    ROR(Rm,Rn,Rdr,registros,Banderas); // rotaci髇 a la derecha
    ADC(Rn,Rm,Rdr,registros,Banderas);// suma con carry
    ASR(Rm,Rn,Rdr,registros,Banderas); //desplazamiento aritm閠ico a la derecha
=======
    LSL(Rn,Rm,Rdr,registros,Banderas); // desplazamiento l贸gico a la izquierda
    LSR(Rn,Rm,Rdr,registros,Banderas); //desplazamiento l贸gico a la derecha
    REV(Rm,Rdr,registros,Banderas); //cambia el orden de los bits
    REV16(Rm,Rdr,registros,Banderas); //cambia el orden de los bits cada 16 bits
    REVSH(Rm,Rdr,registros,Banderas); //cambia el orden de los bits del halfword bajo
    ROR(Rm,Rn,Rdr,registros,Banderas); // rotaci贸n a la derecha
    ADC(Rn,Rm,Rdr,registros,Banderas);// suma con carry
    ASR(Rm,Rn,Rdr,registros,Banderas); //desplazamiento aritm茅tico a la derecha
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
    TST(Rn,Rm,Rdr,registros,Banderas);// and bit a bit pero no guarda el resultado, solo modifica banderas


    return 0;
}
