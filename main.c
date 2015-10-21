#include <curses.h>
#include <stdio.h>

#include "funcBanderas.h"
#include "funcionregistro.h"
#include "funcioninterfaz.h"
#include "instrucciones.h"
#include <stdint.h>
#include "decoder.h"
#include "io.h"

extern uint8_t irq[16];
	
int main(void)
{
	//declaracion de variables locales
	uint32_t Banderas[4]={0};
    uint32_t registros[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,256,0,0};
	uint8_t memory[256];//declaración variables locales
	uint8_t mem_pro = 0;
	uint8_t data;


	//------- No modificar ------//
		int i, num_instructions;
		ins_t read;
		char** instructions;
		instruction_t instruction;

		num_instructions = readFile("code2.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//
	for(i=0;i<=255;i++)
	{
		memory[i]=255;
	}

	//declaraciónn variables locales
	int ch=0,j;
	iniciarinterfaz(); // inicio de la interfaz
	clear();
	initIO(); //Inicialización de los puertos
		
	
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

		if(ch=='T') //ciclo infinito hasta que se presione la tecla T, pausar
		{
			timeout(-1000); //función para poner de nuevo la interfaz paso a paso
		}

		if(ch=='C') //ciclo infinito hasta que se presione la tecla C, Memoria
		{
			erase();
			if(mem_pro==0){
				mostrarmemoria(memory);
				attron(COLOR_PAIR(1)); 
				mvprintw(23,23,"C=Otra ventana   S=salir"); //mostrar en pantalla los botones de ayuda
				attroff(COLOR_PAIR(1)); //finaliza el color 6
				mem_pro=1;
			}else{
				mostrarRegistros(registros,13); //mostrar registros
				mostrarbanderas(Banderas,4); //mostrar banderas
				mvprintw(12,7,"      ");
				mvprintw(12,4,"PC: %d",registros[15]); //imprimir valor de pc
				refreshScreen();
				mvprintw(14,4,"LR: %d",registros[14]); //Imprimir valor de lr
				instruction = getInstruction(instructions[registros[15]]); // Instrucción en la posición 0
				mvprintw(16,4,"->");
				mvprintw(16,7,instructions[registros[15]]); //imprimir la próxima instrucción
				init_pair(6, COLOR_WHITE, COLOR_BLACK); //definición el par de color 6
				attron(COLOR_PAIR(6)); //inicia el color 6
				mvprintw(23,3,"AYUDA: R=Reiniciar A=Automatico T=Parar C=Memoria  P=Puertos  S=salir"); //mostrar en pantalla los botones de ayuda
				attroff(COLOR_PAIR(6)); //finaliza el color 6
				mem_pro=0;
			}
			
		}
		
		if(ch=='P') //ciclo infinito hasta que se presione la tecla P, Puertos
		{	
			erase ();
			if(mem_pro==0){
				showPorts();
				mvprintw(23,3,"BOTONES DE AYUDA: P=volver a la pagina anterior  S=Salir"); 
				ch=getch();
				
				if(ch=='K') //ciclo infinito hasta que se presione la tecla P, pausar
				{
					ch=getch();
					
					IOAccess(2, &data, Read);
					if(data&(1<<(ch-48)))
						changePinPortB(ch-48,LOW);
					else
						changePinPortB(ch-48,HIGH);
				}
		
				if(ch=='L') //ciclo infinito hasta que se presione la tecla P, pausar
				{
					ch=getch();
					
					IOAccess(2, &data, Read);
					if(data&(1<<(ch-48)))
						changePinPortA(ch-48,LOW);
					else
						changePinPortA(ch-48,HIGH);
				}
				showPorts();
				mem_pro=1;
			}else{
			
				mostrarRegistros(registros,13); //mostrar registros
				mostrarbanderas(Banderas,4); //mostrar banderas
				mvprintw(12,7,"      ");
				mvprintw(12,4,"PC: %d",registros[15]); //imprimir valor de pc
				refreshScreen();
				mvprintw(14,4,"LR: %d",registros[14]); //Imprimir valor de lr
				instruction = getInstruction(instructions[registros[15]]); // Instrucción en la posición 0
				mvprintw(16,4,"->");
				mvprintw(16,7,instructions[registros[15]]); //imprimir la próxima instrucción
				init_pair(6, COLOR_WHITE, COLOR_BLACK); //definición el par de color 6
				attron(COLOR_PAIR(6)); //inicia el color 6
				mvprintw(23,3,"AYUDA: R=Reiniciar A=Automatico T=Parar C=Memoria  P=Puertos  S=salir"); //mostrar en pantalla los botones de ayuda
				attroff(COLOR_PAIR(6)); //finaliza el color 6
				mem_pro=0;
			}
			
		}
				
		if(ch=='I') //ciclo infinito hasta que se presione la tecla I, Paso a Paso
		{
			erase ();		
			mostrarRegistros(registros,13); //mostrar registros
			mostrarbanderas(Banderas,4); //mostrar banderas
			mvprintw(12,7,"      ");
			mvprintw(12,4,"PC: %d",registros[15]); //imprimir valor de pc
			refreshScreen();
			mvprintw(14,4,"LR: %d",registros[14]); //Imprimir valor de lr
			instruction = getInstruction(instructions[registros[15]]); // Instrucción en la posición 0
			mvprintw(16,4,"->");
			nvic(registros,Banderas,memory,irq);
			mvprintw(16,7,instructions[registros[15]]); //imprimir la próxima instrucción
			decodeInstruction(instruction,registros,Banderas,memory); // encargada de hacer el llamado a la instrucción y modifica el pc para saber que linea del txt ejecutar	
			init_pair(6, COLOR_WHITE, COLOR_BLACK); //definición el par de color 6
			attron(COLOR_PAIR(6)); //inicia el color 6
			mvprintw(23,3,"AYUDA: R=Reiniciar A=Automatico T=Parar C=Memoria  P=Puertos  S=salir"); //mostrar en pantalla los botones de ayuda
			attroff(COLOR_PAIR(6)); //finaliza el color 6
		}	
		
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
