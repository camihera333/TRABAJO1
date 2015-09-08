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
void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion AND
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion EOR
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion ORR
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion SUB
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void SUB (uint32_t Rn, uint32_t Rm,uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion MUL
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void MUL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion BIC
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void BIC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion LSL
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void LSL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion LSR
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void LSR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion SBC
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void SBC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion MOV
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);


/**
* \brief Funcion MVN
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void MVN (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion RSB
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void RSB (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion ASR
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void ASR(uint32_t Rm,uint32_t corri,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas);

/**
* \brief Funcion CMN
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
int CMN (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion CMP
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t aux variable donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
int CMP (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion TST
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t aux variable donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
int TST (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion REV
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t aux variable donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void REV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion REV16
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/

void REV16 (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion REVSH
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void REVSH (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);

/**
* \brief Funcion ROR
* \param uint32_t corri primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void ROR(uint32_t Rm,uint32_t corri,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas);

/**
* \brief Funcion ADC
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void ADC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);


/**
* \brief Funcion NOP
* \return 0
*/
void NOP ();


































