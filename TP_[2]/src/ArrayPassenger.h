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
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1
#define MAX_TEXTO 51

typedef struct{
	int statusFlight;
	char descripcion[20];
}statusFlight;

typedef struct{
	int typePassenger;
	char descripcion[20];
}typePassenger;

typedef struct{
	int id;
	char name[MAX_TEXTO];
	char lastName[MAX_TEXTO];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

/**
 * @brief esta funcion inicializa el array de pasajeros
 *
 *
 * @param list Passenger* puntero a un array de pasajero
 * @param len int Array length
 * @return int retorna (-1) si hubo error [largo invalido o puntero nulo] - (0) si se ejecuto bien
 */
int initPassengers(Passenger* list, int len);

/**
 * @brief busca el primer espacio libre del array
 *
 * @param list array de una estructura
 * @param len largo del array
 * @return el indice del array en el que hay un espacio libre
 */
int buscarEspacioLibrePassenger(Passenger list[], int len);

/**
 * @brief esta funcion da de alta a un pasajero
 *
 * @param list array de una estructura
 * @param len largo del array
 * @return retorna 1 si se ejecuto bien, -1 si hubo error
 */
int altaPassengers(Passenger list[], int len);

/**
 * @brief agrega a un array de pasajeros los valores recibidos en la primera posicion libre
 *
 * @param list passenger* puntero a un array pasajeros
 * @param len int largo del array
 * @param id int variable de tipo int
 * @param name[] char array de nombre
 * @param lastName[] char array de apellido
 * @param price float variable de tipo float
 * @param typePassenger int variable de tipo int
 * @param flycode[] char array de codigo de vuelo
 * @return int retorna (-1) si hubo error [largo invalido, puntero nulo o sin espacio libre] - (0) si se ejecuto bien
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/**
 * @brief busca un pasajero en un array en base al id recibido y retorna la posicion
 *
 * @param list Passenger* puntero a un array de pasajeros
 * @param len int largo de array
 * @param id int id del pasajero
 * @return retorna passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
 */
int findPassengerById(Passenger* list, int len,int id);

/**
 * @brief modifica un pasajero
 *
 * @param list array de estructura pasajero
 * @param len largo del array
 * @param opcionMenu opcion elegida por el usuario
 * @param indiceId indice del id del pasajero a modificar
 * @return 1 si se ejecuto bien, si hubo error -1
 */
int modificarPassenger(Passenger list[], int len, int opcionMenu, int indiceId);

/**
 * @brief funcion que llama a otros procedimientos para modificar pasajeros
 *
 * @param list array de estructura pasajero
 * @param len largo del array
 * @param contAltas contador de altas dadas
 * @return 1 si se ejecuto bien, si hubo error -1
 */
int modificarPassengers(Passenger list[], int len, int contAltas);

/**
 * @brief elimina un pasajero en base a su Id poniendo el campo isEmpty en libre
 *
 * @param list Passenger* puntero a un array de pasajeros
 * @param len int largo del array
 * @param id int id del pasajero
 * @return int retorna (-1) si hubo error [largo invalido o puntero nulo o no se pudo encontrar el pasajero] - (0) si se ejecuto bien
 */
int removePassenger(Passenger* list, int len, int id);

/**
 * @brief funcion principal para eliminar un pasajero
 *
 * @param list Passenger* puntero a un array de pasajeros
 * @param len largo del array
 * @param contador contador de altas dadas
 * @return 1 si se ejecuto bien, -1 si hubo error
 */
int bajaPassengers(Passenger* list, int len, int contador);


/**
 * @brief ordena los elementos del array de pasajeros en base al apellido, el argumento order indica la forma de ordenamiento
 *
 * @param list Passenger* puntero a un array de pasajeros
 * @param len int largo del array
 * @param order int [1] indica arriba - [0] indica abajo
 * @return int retorna (-1) si hubo error [largo invalido o puntero nulo] - (0) si se ejecuto bien
 */
int sortPassengersByName(Passenger* list, int len, int order);

/**
 * @brief imprime en pantalla un pasajero
 *
 * @param list puntero a un array de pasajeros
 * @param length largo del array
 * @param id es el id del pasajero a imprimir
 * @return 1 si se ejecuto bien, -1 si hubo error
 */
int printPassenger(Passenger* list, int length, int id);

/**
 * @brief imprime en pantalla el array de pasajeros
 *
 * @param list Passenger* puntero a un array de pasajeros
 * @param length int largo del array
 * @return int 1 si se ejecuto bien, -1 si hubo error
 */
int printPassengers(Passenger* list, int length);

/**
 * @brief ordena los elementos del array de pasajeros en base al codigo de vuelo, el argumento order indica la forma de ordenamiento
 *
 * @param list Passenger* puntero a un array de pasajeros
 * @param len int largo del array
 * @param order int [1] indica arriba - [0] indica abajo
 * @return int retorna (-1) si hubo error [largo invalido o puntero nulo] - (0) si se ejecuto bien
 */
int sortPassengersByCode(Passenger* list, int len, int order);

/**
 * @brief funcion principal para ordenar el array
 *
 * @param list puntero a un array de pasajeros
 * @param len largo del array
 * @return retorna 1 si se ejecuto bien, -1 si hubo error
 */
int ordenarPassengers(Passenger* list, int len, int contadorAltas);


/**
 * @brief carga de manera forzada un array de pasajeros
 *
 */
void altaForzadaPassenger();

/**
 * @brief suma los pasajes ingresados
 *
 * @param list array de pasajero
 * @param len largo del array
 * @param pResultado puntero a variable tipo float
 * @return retorna 1 si se ejecuto bien, -1 si hubo error
 */
int sumarPasajes(Passenger list[],int len, float* pResultado);

/**
 * @brief calcula el promedio de los pasajes ingresados
 *
 * @param sumaTotal suma de los pasajes ingresados
 * @param contadorAltas contador de las altas dadas
 * @param pResultado puntero a variable tipo float
 * @return retorna 1 si se ejecuto bien, -1 si hubo error
 */
int promediarPasajes(float sumaTotal, int contadorAltas, float* pResultado);

/**
 * @brief busca si hay pasajes que superen el promedio
 *
 * @param list puntero a array de estructura
 * @param len largo del array
 * @param contPasajeros contador de pasajeros
 * @param promedio promedio calculado de los pasajes ingresados
 * @return retorna 1 si se ejecuto bien, -1 si hubo error
 */
int buscarPasajesPromedio(Passenger* list, int len, int* contPasajeros, float promedio);

#endif /* ARRAYPASSENGER_H_ */
