#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>


void iniciarinterfaz ();
void terminarinterfaz ();
void mostrarRegistros(uint32_t* registros, size_t t);	
void refreshScreen(void);