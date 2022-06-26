/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *	Joel Barrera
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoVuelo[10];
	int isEmpty;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr);
void Passenger_delete(Passenger* pElemento);

int Passenger_obtenerIDMaximo(LinkedList* this,int* idMinimo,int* idMaximo);

void Passenger_tipoPasajeroATexto(int tipoPasajero, char* tipoPasajeroStr);
void Passenger_tipoPasajeroANumero(char* tipoPasajeroStr,int* tipoPasajero);
void Passenger_estadoVueloATexto(int codigoVuelo,char* codigoVueloStr);
void Passenger_darFormatoCodigoVuelo(char* codigoVuelo);

int Passenger_compararPorNombre(void* pElementoUno, void* pElementoDos);
int Passenger_compararPorPrecio(void* pElementoUno, void* pElementoDos);
int Passenger_compararPorCodigoDeVuelo(void* pElementoUno, void* pElementoDos);
int Passenger_compararPorTipoDePasajero(void* pElementoUno, void* pElementoDos);
int Passenger_compararPorEstadoDeVuelo(void* pElementoUno, void* pElementoDos);

void Passenger_imprimirUno(Passenger* pElemento);
int Passenger_listarPasajeros(LinkedList* pArrayListPassenger);
int Passenger_buscarIndicePorID(LinkedList* pArrayListPassenger,int idPasajero);
int Passenger_editarUno(Passenger* pElemento, int opcionModificacion);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);


#endif /* PASSENGER_H_ */
