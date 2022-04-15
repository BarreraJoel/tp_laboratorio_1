/*
 * calcularCostos.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#ifndef CALCULARCOSTOS_H_
#define CALCULARCOSTOS_H_

/**
 * @brief la funcion que permite calcular el precio con tarjeta de debito
 *
 * @param precioDebitoAero es un puntero que recibe una direccion de memoria
 * @param precioDebitoLatam es un puntero que recibe una direccion de memoria
 * @param precioAerolineas copia el valor de la variable que se le esta pasando
 * @param precioLatam copia el valor de la variable que se le esta pasando
 * @return retorna -1 si la funcion se ejecuta incorrectamente, retorna 1 si se ejecuta bien
 */
int calcularPrecioDebito(float* precioDebitoAero, float* precioDebitoLatam, float precioAerolineas, float precioLatam);

/**
 * @brief la funcion permite calcular el precio con tarjeta de credito
 *
 * @param precioCreditoAero es un puntero que recibe una direccion de memoria
 * @param precioCreditoLatam es un puntero que permite recibir una direccion de memoria
 * @param precioAerolineas copia el valor de la variable que se le pasa
 * @param precioLatam hace una copia del valor de la variable que se le pasa
 * @return retorna -1 si se ejecuta mal la funcion, retorna 1 si se ejecuta bien
 */
int calcularPrecioCredito(float* precioCreditoAero, float* precioCreditoLatam, float precioAerolineas, float precioLatam);

/**
 * @brief permite calcular el precio en comparacion al valor de la criptomoneda Bitcoin
 *
 * @param precioConBitcoinAero es un puntero que recibe una direccion de memoria
 * @param precioConBitcoinLatam es un puntero que recibe una direccion de memoria
 * @param precioAerolineas hace una copia del valor de la variable que se le pasa
 * @param precioLatam hace una copia del valor de la variable que se le pasa
 * @return retorna -1 si se ejecuta mal la funcion, caso contrario retorna 1
 */
int calcularPrecioConBitcoin(float* precioConBitcoinAero, float* precioConBitcoinLatam, float precioAerolineas, float precioLatam);

/**
 * @brief permite calcular el precio unitario
 *
 * @param precioUnitarioAero es un puntero que recibe una direccion de memoria
 * @param precioUnitarioLatam es un puntero que recibe una direccion de memoria
 * @param km copia el valor de la variable que se le pasa
 * @param precioAerolineas copia el valor de la variable que se le pasa
 * @param precioLatam copia el valor de la variable que se le pasa
 * @return retorna -1 si se ejecuto mal la funcion, si se ejecuta bien retorna 1
 */
int calcularPrecioUnitario(float* precioUnitarioAero, float* precioUnitarioLatam , float km, float precioAerolineas, float precioLatam);

/**
 * @brief permite calcular la diferencia de precio entre dos valores
 *
 * @param diferenciaPrecio es un puntero que recibe una direccion de memoria
 * @param precioAerolineas copia el valor de la variable que se le pasa
 * @param precioLatam copia el valor de la variable que se le pasa
 * @return retorna -1 si la funcion no se ejecuto bien, si se ejecuta bien retorna 1
 */
int calcularDiferenciaPrecio(float* diferenciaPrecio, float precioAerolineas, float precioLatam);


#endif /* CALCULARCOSTOS_H_ */
