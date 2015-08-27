#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

#include "colors.h"

void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void SUB (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);



