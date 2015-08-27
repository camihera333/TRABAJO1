#ifndef _FUNCIONREGISTRO_H_
#define	_FUNCIONREGISTRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

#include "colors.h"
/**
*\brief declaracion de la funcion mostrarregistros  
*\param uint32_t *registros:puntero de direccion al primer elemento del arreglo
*\param size_t t : tamaño del arreglo
*\return un 0 
*/

void mostrarregistros(uint32_t *registros, size_t t);

#endif

