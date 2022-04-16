/*
 * confirmarDatos.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>

int confirmar(char* confirmacion)
{
	int retorno;

	retorno = -1;
	if(confirmacion != NULL)
	{
		printf("\nConfirma el dato ingresado? s(si) o n(no) : ");
		fflush(stdin);
		scanf("%c", confirmacion);
		while(*confirmacion != 's' && *confirmacion != 'n')
		{
			printf("\nIngrese una opcion valida s(si) o n(no) : ");
			fflush(stdin);
			scanf("%c", confirmacion);
		}
		retorno = 1;
	}
	return retorno;
}
