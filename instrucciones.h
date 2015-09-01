#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include "colors.h"
/**
<<<<<<< HEAD
* \brief Funcion ADD
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \brief Funcion ADD 
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void ADD (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion AND
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void AND (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion EOR
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void EOR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion MOV
<<<<<<< HEAD
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/

void MOV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion ORR
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void ORR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion SUB
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void SUB (uint32_t Rn, uint32_t Rm,uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion MVN
<<<<<<< HEAD
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/

void MVN (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion RSB
<<<<<<< HEAD
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void RSB (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion MUL
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void MUL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion BIC
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void BIC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion NOP
* \return 0
*/
void NOP ();
/**
* \brief Funcion SBC
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void SBC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion CMN
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void CMN (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion CMP
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void CMP (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion LSL
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void LSL (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion LSR
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void LSR (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion ADC
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void ADC (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion ASR
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void ASR(uint32_t Rm,uint32_t corri,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas);
/**
* \brief Funcion REV
<<<<<<< HEAD
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void REV (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion REV16
<<<<<<< HEAD
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void REV16 (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion REVSH
<<<<<<< HEAD
* \param uint32_t Rm registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void REVSH (uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion ROR
* \param uint32_t corri primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void ROR(uint32_t Rm,uint32_t corri,uint32_t* Rdr, uint32_t* registros, uint32_t* Banderas);
/**
* \brief Funcion TST
* \param uint32_t Rn primer registro que se va utilizar
<<<<<<< HEAD
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
=======
* \param uint32_t Rm segundo registro que se va utilizar 
* \param uint32_t* Rdr puntero a la primera direccion del arreglo donde se guardan los resultados de las ALU
* \param uint32_t* Registros puntero al arreglo de registro 
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas 
>>>>>>> 1bf68c92c645892fc31fb5c1fd4cba350902f3bc
* \return 0
*/
void TST (uint32_t Rn, uint32_t Rm, uint32_t* Rdr, uint32_t* Registros, uint32_t* Banderas);


