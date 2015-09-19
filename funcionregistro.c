#include "funcionregistro.h"
#include "instrucciones.h"
#include "funcBanderas.h"


void mostrarbanderas(uint32_t* banderas, size_t t) //funcion que muestra las banderas
{
    		
	init_pair(5, COLOR_GREEN, COLOR_BLACK); // creando combinación de colores 5
    init_pair(4, COLOR_RED, COLOR_BLACK); // creando  combinación de colores 4

	move(18,4);
    if(*(banderas+0)==1) //condicion banderas para mostrar si se activa o no la bandera negativo
            {
          attron (COLOR_PAIR (5)); //Inicializando combinación de colores 5
			printw("N ");
            }
        else
        {
          attron (COLOR_PAIR (4)); //Inicializando combinación de colores 4
		printw("N ");
        }

    if(*(banderas+1)==1) //condicion banderas para mostrar si se activa o no la bandera zero
            {
          attron (COLOR_PAIR (5)); //Inicializando combinación de colores 5
		printw("Z ");
            }
        else
        {
          attron (COLOR_PAIR (4)); //Inicializando combinación de colores 4
		printw("Z ");
        }

    if(*(banderas+2)==1) //condicion banderas para mostrar si se activa o no la bandera carry
            {
          attron (COLOR_PAIR (5)); //Inicializando combinación de colores 5
		printw("C ");
            }
        else
        {
          attron (COLOR_PAIR (4)); //Inicializando combinación de colores 4
		printw("C ");
        }
 
    if(*(banderas+3)==1) //condicion banderas para mostrar si se activa o no la bandera sobreflujo
            {
          attron (COLOR_PAIR (5)); //Inicializando combinación de colores 5
		printw("V");
            }
        else
        {
          attron (COLOR_PAIR (4)); //Inicializando combinación de colores 4
		printw("V");
		}	
	return;
	
}



