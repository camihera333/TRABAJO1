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
	int k;
    uint32_t Banderas[4]={0,0,0,0};
    uint32_t registros[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[0],36);
	mvprintw(13,2,"MOV");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MOV");
	mostrarbanderas(Banderas,4);
	registros[13]=0;
	mostrarlr(&registros[13]);
	registros[14]=0;
	mostrarpc(&registros[14]);
     //llamado función mostrar banderas
	getch ();

	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[1],6);//EO
	mvprintw(13,2,"MOV");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MOV");
	mostrarbanderas(Banderas,4);
	registros[13]=0;
	mostrarlr(&registros[13]);
	registros[14]=2;
	mostrarpc(&registros[14]);
	getch ();


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	BL(registros[14],registros[13],3);
	mvprintw(13,2,"BL");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"BL");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=0;
	mostrarlr(&registros[13]);
	registros[14]=4;
	mostrarpc(&registros[14]);

	getch ();


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[2],registros[0]);//EO
	mvprintw(13,2,"MOV");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MOV");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //
	registros[14]=10;
	mostrarpc(&registros[14]);

	getch ();


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[3],1);//EO
	mvprintw(13,2,"MOV");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MOV");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=12;
	mostrarpc(&registros[14]);
    getch ();


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	LSL(&registros[3],registros[3],31);//EO
	mvprintw(13,2,"LSL");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"LSL");
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=14;
	mostrarpc(&registros[14]);
    getch ();

	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[0],0);//EO
	mvprintw(13,2,"MOV");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MOV");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=16;
	mostrarpc(&registros[14]);
    getch ();


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[4],0);//EO
	mvprintw(13,2,"MOV");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"MOV");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=18;
	mostrarpc(&registros[14]);
    getch ();

	for(k=0;k<32;k++)
	{

	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	LSL(&registros[2],registros[2],1);//EO
	mvprintw(13,2,"LSL");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"LSL");
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=20;
	mostrarpc(&registros[14]);
    getch ();


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ADC(&registros[4],registros[4],registros [4],Banderas);//EO
	mvprintw(13,2,"ADC");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"ADC");
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=22;
	mostrarpc(&registros[14]);
    getch ();

	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	CMP(registros[4],registros[1],Banderas);//EO
	mvprintw(13,2,"CMP");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"CMP");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
    registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=24;
	mostrarpc(&registros[14]);
    getch ();

	if(*(Banderas+2)==1)
	{

	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	ADD(&registros[0],registros[0],registros [3]);//EO
	mvprintw(13,2,"ADD");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"ADD");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=28;
	mostrarpc(&registros[14]);
    getch ();


	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	SUB (&registros[4],registros[4],registros [1]);//EO
	mvprintw(13,2,"SUB");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"SUB");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=30;
	mostrarpc(&registros[14]);
	getch ();

	}

	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	LSR(&registros[3],registros[3],1);//EO
	mvprintw(13,2,"LSR");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"LSR");
    mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=32;
	mostrarpc(&registros[14]);
    getch ();

	if(*(Banderas+1)==1)
	{

	clear();
	iniciarinterfaz(); // inicio de la interfaz
	mostrarRegistros(registros,13); //mostrar registros
	MOV(&registros[1],registros[4]);//EO


	mostrarRegistros(registros,13);
	BL(38,8,0);
	mvprintw(13,2,"BL");
	getch();
	clear ();
	mostrarRegistros(registros,13); //mostrar registros
	mvprintw(13,2,"BL");
	mostrarbanderas(Banderas,4); //llamado función mostrar banderas
	registros[13]=8;
	mostrarlr(&registros[13]); //mostrar instruccion
	registros[14]=8;
	mostrarpc(&registros[14]);
    getch ();

	}

	}

	return 0;

}
