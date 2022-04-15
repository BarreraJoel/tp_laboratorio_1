/*
 * getNumero.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#ifndef GETNUMERO_H_
#define GETNUMERO_H_

/**
 * @brief la funcion permite ingresar un numero flotante
 *
 * @param pNumero es un puntero
 * @param mensaje es un puntero que recibe un mensaje e imprime un mensaje inicial
 * @param mensajeError es un puntero que recibe e imprime un mensaje en caso de error
 * @param minimo es el numero minimo que permite la funcion
 * @param maximo es el numero maximo que permite la funcion
 * @param reintentos es la cantidad de intentos que tiene el usuario
 * @return retorna -1 si la funcion no se ejecuta correctamente, caso contrario retorna 1
 */

int getNumeroFlotante(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* GETNUMERO_H_ */
