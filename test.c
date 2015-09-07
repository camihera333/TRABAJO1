#include "funcionregistro.h"
#include "instrucciones.h"
#include <stdint.h>

#include "colors.h"
int main(void)
{
    int i;
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[13]={0,2147483645,232,0,0,0,0,0,0,0,0,0,0};
    uint32_t Rdr[23]={0};
    uint32_t Rn=1,Rm=2;
    uint32_t bitsRn[32],bitsRm[32];

	mostrarregistros(registros, 13);
	ADD(Rn,Rm,Rdr,registros,Banderas);//suma
	mostraralu(Rdr,0);
	funcBanderas(Rn,Rm,*(Rdr+0),registros,Banderas);
	mostrarbanderas(Banderas,4);

	AND(Rn,Rm,Rdr,registros,Banderas);//AND bit a bit
	mostraralu(Rdr,1);
	funcBanderas(Rn,Rm,*(Rdr+1),registros,Banderas);
	mostrarbanderas(Banderas,4);

	EOR(Rn,Rm,Rdr,registros,Banderas);//OR exclusiva bit a bit
	mostraralu(Rdr,2);
	funcBanderas(Rn,Rm,*(Rdr+2),registros,Banderas);
	mostrarbanderas(Banderas,4);

	ORR(Rn,Rm,Rdr,registros,Banderas); // or lógica bit a bit
	mostraralu(Rdr,3);
	funcBanderas(Rn,Rm,*(Rdr+3),registros,Banderas);
	mostrarbanderas(Banderas,4);

	SUB(Rn,Rm,Rdr,registros,Banderas); //resta
	mostraralu(Rdr,4);
	funcBanderas(Rn,Rm,*(Rdr+4),registros,Banderas);
	mostrarbanderas(Banderas,4);

	MUL(Rn,Rm,Rdr,registros,Banderas); //multiplica
	mostraralu(Rdr,5);
	funcBanderas(Rn,Rm,*(Rdr+5),registros,Banderas);
	mostrarbanderas(Banderas,4);

	BIC(Rn,Rm,Rdr,registros,Banderas); // and entre un registro y el complemento de otro
	mostraralu(Rdr,6);
	funcBanderas(Rn,Rm,*(Rdr+6),registros,Banderas);
	mostrarbanderas(Banderas,4);

	LSL(Rn,Rm,Rdr,registros,Banderas); // desplazamiento lógico a la izquierda
	mostraralu(Rdr,7);
	funcBanderas(Rn,Rm,*(Rdr+7),registros,Banderas);
	mostrarbanderas(Banderas,4);

	LSR(Rn,Rm,Rdr,registros,Banderas); //desplazamiento lógico a la derecha
	mostraralu(Rdr,8);
	funcBanderas(Rn,Rm,*(Rdr+8),registros,Banderas);
	mostrarbanderas(Banderas,4);

    SBC (Rn,Rm,Rdr,registros,Banderas);//resta con carry
    mostraralu(Rdr,9);
	funcBanderas(Rn,Rm,*(Rdr+9),registros,Banderas);
	mostrarbanderas(Banderas,4);

	MOV(Rm,Rdr,registros,Banderas); //escribe un valor en registro
    mostraralu(Rdr,10);
	funcBanderas1(Rn,Rm,*(Rdr+10),registros,Banderas);
	mostrarbanderas(Banderas,4);

    MVN(Rm,Rdr,registros,Banderas); //guarda el complemento de un registro
    mostraralu(Rdr,11);
	funcBanderas1(Rn,Rm,*(Rdr+11),registros,Banderas);
	mostrarbanderas(Banderas,4);

    RSB(Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un número
    mostraralu(Rdr,12);
	funcBanderas1(Rn,Rm,*(Rdr+12),registros,Banderas);
	mostrarbanderas(Banderas,4);

	ASR(Rn,Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un número
    mostraralu(Rdr,13);
	funcBanderas(Rn,Rm,*(Rdr+13),registros,Banderas);
	mostrarbanderas(Banderas,4);

	CMN(Rn,Rm,Rdr,registros,Banderas); //suma pero no guarda el resultado, solo modifica banderas
    mostraralu(Rdr,14);
	funcBanderas2(Rn,Rm,Rdr,registros,Banderas);
	mostrarbanderas(Banderas,4);

    CMP(Rn,Rm,Rdr,registros,Banderas); //resta pero no guarda el resultado, solo modifica banderas
    mostraralu(Rdr,15);
	funcBanderas2(Rn,Rm,Rdr,registros,Banderas);
	mostrarbanderas(Banderas,4);

	TST(Rn,Rm,Rdr,registros,Banderas); //resta pero no guarda el resultado, solo modifica banderas
    mostraralu(Rdr,16);
	funcBanderas2(Rn,Rm,Rdr,registros,Banderas);
	mostrarbanderas(Banderas,4);

	REV(Rm,Rdr,registros,Banderas); //cambia el orden de los bits
    REV16(Rm,Rdr,registros,Banderas); //cambia el orden de los bits cada 16 bits
    REVSH(Rm,Rdr,registros,Banderas); //cambia el orden de los bits del halfword bajo
    ROR(Rm,Rn,Rdr,registros,Banderas); // rotación a la derecha
    ADC(Rn,Rm,Rdr,registros,Banderas);// suma con carry

    NOP(); //no hace nada

    for(i=17;i<=21;i++)
    {
        mostraralu(Rdr,i);
        mostrarbanderas(Banderas,4);
    }

    return 0;
}

