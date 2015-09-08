#include "funcionregistro.h"
#include "instrucciones.h"
#include "funcBanderas.h"


 void mostrarinstrucciones(uint32_t* Rdr, size_t t)
{
    int i;
		
	    attron (COLOR_PAIR (1));
		mvprintw(13,5,":%u",*(Rdr+t));

	refresh();	/* Imprime en la pantalla Sin esto el printw no es mostrado */

	return;
}

void mostrarbanderas(uint32_t* banderas, size_t t)
{
    int i;
	
		
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);


	for(i=0; i<t; i++)
	{
		if( (i % 4) == 0 )
            printw("\n");
	}

    if(*(banderas+0)==1)
            {
          attron (COLOR_PAIR (3));
		printw("    N");
            }
        else
        {
          attron (COLOR_PAIR (4));
		printw("    N");
        }

    if(*(banderas+1)==1)
            {
          attron (COLOR_PAIR (3));
		printw("    Z");
            }
        else
        {
          attron (COLOR_PAIR (4));
		printw("    Z");
        }

    if(*(banderas+2)==1)
            {
          attron (COLOR_PAIR (3));
		printw("    C");
            }
        else
        {
          attron (COLOR_PAIR (4));
		printw("    C");
        }

    if(*(banderas+3)==1)
            {
          attron (COLOR_PAIR (3));
		printw("    V");
            }
        else
        {
          attron (COLOR_PAIR (4));
		printw("    V");
        }

	refresh();	
	return;
}



