/*
 ============================================================================
 Name        : primerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "perros.h"
#include "estadia.h"
#include "Inputs.h"
#define TAM_PERROS 3
#define TAM_ESTADIA 3


int main(void) {

	setbuf(stdout, NULL);

	ePerro arrayDePerros[TAM_PERROS]={{1000, "Lobo", "Sharpei", 2},{1001, "Sheila", "Golden", 12},{1002, "Reina", "Galgo", 13}};
	eEstadia estadias[TAM_ESTADIA];
	eFecha fechaIngreso;

	int opcion;
	int flagFuncion;
	int ultimoIdEstadia=100000;
	int promedio;

	inicializarEstadia(estadias, TAM_ESTADIA);

	while(opcion != 7)
	{
		pedirEntero(&opcion, "-------------------------------------\n"
											 "1. Reservar estadia\n"
											 "2. Modificar estadia\n"
											 "3. Cancelar estadia\n"
											 "4. Listar estadias\n"
											 "5. Listar perros\n"
											 "6. Promedio de edad de los perros\n"
											 "7. SALIR\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. Reservar estadia\n"
											 "2. Modificar estadia\n"
											 "3. Cancelar estadia\n"
											 "4. Listar estadias\n"
											 "5. Listar perros\n"
											 "6. Promedio de edad de los perros\n"
											 "7. SALIR\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1, 7);
		switch(opcion)
				{
				case 1:
					ultimoIdEstadia++;
					if(!reservarEstadia(estadias , TAM_ESTADIA , ultimoIdEstadia, arrayDePerros, fechaIngreso ))
					{
						flagFuncion = 0;
					}

					break;
				case 2:
					if(flagFuncion == 0 )
					{
						subMenuModificarEstadia(estadias, TAM_ESTADIA ,arrayDePerros);
					}
					else
					{
						printf("primero debe reservar una estadia \n");
					}
					break;
				case 3:
					if(flagFuncion == 0)
					{
						cancelarEstadia(estadias, arrayDePerros, TAM_PERROS, TAM_ESTADIA  ,  id)
					}
					else
					{
						printf("primero debe reservar una estadia \n");
					}
					break;
				case 4:
					if(flagFuncion == 0)
					{
						printf("aun no resuelto case 4");
					}
					else
					{
						printf("primero debe reservar una estadia \n");
					}

					break;
				case 5:
						mostrarTodosLosPerros(arrayDePerros, TAM_PERROS);

					break;
				case 6:
						promedio = promedioEdadPerros(arrayDePerros, TAM_PERROS);
						printf("el promedio de edad de los perros es de: %d",promedio);

					break;

				case 7:
					printf("finalizando programa...\n-------------------------------------\n----programa finalizado----\n");
					break;

				default:
					printf("ingrese una opcion valida");
				}

	}










	return EXIT_SUCCESS;
}
