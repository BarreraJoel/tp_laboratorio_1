/*
 * imprimirDatosForzados.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Joel Barrera
 */

#include "calcularCostos.h"
#include "informarResultados.h"

void cargarDatosForzados()
{
	float kmForzado;
	float precioAerolineasForzado;
	float precioLatamForzado;
	float precioDebitoAero;
	float precioCreditoAero;
	float precioConBitcoinAero;
	float precioUnitarioAero;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioConBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecio;

	kmForzado = 7090;
	precioAerolineasForzado = 162965;
	precioLatamForzado = 159339;

	calcularPrecioDebito(&precioDebitoAero, &precioDebitoLatam, precioAerolineasForzado, precioLatamForzado);
	calcularPrecioCredito(&precioCreditoAero, &precioCreditoLatam, precioAerolineasForzado, precioLatamForzado);
	calcularPrecioConBitcoin(&precioConBitcoinAero, &precioConBitcoinLatam, precioAerolineasForzado, precioLatamForzado);
	calcularPrecioUnitario(&precioUnitarioAero, &precioUnitarioLatam , kmForzado, precioAerolineasForzado, precioLatamForzado);
	calcularDiferenciaPrecio(&diferenciaPrecio, precioAerolineasForzado, precioLatamForzado);

	informarResultados(kmForzado, precioAerolineasForzado, precioLatamForzado, precioDebitoAero, precioCreditoAero, precioConBitcoinAero, precioUnitarioAero, precioDebitoLatam, precioCreditoLatam, precioConBitcoinLatam, precioUnitarioLatam, diferenciaPrecio);
}
