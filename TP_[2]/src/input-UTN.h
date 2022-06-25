/*
 * utn.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#ifndef INPUT_UTN_H_
#define INPUT_UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Recibe un numero entero y lo valida
 *
 * @param pResultado puntero a variable de tipo int
 * @param mensaje que se imprime para que un usuario ingrese un numero entero
 * @param mensajeError mensaje que se imprime cuando un usuario ingreso algo no valido
 * @param minimo int cantidad minima que se puede ingresar
 * @param maximo int cantidad maxima que se puede ingresar
 * @param reintentos int cantidad de intentos que tiene el usuario
 * @return int (-1) si ya no hay intentos, (1) si se ejecuto bien
 */
int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * @brief Recibe un numero decimal y lo valida
 *
 * @param pResultado puntero a variable de tipo float
 * @param mensaje que se imprime para que un usuario ingrese un numero flotante
 * @param mensajeError mensaje que se imprime cuando un usuario ingreso algo no valido
 * @param minimo float cantidad minima que se puede ingresar
 * @param maximo float cantidad maxima que se puede ingresar
 * @param reintentos int cantidad de intentos que tiene el usuario
 * @return int (-1) si ya no hay intentos, (1) si se ejecuto bien
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * @brief Recibe caracter ingresado por un usuario y lo valida
 *
 * @param pResultado puntero a variable de tipo char
 * @param mensaje que se imprime para que un usuario ingrese un caracter
 * @param mensajeError mensaje que se imprime cuando un usuario ingreso algo no valido
 * @param minimo
 * @param maximo
 * @param reintentos int cantidad de intentos que tiene el usuario
 * @return int (-1) si ya no hay intentos, (1) si se ejecuto bien
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
/**
 * @brief Recibe un texto y lo valida
 *
 * @param cadena puntero al array del texto
 * @param mensaje que se imprime para que un usuario ingrese el texto
 * @param mensajeError mensaje que se imprime cuando un usuario ingreso algo no valido
 * @param minimo int cantidad minima de caracteres que se puede ingresar
 * @param maximo int cantidad maxima de caracteres que se puede ingresar
 * @param reintentos int cantidad de intentos que tiene el usuario
 * @return int (-1) si ya no hay intentos, (1) si se ejecuto bien
 */
int utn_getTexto(char* cadena, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * @brief Recibe un nombre o apellido y lo valida
 *
 * @param cadena puntero al array del nombre o apellido
 * @param mensaje que se imprime para que un usuario ingrese nombre o apellido
 * @param mensajeError mensaje que se imprime cuando un usuario ingreso algo no valido
 * @param minimo int cantidad minima de caracteres que se puede ingresar
 * @param maximo int cantidad maxima de caracteres que se puede ingresar
 * @param reintentos int cantidad de intentos que tiene el usuario
 * @return int (-1) si ya no hay intentos, (1) si se ejecuto bien
 */
int utn_getNombre(char* cadena, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * @brief Recibe una calle y la valida
 *
 * @param cadena puntero al array de calle
 * @param mensaje que se imprime para que un usuario ingrese una calle
 * @param mensajeError mensaje que se imprime cuando un usuario ingreso algo no valido
 * @param minimo int cantidad minima de caracteres que se puede ingresar
 * @param maximo int cantidad maxima de caracteres que se puede ingresar
 * @param reintentos int cantidad de intentos que tiene el usuario
 * @return Retorna -1 [Sin intentos] - 1 [OK]
 */
int utn_getCalle(char* cadena, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * @brief Recibe un telefono y lo valida
 *
 * @param cadena puntero al array de calle
 * @param limite Largo del array
 * @param mensaje que se imprime para que un usuario ingrese una calle
 * @param mensajeError mensaje que se imprime cuando un usuario ingreso algo no valido
 * @param reintentos cantidad de intentos que tiene el usuario
 * @return Retorna -1 [Sin intentos] - 1 [OK]
 */
int utn_getTelefono(char* cadena, int limite, char* mensaje, char* mensajeError, int reintentos);













#endif /* INPUT_UTN_H_ */
