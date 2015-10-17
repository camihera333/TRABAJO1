#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>


/**
* \brief Function memout
* \param uint32_t address variable que hace referencia a la memoria
* \param uint32_t num numero que determina cuantos bits se toman en la memoria 
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return uint32_t aux2 
*/
uint32_t memout (uint32_t address, uint32_t num, uint8_t* memory);

/**
* \brief Function memint
* \param uint32_t address variable que hace referencia a la memoria
* \param uint32_t num numero que determina cuantos bits se guardan en la memoria 
* \param uint8_t memory puntero a la primera direccion del arreglo
* \param uint32_t num numero que determina cuantos bits se guardan en la memoria
* \return 0
*/
void memint (uint32_t address, uint32_t num, uint8_t* memory, uint32_t num2);

/**
* \brief Function nvic
* \param uint32_t* registros puntero a la primera direccion del arreglo
* \param uint32_t Banderas puntero a la primera direccion del arreglo
* \param uint8_t memory puntero a la primera direccion del arreglo
* \param uint32_t interrupciones puntero a la primera direccion del arreglo
* \return 0
*/
void nvic(uint32_t* registros,uint32_t* Banderas,uint8_t* memory,uint8_t* irq);

/**
* \brief Function ppush
* \param uint32_t* registros puntero a la primera direccion del arreglo
* \param uint8_t memory puntero a la primera direccion del arreglo
* \param uint32_t Banderas puntero a la primera direccion del arreglo
* \return 0
*/
void ppush (uint32_t* registros,uint8_t* memory,uint32_t* Banderas) ;

/**
* \brief Function popp
* \param uint32_t* registros puntero a la primera direccion del arreglo
* \param uint8_t memory puntero a la primera direccion del arreglo
* \param uint32_t Banderas puntero a la primera direccion del arreglo
* \return 0
*/
void popp(uint32_t* registros,uint8_t* memory,uint32_t* Banderas);

/**
* \brief Function BitCount
* \param uint8_t* register_list puntero a la primera direccion del arreglo
* \return uint32_t cont
*/
uint32_t BitCount(uint8_t* register_list);

/**
* \brief Function pop
* \param uint32_t* registros puntero a la primera direccion del arreglo
* \param uint8_t register_list puntero a la primera direccion del arreglo
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void pop(uint32_t* registros,uint8_t* register_list,uint8_t* memory);

/**
* \brief Function push
* \param uint32_t* registros puntero a la primera direccion del arreglo
* \param uint8_t register_list puntero a la primera direccion del arreglo
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void push(uint32_t* registros,uint8_t* register_list,uint8_t* memory);

/**
* \brief Function LDR
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void LDR (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

/**
* \brief Function LDRB
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void LDRB (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

/**
* \brief Function LDRH
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void LDRH (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

/**
* \brief Function LDRSB
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void LDRSB (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

/**
* \brief Function LDRSH
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void LDRSH (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

/**
* \brief Function STR
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void STR (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

/**
* \brief Function STRB
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void STRB (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

/**
* \brief Function STRH
* \param uint32_t* rd puntero a la primera direccion del arreglo
* \param uint32_t a primera registro que se va utilizar
* \param uint32_t b segundo registro que se va utilizar
* \param uint8_t memory puntero a la primera direccion del arreglo
* \return 0
*/
void STRH (uint32_t* rd, uint32_t a, uint32_t b,uint8_t* memory) ;

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
