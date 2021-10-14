/*
 * estadia.h
 *
 *  Created on: 12 oct. 2021
 *      Author: santi
 */

#ifndef ESTADIA_H_
#define ESTADIA_H_
#define VACIO 0
#define OCUPADO 1

#include "fecha.h"

typedef struct
{
	int id;                   // (comienza en 100.000, autoincremental)
	char nombreDuenio[26];        // (cadena de caracteres) Validar
	int telefonoContacto;        //(sólo números) Validar
	int idPerro;         //(debe existir) Validar
	int isEmpty;
	eFecha fechaDeIngreso;             //(Validar día, mes y año)

}eEstadia;


int inicializarEstadia(eEstadia listaReservas[], int tam);
int estadia_buscarLibre(eEstadia listaEstadias[], int tam);

int verificarConfirmacion(char* mensaje);
void mostrarDatosEstadia(eEstadia listaReservas, eFecha fecha);
void mostrarEstadia(eEstadia listaReservas[], int tamReservas, ePerro listaPerros[], eFecha fecha[]);
int CompletarDatosDeEstadia(eEstadia listaReservas[] , int ultimoId ,int i, ePerro listaPerros[] , int tam, eFecha fecha);
int reservarEstadia(eEstadia listaReservas[] , int tam , int ultimoId, ePerro listaPerros[],eFecha fecha );
int submenuModificarEstadia(int opcion);
int RetornarIdEstadia(eEstadia listaReservas[] , int tam , int id);
int cancelarEstadia(eEstadia listaReservas[], ePerro listaPerros[], int tamPerros, int tamEstadias , int id);






#endif /* ESTADIA_H_ */
