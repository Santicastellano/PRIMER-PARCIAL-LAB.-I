/*
 * fecha.h
 *
 *  Created on: 13 oct. 2021
 *      Author: santi
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

eFecha pedirFecha(char mensaje[]);
void mostrarFecha(eFecha fecha);

#endif /* FECHA_H_ */
