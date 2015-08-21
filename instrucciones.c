#include "instrucciones.h"


long int ADD (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn+Rm;
    return Rd;
}

long int AND (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn&Rm;
    return Rd;
}
long int EOR (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn^Rm;
    return Rd;
}
long int MOV( long int Rm)
{
    long int Rd;
    Rd=Rm;
    return Rd;
}


long int ORR (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn|Rm;
    return Rd;
}
long int SUB (long int Rn, long int Rm)
{
    long int Rd;
    Rd=Rn-Rm;
    return Rd;
}
