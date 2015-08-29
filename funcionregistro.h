#ifndef _FUNCIONREGISTRO_H_
#define	_FUNCIONREGISTRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include "colors.h"


void mostrarregistros(uint32_t* registros, size_t t);
void mostrarbanderas(uint32_t* banderas, size_t t2);
void mostraralu(uint32_t* Rdr, size_t t);


#endif

