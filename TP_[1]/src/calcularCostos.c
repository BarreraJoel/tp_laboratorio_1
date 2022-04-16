/*
 * calcularCostos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>

#define DESCUENTO 10
#define INTERES 25

int calcularPrecioDebito(float* pPrecioDebitoAero, float* pPrecioDebitoLatam, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(pPrecioDebitoAero != NULL && pPrecioDebitoLatam != NULL)
	{
		*pPrecioDebitoAero = precioAerolineas - precioAerolineas * DESCUENTO/100;
		*pPrecioDebitoLatam = precioLatam - precioLatam * DESCUENTO/100;
		retorno = 1;
	}

	return retorno;
}

int calcularPrecioCredito(float* pPrecioCreditoAero, float* pPrecioCreditoLatam, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(pPrecioCreditoAero != NULL && pPrecioCreditoLatam != NULL)
	{
		*pPrecioCreditoAero = precioAerolineas + precioAerolineas * INTERES / 100;
		*pPrecioCreditoLatam = precioLatam + precioLatam * INTERES / 100;
		retorno = 1;
	}

	return retorno;
}

int calcularPrecioConBitcoin(float* pPrecioConBitcoinAero, float* pPrecioConBitcoinLatam, float precioAerolineas, float precioLatam)
{
	int retorno;
	float precioBitcoin;

	retorno = -1;
	precioBitcoin = 4606954.55;

	if(pPrecioConBitcoinAero != NULL && pPrecioConBitcoinLatam != NULL)
	{
		*pPrecioConBitcoinAero = precioAerolineas / precioBitcoin;
		*pPrecioConBitcoinLatam = precioLatam / precioBitcoin;
		retorno = 1;
	}

	return retorno;
}

int calcularPrecioUnitario(float* pPrecioUnitarioAero, float* pPrecioUnitarioLatam , float km, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(pPrecioUnitarioAero != NULL && pPrecioUnitarioLatam != NULL)
	{
		*pPrecioUnitarioAero = precioAerolineas / km;
		*pPrecioUnitarioLatam = precioLatam / km;
		retorno = 1;
	}

	return retorno;
}

int calcularDiferenciaPrecio(float* pDiferenciaPrecio, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(pDiferenciaPrecio != NULL)
	{
		if(precioLatam > precioAerolineas)
		{
			*pDiferenciaPrecio = precioLatam - precioAerolineas;
		}
		else
		{
			*pDiferenciaPrecio = precioAerolineas - precioLatam;
		}
		retorno = 1;
	}

	return retorno;
}
