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
 * @param pPrecioDebitoAero es un puntero que recibe una direccion de memoria
 * @param pPrecioDebitoLatam es un puntero que recibe una direccion de memoria
 * @param precioAerolineas copia el valor de la variable que se le esta pasando
 * @param precioLatam copia el valor de la variable que se le esta pasando
 * @return retorna -1 si la funcion se ejecuta incorrectamente, retorna 1 si se ejecuta bien
 */
int calcularPrecioDebito(float* pPrecioDebitoAero, float* pPrecioDebitoLatam, float precioAerolineas, float precioLatam);

/**
 * @brief la funcion permite calcular el precio con tarjeta de credito
 *
 * @param pPrecioCreditoAero es un puntero que recibe una direccion de memoria
 * @param pPrecioCreditoLatam es un puntero que permite recibir una direccion de memoria
 * @param precioAerolineas copia el valor de la variable que se le pasa
 * @param precioLatam hace una copia del valor de la variable que se le pasa
 * @return retorna -1 si se ejecuta mal la funcion, retorna 1 si se ejecuta bien
 */
int calcularPrecioCredito(float* pPrecioCreditoAero, float* pPrecioCreditoLatam, float precioAerolineas, float precioLatam);

/**
 * @brief permite calcular el precio en comparacion al valor de la criptomoneda Bitcoin
 *
 * @param pPrecioConBitcoinAero es un puntero que recibe una direccion de memoria
 * @param pPrecioConBitcoinLatam es un puntero que recibe una direccion de memoria
 * @param precioAerolineas hace una copia del valor de la variable que se le pasa
 * @param precioLatam hace una copia del valor de la variable que se le pasa
 * @return retorna -1 si se ejecuta mal la funcion, caso contrario retorna 1
 */
int calcularPrecioConBitcoin(float* pPrecioConBitcoinAero, float* pPrecioConBitcoinLatam, float precioAerolineas, float precioLatam);

/**
 * @brief permite calcular el precio unitario
 *
 * @param pPrecioUnitarioAero es un puntero que recibe una direccion de memoria
 * @param pPrecioUnitarioLatam es un puntero que recibe una direccion de memoria
 * @param km copia el valor de la variable que se le pasa
 * @param precioAerolineas copia el valor de la variable que se le pasa
 * @param precioLatam copia el valor de la variable que se le pasa
 * @return retorna -1 si se ejecuto mal la funcion, si se ejecuta bien retorna 1
 */
int calcularPrecioUnitario(float* pPrecioUnitarioAero, float* pPrecioUnitarioLatam , float km, float precioAerolineas, float precioLatam);

/**
 * @brief permite calcular la diferencia de precio entre dos valores
 *
 * @param pDiferenciaPrecio es un puntero que recibe una direccion de memoria
 * @param precioAerolineas copia el valor de la variable que se le pasa
 * @param precioLatam copia el valor de la variable que se le pasa
 * @return retorna -1 si la funcion no se ejecuto bien, si se ejecuta bien retorna 1
 */
int calcularDiferenciaPrecio(float* pDiferenciaPrecio, float precioAerolineas, float precioLatam);


#endif /* CALCULARCOSTOS_H_ */
