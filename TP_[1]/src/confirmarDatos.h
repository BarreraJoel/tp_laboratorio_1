/*
 * confirmarDatos.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Joel Barrera
 */

#ifndef CONFIRMARDATOS_H_
#define CONFIRMARDATOS_H_

/**
 * @brief pregunta al usuario si el dato ingresado es correcto
 *
 * @param confirmacion es un puntero que modifica la variable de la funcion main
 * @return retorna -1 si la funcion no se ejecuto bien, de ejecutarse bien retorna 1
 */
int confirmar(char* confirmacion);

#endif /* CONFIRMARDATOS_H_ */
