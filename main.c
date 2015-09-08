#include <curses.h>
#include <stdio.h>

#include "funcBanderas.h"
#include "funcionregistro.h"
#include "funcioninterfaz.h"
#include "instrucciones.h"
#include <stdint.h>


int main(void)
{
    int i, aux,aux2,aux3;
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[13]={0,2147483645,232,0,0,0,0,0,0,0,0,0,0};
    uint32_t Rdr[23]={0};
    uint32_t Rn=1,Rm=2;	
	
	iniciarinterfaz();
	mostrarRegistros(registros,13);
	ADD(Rn,Rm,Rdr,registros,Banderas);//suma
	mvprintw(13,2,"ADD");
	mostrarinstrucciones(Rdr,0);
	funcBanderas(Rn,Rm,*(Rdr+0),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	AND(Rn,Rm,Rdr,registros,Banderas);//AND bit a bit
	mvprintw(13,2,"AND");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,1);
	funcBanderas(Rn,Rm,*(Rdr+1),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	EOR(Rn,Rm,Rdr,registros,Banderas);//OR exclusiva bit a bit
	mvprintw(13,2,"EOR");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,2);
	funcBanderas(Rn,Rm,*(Rdr+2),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();

	clear();
	ORR(Rn,Rm,Rdr,registros,Banderas); // or lógica bit a bit
	mvprintw(13,2,"ORR");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,3);
	funcBanderas(Rn,Rm,*(Rdr+3),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	SUB(Rn,Rm,Rdr,registros,Banderas); //resta
	mvprintw(13,2,"SUB");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,4);
	funcBanderas(Rn,Rm,*(Rdr+4),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	MUL(Rn,Rm,Rdr,registros,Banderas); //multiplica
	mvprintw(13,2,"MUL");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,5);
	funcBanderas(Rn,Rm,*(Rdr+5),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	BIC(Rn,Rm,Rdr,registros,Banderas); // and entre un registro y el complemento de otro
	mvprintw(13,2,"BIC");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,6);
	funcBanderas(Rn,Rm,*(Rdr+6),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	LSL(Rn,Rm,Rdr,registros,Banderas); // desplazamiento lógico a la izquierda
	mvprintw(13,2,"LSL");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,7);
	funcBanderas(Rn,Rm,*(Rdr+7),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	LSR(Rn,Rm,Rdr,registros,Banderas); //desplazamiento lógico a la derecha
	mvprintw(13,2,"LSR");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,8);
	funcBanderas(Rn,Rm,*(Rdr+8),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
    SBC (Rn,Rm,Rdr,registros,Banderas);//resta con carry
    mvprintw(13,2,"SBC");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,9);
	funcBanderas(Rn,Rm,*(Rdr+9),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	MOV(Rm,Rdr,registros,Banderas); //escribe un valor en registro
    mvprintw(13,2,"MOV");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,10);
	funcBanderas1(Rn,Rm,*(Rdr+10),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
    MVN(Rm,Rdr,registros,Banderas); //guarda el complemento de un registro
    mvprintw(13,2,"MVN");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,11);
	funcBanderas1(Rn,Rm,*(Rdr+11),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
    RSB(Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un número
    mvprintw(13,2,"RSB");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,12);
	funcBanderas1(Rn,Rm,*(Rdr+12),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	ASR(Rn,Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un número
    mvprintw(13,2,"ASR");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,13);
	funcBanderas(Rn,Rm,*(Rdr+13),registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	aux = CMN(Rn,Rm,aux,registros,Banderas); //suma pero no guarda el resultado, solo modifica banderas
    mvprintw(13,2,"CMN");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,14);
	funcBanderas2(Rn,Rm,aux,registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
    aux2 = CMP(Rn,Rm,aux,registros,Banderas); //resta pero no guarda el resultado, solo modifica banderas
    mvprintw(13,2,"CMP");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,15);
	funcBanderas2(Rn,Rm,aux,registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	
	aux3 = TST(Rn,Rm,aux,registros,Banderas); //resta pero no guarda el resultado, solo modifica banderas
    mvprintw(13,2,"TST");
	mostrarRegistros(registros,13);
	mostrarinstrucciones(Rdr,16);
	funcBanderas2(Rn,Rm,aux,registros,Banderas);
	mostrarbanderas(Banderas,4);
	getch();
	
	clear();
	REV(Rm,Rdr,registros,Banderas); //cambia el orden de los bits
	mvprintw(13,2,"REV");
	mostrarRegistros(registros,13);
	getch();
	
	clear();
	mvprintw(13,2,"REV16");
	REV16(Rm,Rdr,registros,Banderas); //cambia el orden de los bits cada 16 bits
    mostrarRegistros(registros,13);
	getch();
	
	clear();
	mvprintw(13,2,"REVSH");
	REVSH(Rm,Rdr,registros,Banderas); //cambia el orden de los bits del halfword bajo
    mostrarRegistros(registros,13);
	getch();
	
	clear();
	ROR(Rm,Rn,Rdr,registros,Banderas); // rotación a la derecha
    mvprintw(13,2,"ROR");
	mostrarRegistros(registros,13);
	getch();
	
	clear();
	ADC(Rn,Rm,Rdr,registros,Banderas);// suma con carry
	mvprintw(13,2,"ADC");
	mostrarRegistros(registros,13);
	getch();
	
	clear();
    NOP(); //no hace nada
	getch();
	
	for(i=17;i<=21;i++)
    {
        mostrarinstrucciones(Rdr,i);
        mostrarbanderas(Banderas,4);
		printw("\n");
		refresh();
    }
	
	//terminarinterfaz();
	endwin();
	
}	
