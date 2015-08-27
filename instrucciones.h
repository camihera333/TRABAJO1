#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

#include "colors.h"

/**
*\brief funcion ADD
*\param long int Rn operando 1 de la suma
*\param long int Rm operando 2 de la suma
*\return 0
*/
void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
*\brief funcion AND
*\param long int Rn operando 1 de la multiplicacion logica
*\param long int Rm operando 2 de la multiplicacion logica
*\return 0
*/

void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void SUB (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

