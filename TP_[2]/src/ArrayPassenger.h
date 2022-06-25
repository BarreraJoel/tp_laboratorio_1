/*
 * ArrayPassenger.h
 *
 *  Created on: 24 abr. 2022
 *      Author: Joel Barrera
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input-UTN.h"

#define LIBRE 0
#define OCUPADO 1
#define MAX_TEXTO 51
#define MAX_DESCRIPCION 20
#define MAX_CODIGO 10

typedef struct{
	int statusFlight;
	char descripcion[MAX_DESCRIPCION];
}statusFlight;

typedef struct{
	int typePassenger;
	char descripcion[MAX_DESCRIPCION];
}typePassenger;

typedef struct{
	int id;
	char name[MAX_TEXTO];
	char lastName[MAX_TEXTO];
	float price;
	char flycode[MAX_CODIGO];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

/**
 * @brief Obtiene el tipo de pasajero en texto
 *
 * @param tipo Tipo de pasajero en numero entero
 * @param tipoPasajeroStr Cadena de caracteres donde se almacenara el tipo en texto
 */
void Passenger_obtenerTipo(int tipo,char tipoPasajeroStr[]);
/**
 * @brief Obtiene el estado de vuelo en texto
 *
 * @param estado Estado de vuelo de tipo entero
 * @param statusFlightStr Cadena de caracteres donde se almacenara el estado en texto
 */
void Passenger_obtenerEstado(int estado,char statusFlightStr[]);

/**
 * @brief Inicializa el array de pasajeros
 *
 *
 * @param list Passenger* Array de tipo pasajero
 * @param len int Largo del array
 * @return int Retorna (-1) Error: [Largo invalido o Puntero nulo]
 * 					   ( 0) OK
 */
int initPassengers(Passenger* list, int len);

/**
 * @brief Busca el primer espacio libre del array
 *
 * @param list Array de tipo pasajero
 * @param len Largo del array
 * @return Retorna (-1) Error: [Largo invalido o Puntero nulo]
 * 				   (Indice) OK
 */
int buscarEspacioLibrePassenger(Passenger* list, int len);

/**
 * @brief Agrega a un array de pasajeros los valores recibidos en la primera posicion libre
 *
 * @param list passenger* Array de tipo pasajero
 * @param len int Largo del array
 * @param id int variable de tipo int
 * @param name[] char array de nombre
 * @param lastName[] char array de apellido
 * @param price float variable de tipo float
 * @param typePassenger int variable de tipo int
 * @param flycode[] char array de codigo de vuelo
 * @return int retorna (-1) Error: [Largo invalido, Puntero nulo o Sin espacio libre]
 * 					   ( 0) OK
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/**
 * @brief Da de alta a un pasajero
 *
 * @param list Array de tipo pasajero
 * @param len Largo del array
 * @param id Puntero a int que modificara el valor del id
 * @param ultimoId Puntero a int que guardara el ultimo id dado de alta
 * @return int retorna (-1) Error: [Largo invalido, Puntero nulo o Sin espacio libre]
 * 					   ( 1) OK
 */
int altaPassengers(Passenger* list, int len, int* id, int* ultimoId);

/**
 * @brief Busca un pasajero en un array en base al id recibido y retorna la posicion
 *
 * @param list Passenger* Array de tipo pasajero
 * @param len int Largo de array
 * @param id int ID del pasajero
 * @return Retorna (-1) Error: [Largo no valido o Puntero NULL o Pasajero no encontrado]
 * 				   (Indice) OK: Posicion del pasajero
 */
int findPassengerById(Passenger* list, int len,int id);

/**
 * @brief
 *
 * @param list
 * @param idMinimo
 * @param idMaximo
 * @param ultimoId
 */
void buscarMinimoMaximo(Passenger* list, int* idMinimo,int* idMaximo, int ultimoId);

/**
 * @brief Modifica un pasajero
 *
 * @param list Array de tipo pasajero
 * @param len Largo del array
 * @param opcionMenu Opcion elegida a modificar
 * @param indiceId Indice del ID del pasajero a modificar
 * @return Retorna (-1) Error: [Puntero NULL - Opcion no valida]
 * 				   ( 1) OK
 */
int modificarPassenger(Passenger* pPasajero, int opcionMenu);

/**
 * @brief Permite el ingreso de una opcion de modificacion
 *
 * @param list Array de tipo pasajero
 * @param len Largo del array
 * @param ultimoId Ultimo ID dado de alta
 * @return Retorna (-1) Error: [Puntero NULL - Largo no valido - ID no valido]
 * 				   ( 1) OK
 */
int modificarPassengers(Passenger* list, int len, int ultimoId);

/**
 * @brief Elimina un pasajero en base a su ID poniendo el campo isEmpty en libre
 *
 * @param list Passenger* Array de tipo pasajero
 * @param len int Largo del array
 * @param id int ID del pasajero a eliminar
 * @return int Retorna (-1) Error [Largo invalido o Puntero nulo o No se pudo encontrar el pasajero]
 * 					   ( 0) OK
 */
int removePassenger(Passenger* list, int len, int id);

/**
 * @brief Permite eliminar un pasajero
 *
 * @param list Array de tipo pasajero
 * @param len largo del array
 * @param ultimoId Ultimo ID dado de alta
 * @return Retorna (-1) Error: [Largo invalido o Puntero nulo o ID no valido]
 * 				   ( 1) OK
 */
int bajaPassengers(Passenger* list, int len, int ultimoId);

/**
 * @brief Ordena los elementos del array de pasajeros en base al apellido
 *
 * @param list Passenger* Array de tipo pasajero
 * @param len int Largo del array
 * @param order int Forma de ordenamiento: [1] Ascendente - [0] Descendente
 * @return int Retorna (-1) Error [Largo invalido o Puntero nulo]
 * 					   ( 0) OK
 */
int sortPassengersByName(Passenger* list, int len, int order);

/**
 * @brief Ordena los elementos del array de pasajeros en base al codigo de vuelo y estado de vuelo ACTIVO
 *
 * @param list Passenger* Array de tipo pasajero
 * @param len int Largo del array
 * @param order int Forma de ordenamiento: [1] Ascendente - [0] Descendente
 * @return int Retorna (-1) Error [Largo invalido o Puntero nulo]
 * 					   ( 0) OK
 */
int sortPassengersByCode(Passenger* list, int len, int order);

/**
 * @brief Imprime en pantalla un pasajero
 *
 * @param elemento Elemento del array de pasajeros a imprimir
 */
void printPassenger(Passenger elemento);

/**
 * @brief Imprime en pantalla el array de pasajeros
 *
 * @param list Passenger* Array de tipo pasajero
 * @param length int Largo del array
 * @return int Retorna (-1) Error [Largo invalido o Puntero nulo]
 * 					   ( 1) OK
 */
int printPassengers(Passenger* list, int length);

/**
 * @brief Realiza diferentes informes en base a la opcion ingresada
 *
 * @param list Array de tipo pasajero
 * @param len Largo del array
 * @param contadorAltas Contador de altas dadas para las funciones de calculos
 * @return int Retorna (-1) Error [Largo invalido o Puntero nulo o Contador no valido]
 * 					   ( 1) OK
 */
int informarPassengers(Passenger* list, int len, int contadorAltas);

/**
 * @brief Carga de manera forzada un array de pasajeros y lo imprime
 *
 */
void altaForzadaPassenger();

/**
 * @brief Suma los pasajes ingresados
 *
 * @param list Array de tipo pasajero
 * @param len Largo del array
 * @param pResultado Puntero a float donde se guardara el resultado
 * @return int Retorna (-1) Error [Largo invalido o Punteros nulos]
 * 					   ( 1) OK
 */
int sumarPasajes(Passenger* list,int len, float* pResultado);

/**
 * @brief Calcula el promedio de los pasajes ingresados
 *
 * @param sumaTotal Suma de los pasajes ingresados
 * @param contadorAltas Contador de las altas dadas
 * @param pResultado Puntero a float donde se guardara el resultado
 * @return int Retorna (-1) Error [Largo invalido o Punteros nulos o Contador no valido]
 * 					   ( 1) OK
 */
int promediarPasajes(float sumaTotal, int contadorAltas, float* pResultado);

/**
 * @brief Busca si hay pasajes que superen el promedio
 *
 * @param list Array de tipo pasajero
 * @param len Largo del array
 * @param contPasajeros Puntero a int donde se guardara una cantidad
 * @param promedio Calculo del promedio de los pasajes ingresados
 * @return int Retorna (-1) Error [Largo invalido o Punteros nulos o Promedio no valido]
 * 					   ( 1) OK
 */
int buscarPasajesPromedio(Passenger* list, int len, int* contPasajeros, float promedio);

#endif /* ARRAYPASSENGER_H_ */
