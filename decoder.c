#include "decoder.h"
#include "instrucciones.h"
#include "funcBanderas.h"


void decodeInstruction(instruction_t instruction, uint32_t* registros, uint32_t* Banderas, uint8_t* memory)
{
	uint32_t a,d,e,f,g;
	uint32_t aux=0;
	
	//Función LDR
	if( strcmp(instruction.mnemonic,"LDR") == 0 ){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				MOV(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función				
			}
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				MOV(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				}
		}
		
		else {
			if(instruction.op3_type=='#'){  //si el operando 3 es un numero
			aux=instruction.op3_value; //Se guarda el valor actual del operador en a
			aux=aux<<2;
			LDR(&registros[instruction.op1_value],registros[instruction.op2_value],aux,memory); //se invoca la función
			aux=0;
			}
				else{
				LDR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
				}
		}
		uint32_t h=26624;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}
	
	//Función LDRB
	if( strcmp(instruction.mnemonic,"LDRB") == 0 ){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				MOV(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función				
			}
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				MOV(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				}
		}
		
		else {
			if(instruction.op3_type=='#'){  //si el operando 3 es un numero
			aux=instruction.op3_value; //Se guarda el valor actual del operador en a
			LDRB(&registros[instruction.op1_value],registros[instruction.op2_value],aux,memory); //se invoca la función
			aux=0;
			}
				else{
				LDRB(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
				}
		}
		uint32_t h=30720;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}
	
	//Función LDRH
	if( strcmp(instruction.mnemonic,"LDRH") == 0 ){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				MOV(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función				
			}
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				MOV(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				}
		}
		
		else {
			if(instruction.op3_type=='#'){  //si el operando 3 es un numero
			aux=instruction.op3_value; //Se guarda el valor actual del operador en a
			aux=aux<<1;
			LDRH(&registros[instruction.op1_value],registros[instruction.op2_value],aux,memory); //se invoca la función
			aux=0;
			}
				else{
				LDRH(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
				}
		}
		uint32_t h=34816;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}
	
	//Función LDRSB
	if( strcmp(instruction.mnemonic,"LDRSB") == 0 ){ //comparando caracteres con los del archivo txt
	
		LDR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
		uint32_t h=22016;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}
	
	//Función LDRSH
	if( strcmp(instruction.mnemonic,"LDRSH") == 0 ){ //comparando caracteres con los del archivo txt
	
		LDR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
		uint32_t h=24064;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}
	
	//Función STR
	if( strcmp(instruction.mnemonic,"STR") == 0 ){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				MOV(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función				
			}
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				MOV(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				}
		}
		
		else {
			if(instruction.op3_type=='#'){  //si el operando 3 es un numero
			aux=instruction.op3_value;
			aux=aux<<2;
			STR(&registros[instruction.op1_value],registros[instruction.op2_value],aux,memory); //se invoca la función
			aux=0;
			}
				else{
				STR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
				}
		}
		uint32_t h=24576;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}
	
	//Función STRB
	if( strcmp(instruction.mnemonic,"STRB") == 0 ){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				MOV(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función				
			}
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				MOV(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				}
		}
		
		else {
			if(instruction.op3_type=='#'){  //si el operando 3 es un numero
			aux=instruction.op3_value;
			STRB(&registros[instruction.op1_value],registros[instruction.op2_value],aux,memory); //se invoca la función
			aux=0;
			}
				else{
				STRB(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
				}
		}
		uint32_t h=28672;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}
	
	//Función STRH
	if( strcmp(instruction.mnemonic,"STRH") == 0 ){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				MOV(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función				
			}
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				MOV(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				}
		}
		
		else {
			if(instruction.op3_type=='#'){  //si el operando 3 es un numero
			aux=instruction.op3_value;
			aux=aux<<1;
			STRH(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,memory); //se invoca la función
			aux=0;
			}
				else{
				STRH(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],memory);//se invoca la función
				}
		}
		uint32_t h=32768;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}
	
	// PUSH
	if(( strcmp(instruction.mnemonic,"push") == 0 ))
	{		
	push (registros,instruction.registers_list,memory);
	registros[15]++;
	}
	//POP
	if(( strcmp(instruction.mnemonic,"pop") == 0 ))
	{		
	pop(registros,instruction.registers_list,memory);
	registros[15]++;
	}
	
		
	//Función ADD
	if(( strcmp(instruction.mnemonic,"ADDS") == 0 )||(strcmp(instruction.mnemonic,"ADD") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				ADD(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas); //se invoca la función de las banderas		
					if(instruction.op2_type=='R'){//si el operando 2 es un registro
					a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
					ADD(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
					funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas); //se invoca la función de las banderas
					}
			}
		}

		else {
			if(instruction.op3_type=='#'){  //si el operando 3 es un numero
			ADD(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{	
				ADD(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]);//se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas	
				
				}
		}
		uint32_t h=6144;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función AND
	if(( strcmp(instruction.mnemonic,"ANDS") == 0 )||(strcmp(instruction.mnemonic,"AND") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){//si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			AND(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				AND(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			AND(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				AND(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=16384;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función EOR
	if(( strcmp(instruction.mnemonic,"EORS") == 0 )||(strcmp(instruction.mnemonic,"EOR") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){//si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			EOR(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){ //si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				EOR(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			EOR(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				EOR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=16448;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		g=h|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función ORR
	if(( strcmp(instruction.mnemonic,"ORR") == 0 )||(strcmp(instruction.mnemonic,"ORRS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			ORR(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){ //si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				ORR(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			ORR(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value);//se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				ORR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=17152;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		g=h|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función SUB
	if(( strcmp(instruction.mnemonic,"SUB") == 0 )||(strcmp(instruction.mnemonic,"SUBS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			SUB(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				SUB(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			SUB(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				SUB(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=6656;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función MUL
	if(( strcmp(instruction.mnemonic,"MUL") == 0 )||(strcmp(instruction.mnemonic,"MULS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value];//Se guarda el valor actual del operador en a
			MUL(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){ //si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				MUL(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			MUL(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				MUL(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=16898;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función BIC
	if(( strcmp(instruction.mnemonic,"BIC") == 0 )||(strcmp(instruction.mnemonic,"BICS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value];//Se guarda el valor actual del operador en a
			BIC(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){ //si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				BIC(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			BIC(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				BIC(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=16896;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función LSLS
	if(( strcmp(instruction.mnemonic,"LSL") == 0 )||(strcmp(instruction.mnemonic,"LSLS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
			LSL(&registros[instruction.op1_value],instruction.op2_value,1); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op2_value]; //Se guarda el valor actual del operador en a
				LSL(&registros[instruction.op1_value],registros[instruction.op2_value],1); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],a,Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			a=registros[instruction.op2_value]; //Se guarda el valor actual del operador en a
			LSL(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],a,Banderas);//se invoca la función de las banderas
			}
				else{
				a=registros[instruction.op2_value]; //Se guarda el valor actual del operador en a
				LSL(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],a,Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=0;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;		
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función LSRS
	if(( strcmp(instruction.mnemonic,"LSR") == 0 )||(strcmp(instruction.mnemonic,"LSRS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
			LSR(&registros[instruction.op1_value],instruction.op2_value,1); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				LSR(&registros[instruction.op1_value],registros[instruction.op2_value],1); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			LSR(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
			}
				else{
				LSR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=2048;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función SBC
	if(( strcmp(instruction.mnemonic,"SBC") == 0 )||(strcmp(instruction.mnemonic,"SBCS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			SBC(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,Banderas); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				SBC(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],Banderas); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			SBC(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				SBC(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=16384;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función ADC
	if(( strcmp(instruction.mnemonic,"ADCS") == 0 )||(strcmp(instruction.mnemonic,"ADC") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			ADC(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,Banderas); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],a,instruction.op2_value,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				ADC(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],Banderas); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],a,registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			ADC(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas); //se invoca la función
			funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,Banderas);//se invoca la función de las banderas
			}
				else{
				ADC(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas); //se invoca la función
				funcBanderas (&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=16384;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función MOV
	if(( strcmp(instruction.mnemonic,"MOVS") == 0 )||(strcmp(instruction.mnemonic,"MOV") == 0)){ //comparando caracteres con los del archivo txt
			if(instruction.op2_type=='#'){//si el operando 3 no es ni un registro, ni un número
				MOV(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función
				funcBanderas2(&registros[instruction.op1_value],instruction.op2_value,Banderas);//se invoca la función de las banderas
			}
		else {
		MOV(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
		funcBanderas2(&registros[instruction.op1_value],registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
		}
		uint32_t h=4096;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		g=h|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
	}

	//Función MVN
	if(( strcmp(instruction.mnemonic,"MVNS") == 0 )||(strcmp(instruction.mnemonic,"MVN") == 0)){ //comparando caracteres con los del archivo txt
			if(instruction.op2_type=='#'){//si el operando 3 no es ni un registro, ni un número
			MVN(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas2(&registros[instruction.op1_value],instruction.op2_value,Banderas);//se invoca la función de las banderas
			}
		else {
		MVN(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
		funcBanderas2(&registros[instruction.op1_value],registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
		}
		uint32_t h=8192;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		g=h|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++; //incrementa registros[15], es decir pc, en uno
	}

	//Función RSB
	if(( strcmp(instruction.mnemonic,"RSB") == 0 )||(strcmp(instruction.mnemonic,"RSBS") == 0)){ //comparando caracteres con los del archivo txt
			if(instruction.op2_type=='#'){//si el operando 3 no es ni un registro, ni un número
				RSB(&registros[instruction.op1_value],instruction.op2_value); //se invoca la función
				funcBanderas2(&registros[instruction.op1_value],instruction.op2_value,Banderas);//se invoca la función de las banderas
			}
		else {
		RSB(&registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
		funcBanderas2(&registros[instruction.op1_value],registros[instruction.op2_value],Banderas);//se invoca la función de las banderas
		}
		uint32_t h=16896;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
	}

	//Función ROR
	if(( strcmp(instruction.mnemonic,"ROR") == 0 )||(strcmp(instruction.mnemonic,"RORS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){//si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){ //si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			ROR(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],a,Banderas);//se invoca la función de las banderas
				if(instruction.op2_type=='R'){//si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				ROR(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],a,Banderas); //se invoca la función de las banderas
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
			a=registros[instruction.op2_value]; //Se guarda el valor actual del operador en a
			ROR(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],a,Banderas);//se invoca la función de las banderas
			}
				else{
				a=registros[instruction.op2_value]; //Se guarda el valor actual del operador en a
				ROR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],a,Banderas);//se invoca la función de las banderas
				}
		}
		uint32_t h=16896;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función NOP
	if(( strcmp(instruction.mnemonic,"NOPS") == 0 )||(strcmp(instruction.mnemonic,"NOP") == 0)){ //comparando caracteres con los del archivo txt
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función CMN
	if(( strcmp(instruction.mnemonic,"CMNS") == 0 )||(strcmp(instruction.mnemonic,"CMN") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op2_type=='#') //si el operando 2 es un número
			CMN(registros[instruction.op1_value],instruction.op2_value,Banderas); //se invoca la función
		else {
		CMN(registros[instruction.op1_value],registros[instruction.op2_value],Banderas); //se invoca la función
		}
		uint32_t h=16896;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función CMP
	if(( strcmp(instruction.mnemonic,"CMPS") == 0 )||(strcmp(instruction.mnemonic,"CMP") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op2_type=='#') //si el operando 2 es un número
			CMP(registros[instruction.op1_value],instruction.op2_value,Banderas); //se invoca la función
		else {
		CMP(registros[instruction.op1_value],registros[instruction.op2_value],Banderas); //se invoca la función
		}
		uint32_t h=10240;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función TST
	if(( strcmp(instruction.mnemonic,"TSTS") == 0 )||(strcmp(instruction.mnemonic,"TST") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op2_type=='#')//si el operando 2 es un número
			TST(registros[instruction.op1_value],instruction.op2_value,Banderas); //se invoca la función
		else {
		TST(registros[instruction.op1_value],registros[instruction.op2_value],Banderas); //se invoca la función
		}
		uint32_t h=16896;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función ASR
	if(( strcmp(instruction.mnemonic,"ASR") == 0 )||(strcmp(instruction.mnemonic,"ASRS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op3_type=='N'){ //si el operando 3 no es ni un registro, ni un número
			if(instruction.op2_type=='#'){//si el operando 2 es un número
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
			ASR(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],a,Banderas);
				if(instruction.op2_type=='R'){ //si el operando 2 es un registro
				a=registros[instruction.op1_value]; //Se guarda el valor actual del operador en a
				ASR(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value]); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],a,Banderas);
				}
			}
		}

		else {
			if(instruction.op3_type=='#'){//si el operando 3 es un numero
				a=registros[instruction.op2_value]; //Se guarda el valor actual del operador en a
			ASR(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value); //se invoca la función
			funcBanderas2 (&registros[instruction.op1_value],a,Banderas);
			}
				else{
				a=registros[instruction.op2_value]; //Se guarda el valor actual del operador en a
				ASR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value]); //se invoca la función
				funcBanderas2 (&registros[instruction.op1_value],a,Banderas);
				}
		}
		uint32_t h=4096;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
		return;
	}

	//Función REV
	if(( strcmp(instruction.mnemonic,"REVS") == 0 )||(strcmp(instruction.mnemonic,"REV") == 0)){//comparando caracteres con los del archivo txt
		if(instruction.op2_type=='#') //si el operando 2 es un número
			REV(&registros[instruction.op1_value],instruction.op2_value);//se invoca la función
		else {
		REV(&registros[instruction.op1_value],registros[instruction.op2_value]);//se invoca la función
		}
		uint32_t h=47616;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		f=instruction.op3_value; //se obtiene el valor del tercer operando y se guarda en la variable 
		g=h|(f<<6)|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
	}

	//Función REV16
	if(( strcmp(instruction.mnemonic,"REV16S") == 0 )||(strcmp(instruction.mnemonic,"REV16") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op2_type=='#')//si el operando 2 es un número
			REV16(&registros[instruction.op1_value],instruction.op2_value);//se invoca la función
		else {
		REV16(&registros[instruction.op1_value],registros[instruction.op2_value]);//se invoca la función
		}
		uint32_t h=47680;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		g=h|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
	}

	//Función REVSH
	if(( strcmp(instruction.mnemonic,"REVSH") == 0 )||(strcmp(instruction.mnemonic,"REVSHS") == 0)){ //comparando caracteres con los del archivo txt
		if(instruction.op2_type=='#') //si el operando 2 es un número
			REVSH(&registros[instruction.op1_value],instruction.op2_value);//se invoca la función
		else {
		REVSH(&registros[instruction.op1_value],registros[instruction.op2_value]);//se invoca la función
		}
		uint32_t h=47808;
		d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
		e=instruction.op2_value; //se obtiene el valor del segundo operando y se guarda en la variable e
		g=h|(e<<3)|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
		mvprintw(20,3,"Codificacion de la instruccion: "); 
		mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
		g=0;
		registros[15]++;//incrementa registros[15], es decir pc, en uno
	}
	//B
	if( strcmp(instruction.mnemonic,"B") == 0 ){ //comparando caracteres con los del archivo txt
			registros[15]+=instruction.op1_value; //guarda en pc el valor del operando 1
			uint32_t h=53248;
			d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
			g=h|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
			mvprintw(20,3,"Codificacion de la instruccion: "); 
			mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
			g=0;
	}
	
	//BL
	if( strcmp(instruction.mnemonic,"BL") == 0 ){ //comparando caracteres con los del archivo txt

			a=registros[15]; //guarda en a el valor de pc
			registros[15]+=instruction.op1_value; //guarda en pc el valor del operando 1+a
			registros[14]=a+1; //guarda en LR el valor de a +1
			uint32_t h=53248;
			d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
			g=h|d;  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
			mvprintw(20,3,"Codificacion de la instruccion: "); 
			mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
			g=0;
	}
	

	//BLX
	if( strcmp(instruction.mnemonic,"BLX") == 0 ){ //comparando caracteres con los del archivo txt

			a=registros[15];//guarda en a el valor de pc
			registros[15]=a-1; //guarda en pc el valor del operando a-1
			registros[14]=instruction.op1_value; //guarda en lr el valor del operando 1
			registros[15]+=instruction.op1_value; //guarda en pc el valor del operando 1
			uint32_t h=18304;
			d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
			g=h|(d<<3);  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
			mvprintw(20,3,"Codificacion de la instruccion: "); 
			mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
			g=0;
	}
	

	//BX
	if( strcmp(instruction.mnemonic,"BX") == 0 ){ //comparando caracteres con los del archivo txt

			registros[15]=registros[14]; //guarda en pc el valor de lr
			uint32_t h=18176;
			d=instruction.op1_value; //se obtiene el valor del primer operando y se guarda en la variable d
			g=h|(d<<3);  //Se realiza un or entre los bits fijos de la función y los respectivos valores de los operandos
			mvprintw(20,3,"Codificacion de la instruccion: "); 
			mvprintw(20,37,"%X",g); //Se imprime el valor en hexagesimal
			g=0;
	}
			

	//BEQ
	if( strcmp(instruction.mnemonic,"BEQ") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[1]==1){ // Si la bandera zero está activada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else 
				registros[15]++;
			
			
	}
	


	//BNE
	if( strcmp(instruction.mnemonic,"BNE") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[1]==0){ // Si la bandera zero está desactivada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BCS
	if( strcmp(instruction.mnemonic,"BCS") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[2]==1){ // Si la bandera carry está activada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BCC
	if( strcmp(instruction.mnemonic,"BCC") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[2]==0){ // Si la bandera carry está desactivada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BMI
	if( strcmp(instruction.mnemonic,"BMI") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[0]==1){ // Si la bandera negativo está activada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BPL
	if( strcmp(instruction.mnemonic,"BPL") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[0]==0){ // Si la bandera negativo está activada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BVS
	if( strcmp(instruction.mnemonic,"BVS") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[3]==1){ // Si la bandera sobreflujo está activada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BVC
	if( strcmp(instruction.mnemonic,"BVC") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[3]==0){ // Si la bandera sobreflujo está activada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BHI
	if( strcmp(instruction.mnemonic,"BHI") == 0 ){//comparando caracteres con los del archivo txt
			if((Banderas[2]==1)&&(Banderas[1]==0)){ // Si la bandera carry está activada y la bandera zero está desactivada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BLS
	if( strcmp(instruction.mnemonic,"BLS") == 0 ){//comparando caracteres con los del archivo txt
			if((Banderas[2]==0)||(Banderas[1]==1)){ // Si la bandera carry está desactivada y la bandera zero está activada
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BGE
	if( strcmp(instruction.mnemonic,"BGE") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[0]==Banderas[3]){ // Si la bandera negativo es igual a la bandera sobreflujo
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BLT
	if( strcmp(instruction.mnemonic,"BLT") == 0 ){//comparando caracteres con los del archivo txt
			if(Banderas[0]!=Banderas[3]){ // Si la bandera negativo es diferente a la bandera sobreflujo
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BGT
	if( strcmp(instruction.mnemonic,"BGT") == 0 ){//comparando caracteres con los del archivo txt
			if((Banderas[1]==0)&&(Banderas[0]==Banderas[3])){ // Si la bandera zero está desactivada y la bandera negativo es igual a la bandera sobreflujo
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BLE
	if( strcmp(instruction.mnemonic,"BLE") == 0 ){//comparando caracteres con los del archivo txt
			if((Banderas[1]==0)||(Banderas[0]==Banderas[3])){ // Si la bandera zero está desactivada ó la bandera negativo es igual a la bandera sobreflujo
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
			}
				else
				registros[15]++;
	}

	//BAL
	if( strcmp(instruction.mnemonic,"BAL") == 0 ){//comparando caracteres con los del archivo txt
			a=registros[15]; //guarda en a el valor de pc
			registros[15]=a+instruction.op1_value; //guarda en pc el valor de a + operando 1
	}
	
	if( strcmp(instruction.mnemonic,"LDR") == 0 ){//comparando caracteres con los del archivo txt
		if(instruction.op2_type=='#') //si el operando 2 es un número
			REV(&registros[instruction.op1_value],instruction.op2_value);//se invoca la función
		else {
		REV(&registros[instruction.op1_value],registros[instruction.op2_value]);//se invoca la función
		}
		registros[15]++;//incrementa registros[15], es decir pc, en uno
	}
}



instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;
	
	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */	
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);
	
	/* Separa los operandos */	
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;
							
						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}					
				break;
			
			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
			
			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);			
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}	
	}	
	
	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}
	
	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);	
	
	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */
		
	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */
	
	lines = countLines(fp);	/* Cantidad de líneas*/
	
	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}
	
	fclose(fp);	/* Cierra el archivo */

	return lines;
}	


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];
	
	while( fgets(buffer, 50, fp) != NULL )
		lines++;
	
	rewind(fp);
	
	return lines;
}

