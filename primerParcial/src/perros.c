/*
 * perros.c
 *
 *  Created on: 12 oct. 2021
 *      Author: santi
 */
#include "perros.h"
#include "estadia.h"
#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"


int inicializarPerros(ePerro listaPerros[], int tam)
{
	int i;
	int retorno = -1;

	if (listaPerros != NULL)
	{
		for (i=0; i<tam; i++)
		{
			listaPerros[i].isEmpty = VACIO;
			retorno = 0;
		}
	}
		return retorno;
}

int buscarIdPerro(ePerro listaPerros[] , int tam , int id)
{
	int retorno = -1;
	int i;
	if (listaPerros != NULL)
	{
		for (i=0; i<tam; i++)
		{
			if (listaPerros[i].id == id)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}


void mostrarPerro(ePerro unPerro)
{
	printf("\n-----------------------------------------");

	printf("\n%-15s %-15s %-20s %-15s\n", "ID PERRO", "NOMBRE", "RAZA", "EDAD");
	printf("\n%-15d %-15s %-20s %-15d", unPerro.id, unPerro.nombre, unPerro.raza, unPerro.edad);

	printf("\n-----------------------------------------\n");
}

void mostrarTodosLosPerros(ePerro listadoPerros[],int  tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		if(listadoPerros[i].isEmpty==OCUPADO)
		{
			mostrarPerro(listadoPerros[i]);
		}

	}
}


int buscarLibrePerros(ePerro listaPerros[] , int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if (listaPerros[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int retornarIdPerro(ePerro listaPerros[] , int tam, int id)
{
	int index = -1;
	int i;

	for(i=0; i<tam; i++)
	{
		if (listaPerros[i].id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int submenuModificarPerro(ePerro listaPerros[],int tam)
{
	int opcion;
	int retorno;
	ePerro auxPerro;
	int index;
	int id;

	pedirEntero(&id,"ingrese el id del perro: ","Error. Ingrese el id del perro: ", 1000,2000);
	index= retornarIdPerro( listaPerros ,  tam,  id);


	while(opcion != 4)
	{
		pedirEntero(&opcion, "-------------------------------------\n"
								 "1. MODIFICAR nombre\n"
								 "2. MODIFICAR raza\n"
								 "3. MODIFICAR edad\n"
								 "4.ATRAS\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. MODIFICAR nombre\n"
								 "2. MODIFICAR raza\n"
								 "3. MODIFICAR edad\n"
								 "4.ATRAS\n"
								"-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 4);

		switch(opcion)
		{
			case 1:
					printf("\nperro a modificar:\n\n%-10s %-20s %-20s %-10s\n", "ID", "nombre", "raza", "edad");
					mostrarPerro(listaPerros[index]);
					pedirCadena(auxPerro.nombre, "Ingrese nombre: ", "nombre invalido, hasta 20 caracteres, reingrese: ", 21);

					printf("\nPerro luego de la modificacion:\n\n%-10s %-20s %-20s %-10s\n", "ID", "nombre", "raza", "edad");
					mostrarPerro(auxPerro);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del perro: "))
					{
						strcpy(listaPerros[index].nombre , auxPerro.nombre);
						printf("\nperro %s modificado correctamente!\n\n", listaPerros[index].nombre);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion.\n\n");
					}

					system("pause");
					break;

			case 2:
					printf("\nperro a modificar:\n\n%-10s %-20s %-20s %-10s\n", "ID", "nombre", "raza", "edad");
					mostrarPerro(listaPerros[index]);
					pedirCadena(auxPerro.raza, "Ingrese raza: ", "raza invalida, hasta 20 caracteres, reingrese: ", 21);

					printf("\nPerro luego de la modificación:\n\n%-10s %-20s %-20s %-10s\n", "ID", "nombre", "raza", "edad");
					mostrarPerro(auxPerro);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del perro: "))
					{
						strcpy(listaPerros[index].raza , auxPerro.raza);
						printf("\nperro %s modificado correctamente!\n\n", listaPerros[index].nombre);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion.\n\n");
				    }

					system("pause");
					break;

			case 3:
					printf("\nperro a modificar:\n\n%-10s %-20s %-20s %-10s\n", "ID", "nombre", "raza", "edad");
					mostrarPerro(listaPerros[index]);
					pedirEntero(&auxPerro.edad, "Ingrese la edad del perro: ", "Reingrese la edad del perro: ", 0, 20);

					printf("\nPerro luego de la modificación:\n\n%-10s %-20s %-20s %-10s\n", "ID", "nombre", "raza", "edad");
					mostrarPerro(auxPerro);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del perro: "))
					{
						listaPerros[index].edad = auxPerro.edad;
						printf("\nperro %s modificado correctamente!\n\n", listaPerros[index].nombre);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion.\n\n");
					}

					system("pause");
					break;

			}
		}

	return retorno;
}


float promedioEdadPerros(ePerro listaPerros[], int tamPerros)
{
	int i;
	int acumulador = 0;
	float promedio;
	int contador;

	if(listaPerros != NULL)
	{
		for(i=0; i<tamPerros; i++)
		{
			if(listaPerros[i].isEmpty == OCUPADO)
			{
				acumulador += listaPerros[i].edad;
				contador++;
			}
		}
	promedio = (float) acumulador / contador;
	}

	return promedio;
}






