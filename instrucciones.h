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
void SUB (uint32_t Rn, uint32_t Rm,uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void MVN (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void RSB (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void MUL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void BIC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void NOP ();
void SBC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void CMN (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void CMP (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void LSL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void LSR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ADC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ASR(uint32_t Rm,uint32_t corri,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas);
void REV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void REV16 (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void REVSH (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
void ROR(uint32_t Rm,uint32_t corri,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas);
void TST (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);


