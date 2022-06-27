#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input-UTN.h"

int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();
    int option;
    int contAltas = 0;
    int banderaOpcionUno = 0;
    int banderaOpcionDos = 0;
    int banderaOpcionTres = 0;
    int banderaOpcionOcho = 0;
    int banderaOpcionNueve = 0;

    do
    {
    	if(utn_getNumeroEntero(&option, "\n\n*************************** MENU DE OPCIONES ********************************\n"
										"\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
										"\n2. Cargar los datos de los pasajeros desde el archivo dataDos.bin (modo binario)."
										"\n3. Alta de pasajero"
										"\n4. Modificar datos de pasajero"
										"\n5. Baja de pasajero"
										"\n6. Listar pasajeros"
										"\n7. Ordenar pasajeros"
										"\n8. Guardar los datos de los pasajeros en el archivo dataDos.csv (modo texto)."
										"\n9. Guardar los datos de los pasajeros en el archivo dataDos.bin (modo binario)."
										"\n10. Salir"
										"\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n",1,10,3) == 1)
    	{
            switch(option)
            {
                case 1:
                	if(banderaOpcionUno == 0 && banderaOpcionDos == 0)
                	{
                		if(banderaOpcionTres == 1)
                		{
        					if(controller_loadFromText("data.csv",listaPasajeros) == 1)
        					{
        						printf("\n*** Se cargo la lista de pasajeros con exito (txt) ***\n");
        						banderaOpcionUno = 1;
        					}
                		}
                		else
                		{
        					if(controller_loadFromText("data.csv",listaPasajeros) == 1)
        					{
        						printf("\n*** Se cargo la lista de pasajeros con exito (txt) ***\n");
        						banderaOpcionUno = 1;
        					}
                		}
                	}
                	else
                	{
                		printf("\n*** El archivo ya se cargo antes ***");
                	}
                    break;
                case 2:
                	if(banderaOpcionUno == 0 && banderaOpcionDos == 0)
                	{
                    	if(controller_loadFromBinary("dataDos.bin", listaPasajeros) == 1)
                    	{
                        	printf("\n*** Se cargo la lista de pasajeros con exito (bin) ***\n");
                        	banderaOpcionDos = 1;
                    	}
                	}
                	else
                	{
                		printf("\n*** El archivo ya se cargo antes ***");
                	}
                	break;
                case 3:
                	if(controller_addPassenger(listaPasajeros) == 1)
                	{
                		contAltas++;
                		banderaOpcionTres = 1;
                    	printf("\n*** El alta se realizo con exito ***\n");
                	}
                	break;
                case 4:
                	if(banderaOpcionUno == 1 || banderaOpcionDos == 1 || banderaOpcionTres == 1 || contAltas > 0)
                	{
                    	if(controller_editPassenger(listaPasajeros) == 1)
                    	{
                        	printf("\n*** La modificacion se realizo con exito ***\n");
                    	}
                	}
                	else
                	{
                    	printf("\n*** Debe cargar datos para poder modificarlos ***\n");
                	}
                	break;
                case 5:
                	if(banderaOpcionUno == 1 || banderaOpcionDos == 1 || banderaOpcionTres == 1 || contAltas > 0)
                	{
                    	if(controller_removePassenger(listaPasajeros) == 1)
                    	{
                    		contAltas--;
                        	printf("\n*** La baja se realizo con exito ***\n");
                    	}
                	}
                	else
                	{
                    	printf("\n*** Debe cargar datos para poder eliminarlos ***\n");
                	}
                	break;
                case 6:
                	if(banderaOpcionUno == 1 || banderaOpcionDos == 1 || banderaOpcionTres == 1 || contAltas > 0)
                	{
                    	controller_ListPassenger(listaPasajeros);
                	}
                	else
                	{
                    	printf("\n*** Primero debe cargar datos ***\n");
                	}
                	break;
                case 7:
                	if(banderaOpcionUno == 1 || banderaOpcionDos == 1 || banderaOpcionTres == 1 || contAltas > 0)
                	{
                    	if(controller_sortPassenger(listaPasajeros) == 1)
                    	{
                        	printf("\n*** Se ordeno la lista ***\n");
                    	}
                	}
                	else
                	{
                    	printf("\n*** Debe cargar datos para poder ordenarlos ***\n");
                	}
                	break;
                case 8:
                	if(banderaOpcionUno == 1 || banderaOpcionDos == 1 || contAltas > 0)
                	{
                    	if(controller_saveAsText("dataDos.csv", listaPasajeros) == 1)
        				{
                        	printf("\n*** Se guardo la lista de pasajeros con exito (txt) ***\n");
                    		banderaOpcionOcho = 1;
        				}
                	}
                	else
                	{
                    	printf("\n*** Primero debe cargar datos ***\n");
                	}
                	break;
                case 9:
                	if(banderaOpcionUno == 1 || banderaOpcionDos == 1 || contAltas > 0)
                	{
                    	if(controller_saveAsBinary("dataDos.bin", listaPasajeros) == 1)
                    	{
                        	printf("\n*** Se guardo la lista de pasajeros con exito (bin) ***\n");
                    		banderaOpcionNueve = 1;
                    	}
                	}
                	else
                	{
                    	printf("\n*** Primero debe cargar datos ***\n");
                	}
                	break;
                case 10:
                	if(banderaOpcionOcho == 1 || banderaOpcionNueve == 1)
                	{
                    	ll_deleteLinkedList(listaPasajeros);
                    	printf("\n*** Se elimino la lista de pasajeros con exito ***\n");
                	}
                	else
                	{
                		printf("\n*** Debe realizar por lo menos un guardado de archivo ***\n");
                	}
                	break;
                default:
                	break;
            }
    	}
    }while(option != 10);
    return 0;
}









