/*
 * fecha.c
 *
 *  Created on: 13 oct. 2021
 *      Author: santi
 */
#include "fecha.h"

eFecha pedirFecha(char mensaje[])
{
	eFecha fecha;

	printf("%s", mensaje);
	pedirEntero(&fecha.dia, "Ingrese dia (1-31): ", "Error. Reingrese dia (1-31): ", 1, 31);
	pedirEntero(&fecha.mes, "Ingrese mes (1-12): ", "Error. Reingrese mes (1-12): ", 1, 12);
	pedirEntero(&fecha.anio, "Ingrese anio (2019-2022): ", "Error. Reingrese anio (2019-2022): ", 2019, 2022);

	return fecha;
}

void mostrarFecha(eFecha fecha)
{
	printf("-5%d/%-5d/%-5d", fecha.dia, fecha.mes, fecha.anio);
}

