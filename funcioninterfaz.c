#include "funcioninterfaz.h"
#include "instrucciones.h"
#include "funcBanderas.h"
#include "funcionregistro.h"


void iniciarinterfaz ()
{
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
}


void refreshScreen(void)
{
	border( ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,	ACS_ULCORNER, ACS_URCORNER,	ACS_LLCORNER, ACS_LRCORNER	);
	refresh();
}

void mostrarRegistros(uint32_t *registros, size_t t)
{	
	int i;
   
	move(3, 15);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("REGISTROS");
	
	for(i=0; i<t/2; i++)
	{	move(5+i, 2);	
		attron(COLOR_PAIR(1));
		printw("R%-2d:", i);
		attron(COLOR_PAIR(2));
		printw("%d\t\t", registros[i]);
	}
	for(i=(t/4)+2; i<=(t/2)+2; i++)
	{	move(1+i, 20);	
		attron(COLOR_PAIR(1));
		printw("R%-2d:", i);
		attron(COLOR_PAIR(2));
		printw("%d\t\t", registros[i]);
	}
	for(i=(t/2)+3; i<=(t/2)+6; i++)
	{	move(-4+i, 35);	
		attron(COLOR_PAIR(1));
		printw("R%-2d:", i);
		attron(COLOR_PAIR(2));
		printw("%d\t\t", registros[i]);
	}
			
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(1));
	
	refreshScreen();
}
