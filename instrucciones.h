#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
* \brief Function ADD
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void ADD (uint32_t* rd, uint32_t a, uint32_t b);

void AND (uint32_t* rd, uint32_t a, uint32_t b);

void EOR (uint32_t* rd, uint32_t a, uint32_t b);

void ORR (uint32_t* rd, uint32_t a, uint32_t b);

void SUB (uint32_t* rd, uint32_t a, uint32_t b);

void MUL (uint32_t* rd, uint32_t a, uint32_t b);

void BIC (uint32_t* rd, uint32_t a, uint32_t b);

void LSL (uint32_t* rd, uint32_t a, uint32_t b);

void LSR (uint32_t* rd, uint32_t a, uint32_t b);

void SBC(uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas);

void ADC (uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas);

void MOV (uint32_t* rd, uint32_t a);

void MVN (uint32_t* rd, uint32_t a);

void RSB (uint32_t* rd, uint32_t a);

void ROR(uint32_t* rd,uint32_t a,uint32_t b);

void NOP ();

void CMN (uint32_t a, uint32_t b, uint32_t* Banderas);

void CMP (uint32_t a, uint32_t b, uint32_t* Banderas);

void TST (uint32_t a, uint32_t b, uint32_t* Banderas);

void ASR(uint32_t* rd,uint32_t a,uint32_t b);

void REV(uint32_t* rd,uint32_t a);

void REV16(uint32_t* rd,uint32_t a);

void REVSH(uint32_t* rd,uint32_t a);

