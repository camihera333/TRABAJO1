#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
* \brief Funcion funcBanderas
* \param uint32_t* rd puntero a la primera posicion del arreglo
* \param uint32_t a primer registro que se va utilizar
* \param uint32_t b segundo registro que se va a utilizar
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void funcBanderas (uint32_t*rd, uint32_t a, uint32_t b, uint32_t* Banderas);
/**
* \brief Funcion funcBanderas1
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t Rdr tercer registro que se va a utilizar
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void funcBanderas1 (uint32_t Rn, uint32_t Rm, uint32_t Rdr, uint32_t* Registros, uint32_t* Banderas);
/**
* \brief Funcion funcBanderas2
* \param uint32_t Rn primer registro que se va utilizar
* \param uint32_t Rm segundo registro que se va utilizar
* \param uint32_t aux tercer registro que se va a utilizar
* \param uint32_t* Registros puntero al arreglo de registro
* \param uint32_t* Banderas puntero al arreglo donde se guardan las banderas
* \return 0
*/
void funcBanderas2 (uint32_t Rn, uint32_t Rm, uint32_t aux, uint32_t* Registros, uint32_t* Banderas);
