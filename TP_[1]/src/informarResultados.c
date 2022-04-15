/*
 * informarResultados.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>

void informarResultados(float km, float precioAerolineas, float precioLatam, float precioDebitoAero, float precioCreditoAero, float precioConBitcoinAero, float precioUnitarioAero, float precioDebitoLatam, float precioCreditoLatam, float precioConBitcoinLatam, float precioUnitarioLatam, float diferenciaPrecio)
{
	printf("\nKilometros ingresados: %.2f\n", km);
	printf("\nPrecio Aerolineas: $ %.2f", precioAerolineas);
	printf("\na)Precio con tarjeta de debito: $ %.2f", precioDebitoAero);
	printf("\nb)Precio con tarjeta de credito: $ %.2f", precioCreditoAero);
	printf("\nc)Precio pagando con bitcoin: %.2f BTC", precioConBitcoinAero);
	printf("\nd)Precio unitario: $ %.2f", precioUnitarioAero);
	printf("\n\nPrecio Latam: $ %.2f", precioLatam);
	printf("\na)Precio con tarjeta de debito: $ %.2f", precioDebitoLatam);
	printf("\nb)Precio con tarjeta de credito: $ %.2f", precioCreditoLatam);
	printf("\nc)Precio pagando con bitcoin: %.2f BTC", precioConBitcoinLatam);
	printf("\nd)Precio unitario: $ %.2f", precioUnitarioLatam);
	printf("\n\nLa diferencia de precio es: $ %.2f\n", diferenciaPrecio);
}
