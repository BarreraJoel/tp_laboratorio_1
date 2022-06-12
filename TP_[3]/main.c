#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input-UTN.h"

int main()
{
	setbuf(stdout, NULL);
    int option;
    int contAltas = 0;
    int banderaOpcionUno = 0;
    int banderaOpcionTres = 0;
    int banderaOpcionOcho = 0;
    int banderaOpcionNueve = 0;
    int confirmacion;
    LinkedList* listaPasajeros = ll_newLinkedList();

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
                	if(contAltas > 0)
                	{
                		if(utn_getNumeroEntero(&confirmacion,"\n*** ADVERTENCIA ***\nLos pasajeros dados de alta cambiaran de ID"
															 "\nDesea continuar?\n1.SI\n2.NO\nElija una opcion: ","\nLa opcion ingresada no es valida",1,2,3) == 1 &&
                											 confirmacion == 1)
						{
                			if(controller_reordenarID(listaPasajeros) == 1)
                			{
                                if(controller_loadFromText("data.csv",listaPasajeros) == 1)
                                {
                                	banderaOpcionUno = 1;
                                	printf("\n*** Se cargo la lista de pasajeros con exito (txt) ***\n");
                                }
                			}
						}
                	}
                	else
                	{
                        if(controller_loadFromText("data.csv",listaPasajeros) == 1)
                        {
                        	banderaOpcionUno = 1;
                        	printf("\n*** Se cargo la lista de pasajeros con exito (txt) ***\n");
                        }
                	}
                    break;
                case 2:
                	if(controller_loadFromBinary("dataDos.bin", listaPasajeros) == 1)
                	{
                    	printf("\n*** Se cargo la lista de pasajeros con exito (bin) ***\n");
                	}
                	break;
                case 3:
                	if(controller_addPassenger(listaPasajeros) == 1)
                	{
                		contAltas++;
                		banderaOpcionTres = 1;
                    	printf("\n*** La carga se realizo con exito ***\n");
                	}
                	break;
                case 4:
                	if(banderaOpcionUno == 1 || banderaOpcionTres == 1)
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
                	if(banderaOpcionUno == 1 || banderaOpcionTres == 1)
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
                	controller_ListPassenger(listaPasajeros);
                	break;
                case 7:
                	//controller_sortPassenger(listaPasajeros);
                	break;
                case 8:
                	if(controller_saveAsText("dataDos.csv", listaPasajeros) == 1)
    				{
                		banderaOpcionOcho = 1;
                    	printf("\n*** Se guardo la lista de pasajeros con exito (txt) ***\n");
    				}
                	break;
                case 9:
                	if(controller_saveAsBinary("dataDos.bin", listaPasajeros) == 1)
                	{
                		banderaOpcionNueve = 1;
                    	printf("\n*** Se guardo la lista de pasajeros con exito (bin) ***\n");
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








