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
 * @brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * @param list Passenger* Pointer to array of passenger
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initPassengers(Passenger* list, int len);

/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int buscarEspacioLibrePassenger(Passenger list[], int len);

/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int altaPassengers(Passenger* list, int len);

/**
 * @brief add in a existing list of passengers the values received as parameters* in the first empty position
 *
 * @param list passenger*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param price float
 * @param typePassenger int
 * @param flycode[] char
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/**
 * @brief find a Passenger by Id en returns the index position in array.
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
 */
int findPassengerById(Passenger* list, int len,int id);

/**
 * @brief
 *
 * @param list
 * @param len
 * @param opcionMenu
 * @param indiceId
 * @return
 */
int modificarPassenger(Passenger list[], int len, int opcionMenu, int indiceId);

/**
 * @brief
 *
 * @param list
 * @param len
 * @param contAltas
 * @return
 */
int modificarPassengers(Passenger list[], int len, int contAltas);

/**
 * @brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * @param list Passenger*
 * @param len int
 * @param id int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 */
int removePassenger(Passenger* list, int len, int id);

/**
 * @brief
 *
 * @param list
 * @param len
 * @param contador
 * @return
 */
int bajaPassengers(Passenger* list, int len, int contador);


/**
 * @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * @param list Passenger*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersByName(Passenger* list, int len, int order);

/**
 * @brief
 *
 * @param list
 * @param length
 * @param id
 * @return
 */
int printPassenger(Passenger* list, int length, int id);

/**
 * @brief print the content of passengers array
 *
 * @param list Passenger*
 * @param length int
 * @return int
 */
int printPassengers(Passenger* list, int length);

/**
 * @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * @param list Passenger*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersByCode(Passenger* list, int len, int order);

/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int ordenarPassengers(Passenger* list, int len);


/**
 * @brief
 *
 */
void altaForzadaPassenger();


#endif /* ARRAYPASSENGER_H_ */
