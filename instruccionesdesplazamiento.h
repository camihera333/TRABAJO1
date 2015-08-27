#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

#include "colors.h"

void LSLS (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void LSRS (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ROR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ASR (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void SUB (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
