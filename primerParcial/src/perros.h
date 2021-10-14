/*
 * perros.h
 *
 *  Created on: 12 oct. 2021
 *      Author: santi
 */

#ifndef PERROS_H_
#define PERROS_H_

typedef struct
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int isEmpty;

}ePerro;

int inicializarPerros(ePerro listaPerros[], int tam);
int buscarIdPerro(ePerro listaPerros[] , int tam , int id);//pasar esta funcion a perro.h
void mostrarPerro(ePerro unPerro);
int buscarLibrePerros(ePerro listaPerros[] , int tam);
int retornarIdPerro(ePerro listaPerros[] , int tam, int id);
int submenuModificarPerro(ePerro listaPerros[],int tam);

#endif /* PERROS_H_ */
