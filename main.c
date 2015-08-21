#include <stdio.h>
#include <stdlib.h>
#include "funcionregistro.h"

main()
{

    long int R[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};
    long int Rdr[6];
    long int Rn=R[10],Rm=R[5];
    registros(R);
    Rdr[0]=ADD(Rn,Rm);
    Rdr[1]=AND(Rn,Rm);
    Rdr[2]=EOR(Rn,Rm);
    Rdr[3]=MOV(Rm);
    Rdr[4]=ORR(Rn,Rm);
    Rdr[5]=SUB(Rn,Rm);




}
