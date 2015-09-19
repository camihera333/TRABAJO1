#include <curses.h>
#include <stdio.h>

#include "funcBanderas.h"
#include "funcionregistro.h"
#include "funcioninterfaz.h"
#include "instrucciones.h"
#include <stdint.h>
#include "decoder.h"

int main(void)
{	
	//declaracion de variables locales
	uint32_t Banderas[4]={0};
    uint32_t registros[16]={3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	//------- No modificar ------//	
		int i, num_instructions;
		ins_t read;
		char** instructions;
		instruction_t instruction;
	
		num_instructions = readFile("code.txt", &read);
		if(num_instructions==-1)
			return 0;
	
		if(read.array==NULL)
			return 0;	
	
		instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//	

   	
	//declaraciónn variables locales
	int ch=0;
	int j;
	iniciarinterfaz(); // inicio de la interfaz
	clear();
	
	while(ch!='S') //ciclo infinito hasta que se presione la tecla S, salir
	{	
		ch = getch(); //obtiene la tecla que se presionó
		if(ch=='R') //condición si se presionó la tecla R, reinicia
		{
			refresh();
			registros[15]=0; //fija pc en cero
			instruction = getInstruction(instructions[registros[15]]); // empieza la instrucción en pc=0
			mvprintw(12,7,"          ");
			
			for(j=0;j<16;j++) //ciclo para llenar los registros en cero
			{
			registros[j]=0;	
			}
			
			for(j=0;j<4;j++) //ciclo para llenar la banderas en cero
			{
			Banderas[j]=0;	
			}
		}
		
		if(ch=='A') //ciclo infinito hasta que se presione la tecla A, automático
		{
			timeout(1000); //función para hacer correr la interfaz automáticamente cada 1 segundo
		}
		
		if(ch=='P') //ciclo infinito hasta que se presione la tecla P, pausar
		{
			timeout(-1000); //función para poner de nuevo la interfaz paso a paso
		}
		
		refresh();
		mostrarRegistros(registros,13); //mostrar registros
		refresh();
		mostrarbanderas(Banderas,4); //mostrar banderas
		refresh();
		mvprintw(12,7,"      ");
		mvprintw(12,4,"PC: %d",registros[15]); //imprimir valor de pc
		refreshScreen();
		mvprintw(14,4,"LR: %d",registros[14]); //Imprimir valor de lr
		refresh();
		instruction = getInstruction(instructions[registros[15]]); // Instrucción en la posición 0
		mvprintw(16,4,"->");
		mvprintw(16,7,instructions[registros[15]]); //imprimir la próxima instrucción
		refresh();
		decodeInstruction(instruction,registros,Banderas); // encargada de hacer el llamado a la instrucción y modifica el pc para saber que linea del txt ejecutar
		refresh();	
		init_pair(6, COLOR_WHITE, COLOR_BLACK); //definición el par de color 6
		attron(COLOR_PAIR(6)); //inicia el color 6
		mvprintw(23,6,"BOTONES DE AYUDA: R=Reiniciar A=Automatico P=Parar S=salir"); //mostrar en pantalla los botones de ayuda
		attroff(COLOR_PAIR(6)); //finaliza el color 6
		refresh();
	}
	

	//------- No modificar ------//	
	/* Libera la memoria reservada para las instrucciones */
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}	
	free(read.array);
	//---------------------------//

	endwin();
		
	return 0;
}
