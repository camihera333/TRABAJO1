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
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[15]={1426128810,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ADD(&registros[3],registros[0],registros[1]);//suma
	mvprintw(13,2,"ADD"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"ADD"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();		

	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	AND(&registros[3],registros[0],registros[1]);//and
	mvprintw(13,2,"AND"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	iniciarinterfaz(); // inicio de la interfaz
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"AND"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	EOR(&registros[3],registros[0],registros[1]);//EOR
	mvprintw(13,2,"EOR"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"EOR"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ORR(&registros[3],registros[0],registros[1]);//ORR
	mvprintw(13,2,"ORR"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"ORR"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	SUB(&registros[3],registros[0],registros[1]);//SUB
	mvprintw(13,2,"SUB"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"SUB"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MUL(&registros[3],registros[0],registros[1]);//MUL
	mvprintw(13,2,"MUL"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MUL"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	BIC(&registros[3],registros[0],registros[1]);//BIC
	mvprintw(13,2,"BIC"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"BIC"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	LSL(&registros[3],registros[0],registros[1]);//LSL
	mvprintw(13,2,"LSL"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"LSL"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	LSR(&registros[3],registros[0],registros[1]);//LSR
	mvprintw(13,2,"LSR"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"LSR"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
		
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	SBC(&registros[3],registros[0],registros[1], Banderas);//SBC
	mvprintw(13,2,"SBC"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"SBC"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ADC(&registros[3],registros[0],registros[1], Banderas);//ADC
	mvprintw(13,2,"ADC"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"ADC"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[3],registros[0]);//MOV
	mvprintw(13,2,"MOV"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MOV"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MVN(&registros[3],registros[0]);//MVN
	mvprintw(13,2,"MVN"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MVN"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	RSB(&registros[3],registros[0]);//RSB
	mvprintw(13,2,"RSB"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"RSB"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ROR(&registros[3],registros[0],registros[1]);//ROR
	mvprintw(13,2,"ROR"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"ROR"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	NOP ();//NOP
	mvprintw(13,2,"NOP"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	CMN(registros[0],registros[1],Banderas);//CMN
	mvprintw(13,2,"CMN"); 
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"CMN"); 
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	CMP(registros[0],registros[1],Banderas);//CMP
	mvprintw(13,2,"CMP"); 
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"CMP"); 
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	TST(registros[0],registros[1],Banderas);//TST
	mvprintw(13,2,"TST"); 
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"TST"); 
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ASR(&registros[3],registros[0],registros[1]);//ASR
	mvprintw(13,2,"ASR"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"ASR"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();

	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	REV(&registros[3],registros[0]);//REV
	mvprintw(13,2,"REV"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"REV"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	REV16(&registros[3],registros[0]);//REV16
	mvprintw(13,2,"REV16"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"REV16"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	REVSH(&registros[3],registros[0]);//REVSH
	mvprintw(13,2,"REVSH"); 
	funcBanderas(&registros[3],registros[0],registros[1],Banderas); //llamado función banderas
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"REVSH"); 
    mostrarinstrucciones(&registros[3]); //mostrar instruccion
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	getch ();
	
	return 0;
	
}
