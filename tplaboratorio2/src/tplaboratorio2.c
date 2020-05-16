/*
 ============================================================================
 Name        : tplaboratorio2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employees.h"
#include "utn.h"

#define QTY_EMPLOYEES 1000

int main(void)
{
	setbuf(stdout,NULL);
	Employee arrayEmployees[QTY_EMPLOYEES];
	int menuOption;
	int index;
	int idEmployees = 0;
	int auxId;
	int order;

	if(initEmployees(arrayEmployees,QTY_EMPLOYEES) == 0)
	{
		printf("\nArray de empleados inicializado correctamente.\n");
	}

	addEmployeesForzada(arrayEmployees,QTY_EMPLOYEES,&idEmployees,"Eugenia","Deronace",10000,22,0);
	addEmployeesForzada(arrayEmployees,QTY_EMPLOYEES,&idEmployees,"Nicolas","Aranzazu",10000,25,1);
	addEmployeesForzada(arrayEmployees,QTY_EMPLOYEES,&idEmployees,"Camila","Conzalez",10000,23,2);
	addEmployeesForzada(arrayEmployees,QTY_EMPLOYEES,&idEmployees,"Ariel","Bagostino",50000,28,3);

	do
	{
		if(!utn_getNumero(&menuOption,
						 "\n\nElija una opción:\n"
						 "\n1.Dar de alta un empleado."
						 "\n2.Modificar un empleado."
						 "\n3.Dar de baja un empleado."
						 "\n4.Informar listado de empleados, total y promedio de sus salarios."

						 "\n5.Salir.\n\n",

						 "Error, no es una opción válida",1,5,1) )
		{
			switch(menuOption)
			{
				case 1:
					index = getEmptyIndex(arrayEmployees,QTY_EMPLOYEES);
					if(index >= 0)
					{
						if( !addEmployees(arrayEmployees,QTY_EMPLOYEES,index,&idEmployees))
						{
							printf("\nCarga realizada con éxito.\n");
						}
					}
					break;
				case 2:
					printEmployees(arrayEmployees,QTY_EMPLOYEES);
					if(!utn_getNumero(&auxId,"\nIngrese ID del cliente a modificar:\n","Error, el ID ingresado no existe",0,idEmployees,0))
					{
						index = findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxId);
						if(index >= 0)
						{
							modifyEmployee(arrayEmployees,QTY_EMPLOYEES,index);
						}
					}
				break;
				case 3:
					printEmployees(arrayEmployees,QTY_EMPLOYEES);
					if(!utn_getNumero(&auxId,"\nIngrese ID del cliente a dar de baja:\n","Error, el ID ingresado no existe",0,idEmployees,0))
					{
						if(!removeEmployee(arrayEmployees,QTY_EMPLOYEES,auxId))
						{
							printf("\nEl cliente ha sido dado de baja con éxito.");
						}
					}
				break;
				case 4:
					if(!utn_getNumero(&order,"¿De qué manera desea ordenar su lista de empleados? [1]ASCENDENTE [0]DESCENDENTE \n","Opción inválida",0,1,0))
					{
						if(!sortEmployees(arrayEmployees,QTY_EMPLOYEES,order))
						{
							printEmployees(arrayEmployees,QTY_EMPLOYEES);
						}
						imprimeTotalSalariosYSuPromedio(arrayEmployees,QTY_EMPLOYEES);
					}
					break;
			}
		}

	}while(menuOption != 5);

	return EXIT_SUCCESS;
}
