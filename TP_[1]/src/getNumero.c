/*
 * getNumero.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>

int getNumeroFlotante(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno;
	float numero;

	while(reintentos>0)
	{
		printf(mensaje);

		if(scanf("%f",&numero)==1)
		{
			if(numero <= maximo && numero >= minimo)
			{
				break;
			}
		}
		fflush(stdin);

		reintentos--;
		printf(mensajeError);
	}

	if(reintentos==0)
	{
		retorno = -1;
	}
	else
	{
		retorno = 1;
		*pNumero = numero;
	}
	return retorno;
}
