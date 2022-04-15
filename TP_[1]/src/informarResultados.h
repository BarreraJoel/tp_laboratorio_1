/*
 * informarResultados.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#ifndef INFORMARRESULTADOS_H_
#define INFORMARRESULTADOS_H_

/**
 * @brief informa los resultados de los calculos de los costos
 *
 * @param km copia el valor de la variable de los kilometros ingresados
 * @param precioAerolineas copia el valor de la variable del precio de la aerolinea
 * @param precioLatam copia el valor de la variable del precio de la aerolinea
 * @param precioDebitoAero copia el valor de la variable con el calculo realizado
 * @param precioCreditoAero copia el valor de la variable con el calculo realizado
 * @param precioConBitcoinAero copia el valor de la variable con el calculo realizado
 * @param precioUnitarioAero copia el valor de la variable con el calculo realizado
 * @param precioDebitoLatam copia el valor de la variable con el calculo realizado
 * @param precioCreditoLatam copia el valor de la variable con el calculo realizado
 * @param precioConBitcoinLatam copia el valor de la variable con el calculo realizado
 * @param precioUnitarioLatam copia el valor de la variable con el calculo realizado
 * @param diferenciaPrecio copia el valor de la variable con el calculo realizado
 */
void informarResultados(float km, float precioAerolineas, float precioLatam, float precioDebitoAero, float precioCreditoAero, float precioConBitcoinAero, float precioUnitarioAero, float precioDebitoLatam, float precioCreditoLatam, float precioConBitcoinLatam, float precioUnitarioLatam, float diferenciaPrecio);


#endif /* INFORMARRESULTADOS_H_ */
