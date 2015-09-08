#include <curses.h>
#include <stdio.h>

#include "funcBanderas.h"
#include "funcionregistro.h"
#include "funcioninterfaz.h"
#include "instrucciones.h"
#include <stdint.h>


int main(void)
{
	//declaracion de variables locales
    int i, aux,aux2,aux3;
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[13]={0,2147483645,232,0,0,0,0,0,0,0,0,0,0};
    uint32_t Rdr[23]={0};
    uint32_t Rn=1,Rm=2;	
	
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ADD(Rn,Rm,Rdr,registros,Banderas);//suma
	mvprintw(13,2,"ADD"); 
	mostrarinstrucciones(Rdr,0); //mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+0),registros,Banderas); //llamado función banderas
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch(); 
	
	clear(); //limpia 
	AND(Rn,Rm,Rdr,registros,Banderas);//AND bit a bit
	mvprintw(13,2,"AND");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,1); //mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+1),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	EOR(Rn,Rm,Rdr,registros,Banderas);//OR exclusiva bit a bit
	mvprintw(13,2,"EOR");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,2);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+2),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();

	clear();
	ORR(Rn,Rm,Rdr,registros,Banderas); // or lógica bit a bit
	mvprintw(13,2,"ORR");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,3);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+3),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	SUB(Rn,Rm,Rdr,registros,Banderas); //resta
	mvprintw(13,2,"SUB");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,4);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+4),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	MUL(Rn,Rm,Rdr,registros,Banderas); //multiplica
	mvprintw(13,2,"MUL");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,5);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+5),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	BIC(Rn,Rm,Rdr,registros,Banderas); // and entre un registro y el complemento de otro
	mvprintw(13,2,"BIC");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,6);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+6),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	LSL(Rn,Rm,Rdr,registros,Banderas); // desplazamiento lógico a la izquierda
	mvprintw(13,2,"LSL");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,7);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+7),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	LSR(Rn,Rm,Rdr,registros,Banderas); //desplazamiento lógico a la derecha
	mvprintw(13,2,"LSR");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,8);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+8),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
    SBC (Rn,Rm,Rdr,registros,Banderas);//resta con carry
    mvprintw(13,2,"SBC");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,9);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+9),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	MOV(Rm,Rdr,registros,Banderas); //escribe un valor en registro
    mvprintw(13,2,"MOV");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,10);//mostrar instruccion
	funcBanderas1(Rn,Rm,*(Rdr+10),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
    MVN(Rm,Rdr,registros,Banderas); //guarda el complemento de un registro
    mvprintw(13,2,"MVN");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,11);//mostrar instruccion
	funcBanderas1(Rn,Rm,*(Rdr+11),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
    RSB(Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un número
    mvprintw(13,2,"RSB");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,12);//mostrar instruccion
	funcBanderas1(Rn,Rm,*(Rdr+12),registros,Banderas); //llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrarbanderas
	getch();
	
	clear();
	ASR(Rn,Rm,Rdr,registros,Banderas); //obtiene el complemento a dos de un número
    mvprintw(13,2,"ASR");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,13);//mostrar instruccion
	funcBanderas(Rn,Rm,*(Rdr+13),registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	aux = CMN(Rn,Rm,aux,registros,Banderas); //suma pero no guarda el resultado, solo modifica banderas
    mvprintw(13,2,"CMN");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,14);//mostrar instruccion
	funcBanderas2(Rn,Rm,aux,registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
    aux2 = CMP(Rn,Rm,aux,registros,Banderas); //resta pero no guarda el resultado, solo modifica banderas
    mvprintw(13,2,"CMP");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,15);//mostrar instruccion
	funcBanderas2(Rn,Rm,aux,registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	
	aux3 = TST(Rn,Rm,aux,registros,Banderas); //resta pero no guarda el resultado, solo modifica banderas
    mvprintw(13,2,"TST");
	mostrarRegistros(registros,13); //mostrar registros
	mostrarinstrucciones(Rdr,16);//mostrar instruccion
	funcBanderas2(Rn,Rm,aux,registros,Banderas);//llamado función banderas
	mostrarbanderas(Banderas,4);//llamado función mostrar banderas
	getch();
	
	clear();
	REV(Rm,Rdr,registros,Banderas); //cambia el orden de los bits
	mvprintw(13,2,"REV");
	mostrarRegistros(registros,13); //mostrar registros
	getch();
	
	clear();
	mvprintw(13,2,"REV16");
	REV16(Rm,Rdr,registros,Banderas); //cambia el orden de los bits cada 16 bits
    mostrarRegistros(registros,13); //mostrar registros
	getch();
	
	clear();
	mvprintw(13,2,"REVSH");
	REVSH(Rm,Rdr,registros,Banderas); //cambia el orden de los bits del halfword bajo
    mostrarRegistros(registros,13); //mostrar registros
	getch();
	
	clear();
	ROR(Rm,Rn,Rdr,registros,Banderas); // rotación a la derecha
    mvprintw(13,2,"ROR"); 
	mostrarRegistros(registros,13); //mostrar registros
	getch();
	
	clear();
	ADC(Rn,Rm,Rdr,registros,Banderas);// suma con carry
	mvprintw(13,2,"ADC");
	mostrarRegistros(registros,13); //mostrar registros
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
