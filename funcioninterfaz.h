#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>

/**
* \brief Funcion iniciarinterfaz
* \return 0
*/
void iniciarinterfaz ();

/**
* \brief Funcion terminarinterfaz
* \return 0
*/
void terminarinterfaz ();

/**
* \brief Funcion mostrarRegistros
* \param uint32_t* puntero, registros primera variable que se va utilizar
* \param size_t t tamaño del arreglo,segunda variable que se va utilizar
* \return 0
*/
void mostrarRegistros(uint32_t* registros, size_t t);	

/**
* \brief Funcion refreshScreen
* \return 0
*/
void refreshScreen(void);