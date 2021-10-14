/*
 * estadia.c
 *
 *  Created on: 12 oct. 2021
 *      Author: santi
 */
#include "perros.h"
#include "estadia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "fecha.h"



int inicializarEstadia(eEstadia listaReservas[], int tam)
{
	int i;
	int retorno = -1;
	if (listaReservas != NULL)
	{
		for (i=0; i<tam; i++)
		{
			listaReservas[i].isEmpty = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

int estadia_buscarLibre(eEstadia listaEstadias[], int tam)
{
    int i;
    int index;
    index=-1;

    for(i=0;i<tam;i++)
    {
        if(listaEstadias[i].isEmpty==VACIO)
        {
            index=i;
            break;
        }
    }
    return index;
}


int verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

	return retorno;
}

void mostrarDatosEstadia(eEstadia listaReservas, eFecha fecha)
{
	printf("\n----------------------------------------------------------------"
			   "\nDatos de la estadia: \n"
			   "ID: %d\nNombre duenio: %s\nTelefono de contacto: %d\nID del perro: %d\nFecha: %d/%d/%d\n"
			   "\n----------------------------------------------------------------\n", listaReservas.id, listaReservas.nombreDuenio,
			   listaReservas.telefonoContacto, listaReservas.idPerro, fecha.dia, fecha.mes,fecha.anio);
}

void mostrarEstadiaYPerro(eEstadia listaReservas[], int tamReservas, ePerro listaPerros[], eFecha fecha[])
{
	int i;

	printf("\n%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-25s\n",  "ID PERRO", "NOMBRE PERRO", "RAZA", "EDAD", "ID ESTADIA" , "NOMBRE DUEÑO", "TELEFONO CONTACTO", "FECHA");

	for(i=0 ;i<tamReservas; i++)
	{
		if (listaReservas[i].isEmpty == 1)
		{
			printf("%-15d %-15s %-15s %-15d %-15d %-15s %-25d %-2d/%-2d/%-2d\n",
					listaPerros[i].id,
					listaPerros[i].nombre,
					listaPerros[i].raza,
					listaPerros[i].edad,
					listaReservas[i].id,
					listaReservas[i].nombreDuenio,
					listaReservas[i].telefonoContacto,
					fecha[i].dia,
					fecha[i].mes,
					fecha[i].anio);
	    }
	}
}



int CompletarDatosDeEstadia(eEstadia listaReservas[] , int ultimoId ,int i, ePerro listaPerros[] , int tam, eFecha fecha)
{
	int retorno;

	listaReservas[i].id=ultimoId+1;

	pedirCadena(listaReservas[i].nombreDuenio, "\nIngrese el nombre del duenio: ", "Error. Ingrese nuevamente el nombre: ", 26);
	pedirEntero(&listaReservas[i].telefonoContacto, "Ingrese telefono de contacto: ", "Error. Reingrese teléfono: (11-0000-0000 , 11-9999-9999)", 1100000000 , 1199999999);
	pedirEntero(&listaReservas[i].idPerro, "Ingrese el ID del perro: (1000-2000)", "Error. Reingrese un ID: (1000-2000)", 1000 , 2000);
	while (buscarIdPerro(listaPerros, tam , listaReservas[i].idPerro) == -1)
	{
		printf("No se encontro el id. Vuelva a intentar.\n");
		pedirEntero(&listaReservas[i].idPerro, "Ingrese el ID del perro: (1000-2000)", "Error. Reingrese un ID: (1000-2000)", 1000 , 2000);
	}

	fecha = pedirFecha("\nComplete los datos de la fecha:\n");

	mostrarDatosEstadia( listaReservas[i], fecha);      ////////////aca nose si poner o no []////////////////////////
	if(!verificarConfirmacion("\nIngrese 's' para confirmar la reserva: "))
	{
		listaReservas[i].isEmpty = OCUPADO;
		retorno = 0;
	}

	return retorno;
}

int reservarEstadia(eEstadia listaReservas[] , int tam , int ultimoId , ePerro listaPerros[],eFecha fecha)
{
	int retorno = -1;
	int index;

		index = estadia_buscarLibre(listaReservas, tam);

		if(index != -1)
		{
			printf("\nCargando estadia...\n\n");
			if(CompletarDatosDeEstadia(listaReservas, ultimoId, index, listaPerros, tam, fecha )==0)
			{
				printf("\nSe confirmo la reserva de la estadia!\n\n");
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la reserva de la estadia.\n\n");

			}
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

		return retorno;

}

int subMenuModificarEstadia(eEstadia listaReservas[], int tam, ePerro listaPerros[])
{
	int retorno = -1;
	int index;
	int idIngresado;
	int opcion;
	eEstadia aux;
	eFecha fecha;

	pedirEntero(&idIngresado, "Ingrese el ID de la estadia a modificar (+100000): ", "Reingrese el ID de la estadia a modificar (+100000): ", 100000, 199999);
	index = RetornarIdEstadia(listaReservas, tam, idIngresado);

	if(index != -1)
	{
		printf("\nEstadia a confirmar:\n\n %-10s %-20s %-20s %-10s %-10s\n", "ID", "nombre duenio", "telefono contacto", "idPerro", "Fecha de ingreso");
		mostrarDatosEstadia( listaReservas[index], fecha);

		do
		{
			aux = listaReservas[index];
			pedirEntero(&opcion, "-------------------------------------\n"
								 "1. MODIFICAR telefono de contacto\n"
								 "2. MODIFICAR perro\n"
								 "3. ATRAS\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. MODIFICAR telefono de contacto\n"
								 "2. MODIFICAR perro\n"
								 "3. ATRAS\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 3);

			switch(opcion)
			{
				case 1:
					printf("\nEstadia a modificar:\n\n%-10s %-20s %-20s %-10s %-10s\n", "ID", "nombre duenio", "telefono contacto", "idPerro", "Fecha de ingreso");
					mostrarDatosEstadia( listaReservas[index],  fecha);
					pedirEntero(&aux.telefonoContacto, "ingrese el telefono de contacto: ", "Reingrese el telefono de contacto: ",1100000000 ,1199999999 );

					printf("\nEstadia luego de la modificación:\n\n%-10s %-20s %-20s %-10s %-10s\n", "ID", "nombre duenio", "telefono contacto", "idPerro", "Fecha de ingreso");
					mostrarDatosEstadia( listaReservas[index],  fecha);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion: "))
					{
						listaReservas[index].telefonoContacto = aux.telefonoContacto;
						printf("\nEstadia %d modificada correctamente!\n\n", listaReservas[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion de la estadia.\n\n");
					}

					system("pause");
					break;

				case 2:
					submenuModificarPerro(listaPerros, tam);
		    }
	    }while(opcion!=3);
	}

	return retorno;
}
int RetornarIdEstadia(eEstadia listaReservas[] , int tam , int id)
{
	int i;
	int index = -1;
	for (i=0;i<tam; i++)
	{
		if ( listaReservas[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int cancelarEstadia(eEstadia listaReservas[], int tamEstadias )
{
	int retorno = -1;
	int index;
	int idIngresado;

	pedirEntero(&idIngresado, "Ingrese el ID de la estadia cancelar: ", "Reingrese el ID : ", 1000, 2000);
	index = RetornarIdEstadia(listaReservas, tamEstadias, idIngresado);

	if(index != -1) //Existe el producto?
	{
		mostrarDatosEstadia(listaReservas[index], listaReservas[index].fechaDeIngreso);

		if(!verificarConfirmacion("\nIngrese 's' para cancelar la estadia: "))
		{
			listaReservas[index].isEmpty = VACIO;
			printf("\nEstadia CANCELADA!\n\n");
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la operacion.\n\n");
		}
	}
	else
	{
		printf("\nError. Estadia no encontrada...\n\n");
	}

	return retorno;
}









