
#include "instrucciones.h"


long int ADD (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn+Rm; //operacion logica de ADD y retorna Rd
    return Rd;
}

long int AND (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn&Rm;  //operacion logica de AND y retorna Rd
    return Rd;
}
long int EOR (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn^Rm; //operacion logica de EOR y retorna Rd
    return Rd;
}
long int MOV( long int Rm)
{
    long int Rd;
    Rd=Rm;//operacion logica de MOV y retorna Rd
    return Rd;
}


long int ORR (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn|Rm; //operacion logica de ORR y retorna Rd
    return Rd;
}
long int SUB (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn-Rm;
    return Rd;//operacion logica de SUB y retorna Rd
}
