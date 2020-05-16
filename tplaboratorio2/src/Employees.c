/*
 * Employees.c
 *
 *  Created on: 13 may. 2020
 *      Author: Eugenia
 */

#include "Employees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"


/** \brief  To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 *         position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Find the first empty position
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int getEmptyIndex(Employee* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/** \brief add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param list employee*
 * \param len int
 * \param id int*
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \param indice int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployeesForzada(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice)
{
	Employee bufferEmployee;
	int retorno = -1;
	if(list != NULL && len > 0 && id >= 0 && name != NULL && lastName != NULL && salary >= 0 && sector >= 0 && indice >= 0 && indice < len)
	{
		bufferEmployee.sector = sector;
		bufferEmployee.salary = salary;
		strncpy(bufferEmployee.name,name,NAME_LEN);
		strncpy(bufferEmployee.lastName,lastName,LASTNAME_LEN);
		bufferEmployee.id = *id;
		bufferEmployee.isEmpty = 0;
		list[indice] = bufferEmployee;
		retorno = 0;
		(*id)++;
	}
	return retorno;
}


/**
 * \brief Register an employee in an array position
 * \param list employee*
 * \param len int
 * \param index Position to be updated
 * \param id Identifier to be assigned
 * \return return 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployees(Employee* list,int len, int index, int* id)
{
	int retorno = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
	{
		if(	!utn_getNombre(bufferEmployee.name,NAME_LEN,"\n¿Nombre?: ","\nError, ingrese un nombre válido.\n",2) &&
			!utn_getApellido(bufferEmployee.lastName,LASTNAME_LEN,"\n¿Apellido?: ","\nError, ingrese un apellido válido.\n",2) &&
			!utn_getNumeroFlotante(&bufferEmployee.salary,"\n¿Salario? ","\nError, ingrese un salario válido.\n",0,300000,0) &&
			!utn_getNumero(&bufferEmployee.sector,"\n¿Sector?: ","\nError, ingrese un sector válido.\n",0,200,1) )
		{
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;
			list[index] = bufferEmployee;
			retorno = 0;
			(*id)++;
		}
	}
	return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
  * \param list Employee*
  * \param len int
  * \param id int
  * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
  */
int findEmployeeById(Employee* list, int len,int id)
{
	int i;
	int retorno = -1;
	if(list != NULL && len > 0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Modify data of an employee in an array position
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modifyEmployee(Employee* list,int len, int index)
{
	int respuesta = -1;
	int i;
	int menuOption;
	Employee bufferEmployee;


	if(list != NULL && len > 0 && index >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == index)
			{

				do
				{
					if(!utn_getNumero(&menuOption,"¿Qué dato desea modificar?\n[1]NOMBRE\n[2]APELLIDO\n[3]SALARIO\n[4]SECTOR\n[5]NINGUNO","Error, ingrese una opción válida\n",1,5,0))
					{
						switch(menuOption)      //Hice un switch para que el usuario elija el campo que quiere modificar.
						{
						case 1:
							if(!utn_getNombre(bufferEmployee.name,NAME_LEN,"\n¿Nombre?\n","\nError, ingrese un nombre válido\n",0))
							{
								respuesta = 0;
								bufferEmployee.id = list[index].id;
								bufferEmployee.isEmpty = 0;
								list[index] = bufferEmployee;
								printf("\nEl nombre del empleado ha sido modificado con éxito.\n\n");
							}
							break;
						case 2:
							if(!utn_getApellido(bufferEmployee.lastName,LASTNAME_LEN,"\n¿Apellido?\n","\nError, ingrese un apellido válido\n",0))
							{
								respuesta = 0;
								bufferEmployee.id = list[index].id;
								bufferEmployee.isEmpty = 0;
								list[index] = bufferEmployee;
								printf("\nEl apellido del empleado ha sido modificado con éxito.\n\n");
							}
							break;
						case 3:
							if(!utn_getNumeroFlotante(&bufferEmployee.salary,"\n¿Salario?\n","\nError, ingrese un salario válido\n",0,300000,0))
							{
								respuesta = 0;
								bufferEmployee.id = list[index].id;
								bufferEmployee.isEmpty = 0;
								list[index] = bufferEmployee;
								printf("\nEl salario del empleado ha sido modificado con éxito.\n\n");
							}
							break;
						case 4:
							if(!utn_getNumero(&bufferEmployee.sector,"\n¿Sector?\n","\nError, ingrese un sector válido\n",0,200,1))
							{
								respuesta = 0;
								bufferEmployee.id = list[index].id;
								bufferEmployee.isEmpty = 0;
								list[index] = bufferEmployee;
								printf("\nEl sector del empleado ha sido modificado con éxito.\n\n");
							}
							break;
						}
					}
				}while(menuOption != 5);
			}
		}
	}
	return respuesta;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
  * \param list Employee*
  * \param len int
  * \param id int
  * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
  */
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				list[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
  * \param list Employee*
  * \param len int
  * \param order int  [1] indicate UP - [0] indicate DOWN
  * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
  */
int sortEmployees(Employee* list, int len, int order)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Employee buffer;
	int auxiliarCmp;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
				if( (auxiliarCmp > 0 && order == 1) ||
					(auxiliarCmp == 0 && list[i].sector > list[i+1].sector && order == 1) ) //Ordena los apellidos de la A a la Z
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1]=buffer;
				}
				else if( (auxiliarCmp < 0 && order == 0) ||
				(auxiliarCmp == 0 && list[i].sector < list[i+1].sector && order == 0) ) //Ordena los apellidos de la Z a la A
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);
	}
	return respuesta;
}

/** \brief prints the total and average salary
  * \param list Employee*
  * \param len int
  * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
  */
int imprimeTotalSalariosYSuPromedio(Employee* list,int len)
{
    int respuesta = -1;
    int i;
    int contador = 0;
    float sumaSalarios = 0;
    float acumuladorSalarios = 0;
    float promedio;
    int contadorMaxPromedios = 0;
    if(list != NULL && len > 0)
    {
    	respuesta = 0;
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 0)
            {
            	sumaSalarios = list[i].salary;
            	acumuladorSalarios += sumaSalarios;
                contador++;
            }
        }
        promedio = acumuladorSalarios / contador;
    }
    printf("\nLa suma total de los salarios es: [%.2f] y el promedio: [%.2f]",acumuladorSalarios,promedio);

    for(i=0;i<len;i++)
    {
    	if(list[i].isEmpty == 0 && list[i].salary > promedio)
    	{
    		contadorMaxPromedios++;
    	}
    }
    printf("\nLos empleados que superan la cantidad promedio de salarios son: %d",contadorMaxPromedios);
    return respuesta;
}


/** \brief print the content of employees array
  * \param list Employee*
  * \param length int
  * \return int
 */
int printEmployees(Employee* list, int length)
{
	int i;
	if(list != NULL && length > 0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("ID empleado: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
	return 0;
}



