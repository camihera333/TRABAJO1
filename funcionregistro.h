#ifndef FUNCIONREGISTRO_H
#define FUNCIONREGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>

/**
* \brief Funcion que muestra los registros
* \param uint32_t* registros puntero a la primera posicion del arreglo registros
* \param size_t t tamaño del arreglo registros
* \return 0
*/
void mostrarregistros(uint32_t* registros, size_t t);

/**
* \brief Funcion que muestra banderas
* \param uint32_t* banderas puntero a la primera posicion del arreglo banderas
* \param size_t t2 tamaño del arreglo banderas
* \return 0
*/
void mostrarbanderas(uint32_t* banderas, size_t t2);

/**
* \brief Funcion que mostrara las operaciones aritmetica-logicas
* \param uint32_t* rdr puntero a la primera posicion del arreglo rdr
* \param size_t t tamaño del arreglo rdr
* \return 0
*/
void mostrarinstrucciones(uint32_t* rd);

#endif
