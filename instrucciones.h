#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>

/**
* \brief Function push
* \param uint32_t* registros puntero a la primera direccion del arreglo
* \param uint32_t register_list primera registro que se va utilizar
* \return 0
*/
void push (uint32_t* registros,uint8_t* register_list);

/**
* \brief Function BitCount
* \param uint32_t* registros puntero a la primera direccion del arreglo
* \return uint32_t 
*/
uint32_t BitCount(uint32_t* registros);

/**
* \brief Function ADD
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void ADD (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function AND
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void AND (uint32_t* rd, uint32_t a, uint32_t b);
/**
* \brief Function EOR
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void EOR (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function ORR
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void ORR (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function SUB
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void SUB (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function MUL
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void MUL (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function BIC
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void BIC (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function LSL
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void LSL (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function LSR
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void LSR (uint32_t* rd, uint32_t a, uint32_t b);

/**
* \brief Function SBC
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void SBC(uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas);

/**
* \brief Function ADC
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundoregistro que se va utilizar
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void ADC (uint32_t* rd, uint32_t a, uint32_t b, uint32_t* Banderas);

/**
* \brief Function MOV
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \return 0
*/
void MOV (uint32_t* rd, uint32_t a);

/**
* \brief Function MVN
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \return 0
*/
void MVN (uint32_t* rd, uint32_t a);

/**
* \brief Function RSB
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \return 0
*/
void RSB (uint32_t* rd, uint32_t a);

/**
* \brief Function ROR
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \return 0
*/
void ROR(uint32_t* rd,uint32_t a,uint32_t b);

/**
* \brief Function NOP
* \return 0
*/
void NOP ();

/**
* \brief Function CMN
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundoregistro que se va utilizar
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void CMN (uint32_t a, uint32_t b, uint32_t* Banderas);

/**
* \brief Function CMP
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundoregistro que se va utilizar
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void CMP (uint32_t a, uint32_t b, uint32_t* Banderas);

/**
* \brief Function TST
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundoregistro que se va utilizar
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void TST (uint32_t a, uint32_t b, uint32_t* Banderas);

/**
* \brief Function ASR
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundoregistro que se va utilizar
* \return 0
*/
void ASR(uint32_t* rd,uint32_t a,uint32_t b);

/**
* \brief Function REV
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \return 0
*/
void REV(uint32_t* rd,uint32_t a);

/**
* \brief Function REV16
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizaras
* \return 0
*/
void REV16(uint32_t* rd,uint32_t a);

/**
* \brief Function REVSH
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \return 0
*/
void REVSH(uint32_t* rd,uint32_t a);
