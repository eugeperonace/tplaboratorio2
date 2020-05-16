/*
 * ArrayEmployees.h
 *
 *  Created on: 13 may. 2020
 *      Author: Eugenia
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 51
#define LASTNAME_LEN 51

struct
{
	int id;
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

int initEmployees(Employee* list, int len);
int getEmptyIndex(Employee* list, int len);
int addEmployeesForzada(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice);
int addEmployees(Employee* array,int limite, int indice, int* id);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int modifyEmployee(Employee* array,int len, int index);
int imprimeTotalSalariosYSuPromedio(Employee* list,int len);

#endif /* ARRAYEMPLOYEES_H_ */
