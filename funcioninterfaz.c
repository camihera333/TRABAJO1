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
	attroff(COLOR_PAIR(2)); //se finaliza el color
	attroff(COLOR_PAIR(1)); //se finaliza el color
	
}
void mostrarmemoria(uint8_t *memory)
{
	erase();
	int i; //variable local
	attron(COLOR_PAIR(1)); //inicio de color
	mvprintw(2,30,"Memoria Ram");  //mostrar en pantalla meoria ram
	attroff(COLOR_PAIR(1)); //finalización de color
	for(i=0;i<=63;i++){ //ciclo para mostrar la memoria
		int b=255-(i*4);
		
		if(i<16)
		{
			move(4+i,3);
			attron(COLOR_PAIR(1));
			printw("%.2X ",b);
			attroff(COLOR_PAIR(1));
			printw("%.2X %.2X %.2X %.2X",memory[b],memory[b-1],memory[b-2],memory[b-3]);
		}
		if((i>=16)&&(i<32))
		{
			move(4+i-16,20);
			attron(COLOR_PAIR(1));
			printw("%.2X ", b);
			attroff(COLOR_PAIR(1));
			printw("%.2X %.2X %.2X %.2X",memory[b],memory[b-1],memory[b-2],memory[b-3]);
		}
		if((i>=32)&&(i<48))
		{
			move(4+i-32,38);
			attron(COLOR_PAIR(1));
			printw("%.2X ", b);
			attroff(COLOR_PAIR(1));
			printw("%.2X %.2X %.2X %.2X",memory[b],memory[b-1],memory[b-2],memory[b-3]);
		}
		
		if(i>=48)
		{
			move(4+i-48,56);
			attron(COLOR_PAIR(1));
			printw("%.2X ", b);
			attroff(COLOR_PAIR(1));
			printw("%.2X %.2X %.2X %.2X",memory[b],memory[b-1],memory[b-2],memory[b-3]);
		}
	}
	
	attroff(COLOR_PAIR(2));   //imprime en pantalla la memoria que se realiza con los ciclos 
}
void refreshScreen(void)
{
	border( ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,	ACS_ULCORNER, ACS_URCORNER,	ACS_LLCORNER, ACS_LRCORNER	);
	refresh();
}

void mostrarRegistros(uint32_t *registros, size_t t)
{	
	int i;
   
   init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	move(2, 27);	/* Mueve el cursor a la posición y=2, x=34*/
	attron(COLOR_PAIR(3));
	printw("REGISTROS");
	attroff(COLOR_PAIR(3));

	for(i=0; i<t/2-1; i++)
	{	move(5+i, 10);	//se pone el cursor en la posicion deseda
		attron(COLOR_PAIR(1)); // se inicializa el color
		printw("R%-2d:", i); 
		attron(COLOR_PAIR(2)); // se inicializa el color
		printw("%d\t\t", registros[i]); //se imprime el resultado
	}
	for(i=(t/4)+2; i<=(t/2)+2; i++)
	{	move(i, 25);	 //se pone el cursor en la posicion deseda
		attron(COLOR_PAIR(1)); // se inicializa el color
		printw("R%-2d:", i);
		attron(COLOR_PAIR(2)); // se inicializa el color
		printw("%d\t\t", registros[i]); //se imprime el resultado
	}
	for(i=(t/2)+3; i<=(t/2)+6; i++)
	{	move(-4+i, 40);	 //se pone el cursor en la posicion deseda
		attron(COLOR_PAIR(1)); // se inicializa el color
		printw("R%-2d:", i);
		attron(COLOR_PAIR(2)); // se inicializa el color
		printw("%d\t\t", registros[i]); //se imprime el resultado
		attroff(COLOR_PAIR(2)); //se finaliza el color
		attroff(COLOR_PAIR(1)); //se finaliza el color
	}
			
	attroff(COLOR_PAIR(2)); //se finaliza el color
	attroff(COLOR_PAIR(1)); //se finaliza el color
	
	refreshScreen();
}
